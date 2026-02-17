plant.grav = 9.81;     % (m/s^2) gravity
plant.l = 0.25;     % (m) half-width of quad rotor
plant.m = 0.486;    % (m) mass of the quad rotor
plant.J = 0.00383;  % (kgm^2), moment of inertia

n = 6;  % # of states
nu = 2; % # of inputs 
na = 1; % # of parameters % na = 3 for a = [wind_x/m, wind_z/m, moment/J], or na = 1 for a = [wind_x/m]

x = sdpvar(n,1); % state x = [px, pz, phi, vx, vz, phi_dot]
x_store = x;
a = sdpvar(na,1); % constant uncertainty parameters a = [wind_x/m, wind_z/m, moment/J], or just a = [wind_x/m]

% approximating sin/cos with Chebshev polynomials (for applying SOS programming)
sinx = @(x) 0.9101*(x./(pi/3)) - 0.04466*(4*(x./(pi/3)).^3 - 3*(x./(pi/3))); 
cosx = @(x) 0.7441 -0.2499*(2*(x./(pi/3)).^2 -1);                            
sin_phi = sinx(x(3)); 
cos_phi = cosx(x(3));

%% System dynamics: x_dot = f(x) + g(x)u + Y(x)a
f = [x(4) * cos_phi - x(5) * sin_phi;     %px
     x(4) * sin_phi + x(5) * cos_phi;     %pz
     x(6);                                %phi
     x(6) * x(5) - plant.grav * sin_phi;  %vx
     -x(6) * x(4) - plant.grav * cos_phi; %vz
     0];                                  %phi_dot

df_dx = jacobian(f,x);

% f written as a function handle: can also work when x has multiple columns
f_fcn = @(x) [x(4,:) .* cos(x(3,:)) - x(5,:).*sin(x(3,:)); 
              x(4,:) .* sin(x(3,:)) + x(5,:).*cos(x(3,:));
              x(6,:);
              x(6,:) .* x(5,:) - plant.grav * sin(x(3,:));
              -x(6,:) .* x(4,:) - plant.grav * cos(x(3,:));
              zeros(1,size(x,2))];
f_phi_fcn = @(x) x(6);
f_vx_fcn = @(x) x(6) * x(5) - plant.grav * sin(x(3));

g = [zeros(4,2); 1/plant.m, 1/plant.m; plant.l/plant.J, -plant.l/plant.J]; 
g_perp = [eye(4); zeros(2,4)];

% Unmatched uncertanity: Y(x)a
% a = [wind_x/m, wind_z/m, moment/J]: constant
%{
Y = [0, 0, 0;
     0, 0, 0;
     0, 0, 0;
     cos_phi, sin_phi, 0;
     -sin_phi, cos_phi, 0;
     0, 0, 1];
%}
% a = [wind_x/m]: constant
Y = [0;
     0;
     0;
     cos_phi;
     -sin_phi;
     0];

dY_dx = jacobian(Y,x);

A = df_dx;
for i = 1:size(Y,2)
    A = A + jacobian(Y(1:size(Y,1),i),x) * a(i); % TODO: check correctness
end

%{
Y_fcn = @(x) [0, 0, 0;
              0, 0, 0;
              0, 0, 0;
              cos(x(3,:)), sin(x(3,:)), 0;
              -sin(x(3,:)), cos(x(3,:)), 0;
              0, 0, 1];
%}

Y_fcn = @(x) [0;
              0;
              0;
              cos(x(3,:));
              -sin(x(3,:));
              0];
Y_phi_fcn = @(x) 0;
Y_vx_fcn = @(x) cos(x(3));

%% Store data
x = x_store;

plant.n = n; 
plant.nu = nu; 
plant.na = na;

plant.sinx = sinx;
plant.cosx = cosx;
plant.f_fcn = f_fcn;
plant.df_dx = df_dx;
plant.A = A;
plant.g = g;
plant.g_perp = g_perp;
plant.g_fcn = @(x) g;
plant.Y_fcn = Y_fcn;
plant.dynamics = @(x,u,a) f_fcn(x) + g * u + Y_fcn(x) * a;
