plant.grav = 9.81;     % (m/s^2) gravity
plant.l = 0.25;     % (m) half-width of quad rotor
plant.m = 0.486;    % (m) mass of the quad rotor
plant.J = 0.00383;  % (kgm^2), moment of inertia

n = 6;  % # of states
nu = 2; % # of inputs
na = 1; % # of parameters % na = 1 or 3

x = sdpvar(n,1); % state x = [px, pz, phi, vx, vz, phi_dot]
x_store = x;
a = sdpvar(na,1); % constant uncertainty parameters a = [wind_x/m, wind_z/m, moment/J], or just a = [wind_x/m]
a_store = a;

% approximating sin/cos with Chebshev polynomials (for applying SOS programming)
sinx = @(x) 0.9101*(x./(pi/3)) - 0.04466*(4*(x./(pi/3)).^3 - 3*(x./(pi/3))); 
cosx = @(x) 0.7441 -0.2499*(2*(x./(pi/3)).^2 -1);                            
sin_phi = sinx(x(3)); 
cos_phi = cosx(x(3));

%% Nominal dynamics: f(x) + g(x)u
f = [x(4) * cos_phi - x(5) * sin_phi;     %px
     x(4) * sin_phi + x(5) * cos_phi;     %pz
     x(6);                                %phi
     x(6) * x(5) - plant.grav * sin_phi;  %vx
     -x(6) * x(4) - plant.grav * cos_phi; %vz
     0];                                  %phi_dot

df_dx = jacobian(f,x);

% can also work when x has multiple columns (needed for motion planning)
f_fcn = @(x) [x(4,:) .* cos(x(3,:)) - x(5,:).*sin(x(3,:)); 
              x(4,:) .* sin(x(3,:)) + x(5,:).*cos(x(3,:));
              x(6,:);
              x(6,:) .* x(5,:) - plant.grav * sin(x(3,:));
              -x(6,:) .* x(4,:) - plant.grav * cos(x(3,:));
              zeros(1,size(x,2))];
f_phi_fcn = @(x) x(6,:);
f_vx_fcn = @(x) x(6,:) .* x(5,:) - plant.grav * sin(x(3,:));

g = [zeros(4,2); 1/plant.m, 1/plant.m; plant.l/plant.J, -plant.l/plant.J]; 
g_perp = [eye(4); zeros(2,4)];

%% Parametric uncertainty: Y(x)a

% Column vectors of Y(x)
% for x that has multiple columns (needed for motion planning)
Y1_fcn = @(x) [x(4,:) .* x(3,:).^4;
               x(5,:) .* x(3,:).^4;
               zeros(1,size(x,2));
               zeros(1,size(x,2));
               zeros(1,size(x,2));
               zeros(1,size(x,2))];

Y2_fcn = @(x) [x(5,:) .* x(3,:).^5;
               x(4,:) .* x(3,:).^5;
               zeros(1,size(x,2));
               zeros(1,size(x,2));
               zeros(1,size(x,2));
               zeros(1,size(x,2))];

Y3_fcn = @(x) [zeros(1,size(x,2));
               zeros(1,size(x,2));
               zeros(1,size(x,2));
               ones(1,size(x,2));
               zeros(1,size(x,2));
               zeros(1,size(x,2))];

if na == 1
    % 1-dim uncertainty
    Y = [0; 0; 0; 1; 0; 0];
    Y_fcn = @(x) [0; 0; 0; 1; 0; 0];

    dynamics_fcn = @(x,u,a) f_fcn(x) + g * u + Y3_fcn(x) * a(1);

elseif na == 3
    % 3-dim uncertainty
    Y = [x(4) * x(3)^4, x(5) * x(3)^5, 0;
         x(5) * x(3)^4, x(4) * x(3)^5, 0;
         0, 0, x(6);
         0, 0, 0;
         0, 0, 0;
         0, 0, 0];
    Y_fcn = @(x) [x(4) * x(3)^4, x(5) * x(3)^5, 0;
                  x(5) * x(3)^4, x(4) * x(3)^5, 0;
                  0, 0, x(6);
                  0, 0, 0;
                  0, 0, 0;
                  0, 0, 0];

    dynamics_fcn = @(x,u,a) f_fcn(x) + g * u + Y1_fcn(x) * a(1) + Y2_fcn(x) * a(2) + Y3_fcn(x) * a(3);
end

%% A function
A = df_dx;
for i = 1:size(Y,2)
    A = A + jacobian(Y(1:size(Y,1),i),x) * a(i); % TODO: check correctness
end

% below is for motion planning only
s = sdisplay(A);
syms x [n 1]
syms a [na 1]
syms A_fcn [n n]
for i = 1:n
    for j = 1:n
        A_fcn(i,j) = eval(s{i,j});
    end
end
A_fcn = matlabFunction(A_fcn,'Vars',{x,a});

%% Store data
x = x_store;
a = a_store;

plant.n = n; 
plant.nu = nu; 
plant.na = na;

plant.sinx = sinx;
plant.cosx = cosx;
plant.f_fcn = f_fcn;
plant.df_dx = df_dx;
plant.A = A;
plant.A_fcn = A_fcn;
plant.g = g;
plant.g_perp = g_perp;
plant.g_fcn = @(x) g;
plant.Y_fcn = Y_fcn;
plant.dynamics = dynamics_fcn;
