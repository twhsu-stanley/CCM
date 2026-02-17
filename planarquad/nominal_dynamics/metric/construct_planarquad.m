plant.g = 9.81;     % (m/s^2) gravity
plant.l = 0.25;     % (m) half-width of quad rotor
plant.m = 0.486;    % (m) mass of the quad rotor
plant.J = 0.00383;  % (kgm^2), moment of inertia

n = 6;              % #states
nu = 2;              % #inputs 

x = sdpvar(n,1); 
x_store = x;
% approximating sin/cos with Chebshev polynomials (for applying SOS programming)
sinx = @(x) 0.9101*(x./(pi/3)) - 0.04466*(4*(x./(pi/3)).^3 - 3*(x./(pi/3))); 
cosx = @(x) 0.7441 -0.2499*(2*(x./(pi/3)).^2 -1);                            
sin_phi = sinx(x(3)); 
cos_phi = cosx(x(3));

%% System dynamics
f = [x(4)*cos_phi - x(5)*sin_phi;       %px
    x(4)*sin_phi + x(5)*cos_phi;        %pz
    x(6);                           %phi
    x(6)*x(5)-plant.g*sin_phi;        %vx
    -x(6)*x(4)-plant.g*cos_phi;       %vz
    0];                             %phi_dot

% f written as a function handle: can also work when x has multiple columns
f_fcn = @(x) [x(4,:).*cos(x(3,:)) - x(5,:).*sin(x(3,:));    %px
            x(4,:).*sin(x(3,:)) + x(5,:).*cos(x(3,:));      %pz
            x(6,:);                                         %phi
            x(6,:).*x(5,:)-plant.g*sin(x(3,:));             %vx
            -x(6,:).*x(4,:)-plant.g*cos(x(3,:));            %vz
            zeros(1,size(x,2))];                 
f_phi_fcn = @(x) x(6);
f_vx_fcn = @(x) x(6)*x(5)-plant.g*sin(x(3));

g = [zeros(4,2); 1/plant.m 1/plant.m; plant.l/plant.J -plant.l/plant.J]; 
g_perp = [eye(4); zeros(2,4)];

df_dx = jacobian(f,x);
A = df_dx;

%% Store data
x = x_store;

plant.n = n; 
plant.nu = nu;

plant.sinx = sinx;
plant.cosx = cosx;
plant.f_fcn = f_fcn;
plant.df_dx = df_dx;
plant.A = A;
plant.g = g;
plant.g_perp = g_perp;
plant.g_fcn = @(x) g;
plant.dynamics = @(x,u) f_fcn(x) + g * u;
