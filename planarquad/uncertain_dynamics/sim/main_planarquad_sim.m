clc;
clear;
close all
addpath trajGen_pvtol trajGen_pvtol/nominal_trajs 
addpath('../metric');
addpath('../utilities');

%% Simulation settings
file_controller = '../metric/ccm_0.8.mat'; % CCM
load(file_controller);

controller.use_cp = true;%false; %  whether to implement the constraint tightening in the CRCLF-QP

sim_config.include_obs = 0;         % whether to include the obstacles
sim_config.include_dist = 0;        % include the disturbance  
sim_config.replan_nom_traj = 0;     % whether to replan a trajectory **1 doesn't work
sim_config.dt_sim = 1/100;
use_generated_code = 0;             % whether to use the generated codes for simulations: using generated codes can accelerate by at least one fold

n = 6;
nu = 2;
x0 = zeros(6,1);                   % initial state

% The following are only needed if replan_nom_traj == 1, which doesn't work now
% sim_config.include_tube = 0;       % whether to tighten the state bounds in planning a nominal trajectory
% sim_config.tight_input_bnd = 0;    % whether to tighten the input bounds in planning a nominal trajectory
% sim_config.duration = 2;           % sim duration
% xF = [5 5 0 0 0 0]';              % final state
% umax = 3*plant.m*plant.g;         % control limit
% u_bnd = [0 0; umax umax]';
% x_bnd = [-inf -inf -state_set.p_lim -state_set.vx_lim, -state_set.vz_lim, -state_set.pd_lim;
%           inf  inf  state_set.p_lim  state_set.vx_lim   state_set.vz_lim   state_set.pd_lim]';

% Disturbance settings 
dist_config.include_dist = sim_config.include_dist;
dist_config.gen_dist = @(t) [-0.5 + 0.8*sin(2*pi/1*t);
                             0.5 + 0.8*cos(2*pi/2*t + 0.03);
                             0.5 + 0.4*sin(2*pi/3*t + 0.01);
                             0.5 + 0.2*cos(2*pi/1*t + 0.04);
                             0.7 + 0.1*sin(2*pi/4*t + 0.01);
                             0.2 + 0.5*cos(2*pi/5*t + 0.05);];

w_norm_max = 0;
for t = 1:0.01:10
    w_norm = norm(dist_config.gen_dist(t));
    if w_norm > w_norm_max
        w_norm_max = w_norm;
    end
end
w_max = w_norm_max;
controller.cp_quantile = w_max;

%% Plan or load a nominal trajecotory 
addpath('C:\ACXIS Code\OptimTraj');
gen_nominal_traj;
controller.x_nom_fcn = x_nom_fcn;
controller.u_nom_fcn = u_nom_fcn;
%controller.w_nom = 0;  % nominal value for disturbances

%% Formulate the NLP problem for geodesic computation
controller.use_generated_code = use_generated_code;
lambda = controller.lambda;
%  problem setting for geodesic computation
D = 2;      % degree of the polynomial
N = D + 6;  % stopping index for the CGL (Chebyshev-Gauss-Lobatto) nodes: #nodes N+1

% --------------- re-generate the code is necessary after change of ------
% controller or geodesic optimization settings: remember to re-generate the
% m-file functions, e.g., dW_dphi, dW_dvx, etc., first.------------------  
if controller.use_generated_code
    load geodesic_setting_for_codegen.mat
    if D ~= geodesic_setting_for_codegen.D ||  N ~= geodesic_setting_for_codegen.N
       error('The geodesic setting here does not match the one used for code generation.'); 
    end
    answer = questdlg('Are the generated codes for this particular scenario?','Question for using C-code in simulation','Yes','No','No');
    switch answer 
        case 'Yes'            
        case 'No'
            error('You cannot continue without including the generated codes for this scenario!');
    end
end
controller.geodesic = set_opt_prob_for_geodesic_computation(n,D,N,controller);
%controller.geodesic.nlprob = []; % setting geodesic.nlprob to [] indicates that the geodesic will be approximated by a straight line

%% Simulation
times = 0:sim_config.dt_sim:sim_config.duration;
T_steps = length(times);

xTraj = zeros(plant.n, T_steps);
uTraj = zeros(plant.nu, T_steps);
energyTraj = zeros(1, T_steps);
slackTraj = zeros(1, T_steps);
gmbTraj = zeros(1, T_steps);
xnomTraj = zeros(plant.n, T_steps);
unomTraj = zeros(plant.nu, T_steps);

x0 = x0 + [-0;0;0;0;0;0];

% Initialization
t = times(1);
xd0 = controller.x_nom_fcn(t);
ud0 = controller.u_nom_fcn(t);
[uc0, Erem0, slack0, gmb0] = ccm_law(t, xd0, ud0, x0, plant, controller);
xa = x0;

options = odeset('RelTol',1e-2);

for i = 1:T_steps
    t = times(i);
    
    xTraj(:,i) = xa(1:plant.n);

    % Log the nominal state and input
    xd = controller.x_nom_fcn(t);
    ud = controller.u_nom_fcn(t);
    xnomTraj(:,i) = xd;
    unomTraj(:,i) = ud;
    
    [uc, Erem, slack, gmb] = ccm_law(t, xd, ud, xa, plant, controller);
    uTraj(:,i) = uc;
    energyTraj(:,i) = Erem;
    slackTraj(:,i) = slack;
    gmbTraj(:,i) = gmb;
    % uTraj(:,i) = xa((plant.n+1):(plant.n+plant.nu));
    % energyTraj(:,i) = xa(plant.n+plant.nu+1);
    % slackTraj(:,i) = xa(plant.n+plant.nu+2);
    % gmbTraj(:,i) = xa(plant.n+plant.nu+3);
    
    % Propagate state with zero-hold for control inputs
    if i < T_steps
        %[t_plus, x_plus] = ode45(@(t,x) planarquad_dyn(t, x, uc, wt, plant), [times(i) times(i+1)], x, options);
        [t_plus, xa_plus] = ode23s(@(t,xa) planarquad_dyn(t,xa, plant, controller, dist_config), [times(i) times(i+1)], xa, options);
        xa = xa_plus(end,:)';
    end

end

%% Plot the result
plot_trajs;

%% Save data
if controller.use_cp
    file_name = 'sim_crccm';
else
    file_name = 'sim_ccm';
end
file_name = [file_name '_lambda_' num2str(controller.lambda,2)];
if dist_config.include_dist == 1
    file_name = [file_name '_wmax_' num2str(w_max)];
end

if sim_config.include_obs == 1
    file_name  = [file_name '_w_obs.mat'];
else
    file_name  = [file_name '.mat'];
end
save(file_name,'times','xTraj','uTraj','xnomTraj','unomTraj','energyTraj','slackTraj','dist_config','sim_config','plant','controller');

%% Planar quad dynamics
function dxadt = planarquad_dyn(t, xa, plant, controller, dist_config)
% xa: augmented state = [state, control inputs, Reimaniann energy, QP slack]

n = plant.n;
nu = plant.nu;
x = xa(1:n);

xd = controller.x_nom_fcn(t);
ud = controller.u_nom_fcn(t);

[uc, Erem, slack, gmb] = ccm_law(t, xd, ud, x, plant, controller);

if dist_config.include_dist == 1
        wt = dist_config.gen_dist(t);
    else
        wt = zeros(n,1);
end

dxdt = plant.f_fcn(x) + plant.B_fcn(x) * uc + plant.Bw_fcn(x) * wt;
dxadt = dxdt;

end