clc;
clear;
close all
addpath('../metric');
addpath('../../utilities');
addpath('../../planning');

%% Simulation settings
file_controller = '../metric/na4/uccm_0.8_na4.mat'; % uCCM
load(file_controller);

n = 6;
nu = 2;

sim_config.dt_sim = 1/100;
sim_config.replan_nom_traj = 1;    % whether to replan a trajectory
sim_config.include_obs = 0;        % whether to include the obstacles 
sim_config.include_tube = 0;       % whether to tighten the state bounds in planning a nominal trajectory
sim_config.duration = 6;           % sim duration % will be modified if replan_nom_traj == 1
x0 = [0; 0; 0; 0; 0; 0];
xF = [6; 6; 0; 0; 0; 0];              % final state
umax = 3 * plant.m * plant.grav;      % control limit
u_bnd = [0 0; umax umax]';
x_bnd = [-inf -inf -state_set.p_lim -state_set.vx_lim, -state_set.vz_lim, -state_set.pd_lim;
          inf  inf  state_set.p_lim  state_set.vx_lim   state_set.vz_lim   state_set.pd_lim]';

%% Set uncertainty parameter: a
a = [-0.4; 0.12; 0.3; 0.15];
controller.W_fcn = @(x) controller.W_fcn(x,a);
controller.dW_dxi_fcn = @(i,x) controller.dW_dxi_fcn(i,x,a);
controller.dW_dai_fcn = @(x) controller.dW_dai_fcn(1,x,a); % TODO: should work for higher-dim a

plant.dynamics = @(x,u) plant.dynamics(x,u,a);
plant.A_fcn = @(x) plant.A_fcn(x,a);

%% Plan or load a nominal trajecotory 
% NOTE: the desired trajecotry follows the uncertain dynamics with Y(x)a
addpath('C:\ACXIS Code\OptimTraj');
gen_nominal_traj;
controller.x_nom_fcn = x_nom_fcn;
controller.u_nom_fcn = u_nom_fcn;

%% Formulate the NLP problem for geodesic computation
lambda = controller.lambda;
%  problem setting for geodesic computation
D = 2;      % degree of the polynomial
N = D + 6;  % stopping index for the CGL (Chebyshev-Gauss-Lobatto) nodes: #nodes N+1

controller.geodesic = set_opt_prob_for_geodesic_computation(n,D,N,controller);
%controller.geodesic.nlprob = []; % setting geodesic.nlprob to [] indicates that the geodesic will be approximated by a straight line

%% Simulation
times = 0:sim_config.dt_sim:sim_config.duration;
T_steps = length(times);

xTraj = zeros(plant.n, T_steps);
uTraj = zeros(plant.nu, T_steps);
energyTraj = zeros(1, T_steps);
slackTraj = zeros(1, T_steps);
xnomTraj = zeros(plant.n, T_steps);
unomTraj = zeros(plant.nu, T_steps);

% Initialization
x0 = [-0.1; 0.5; pi/5; 0.0; 0.0; pi/4];
x = x0;

options = odeset('RelTol',1e-2);

for i = 1:T_steps
    t = times(i);
    fprintf('t = %.4f\n', t);
    
    xTraj(:,i) = x;

    % Log the nominal state and input
    xd = controller.x_nom_fcn(t);
    ud = controller.u_nom_fcn(t);
    xnomTraj(:,i) = xd;
    unomTraj(:,i) = ud;
    
    % TODO: account for Y(x)a in ccm_law
    [uc, Erem, slack] = ccm_law(t, xd, ud, x, plant, controller);
    uTraj(:,i) = uc;
    energyTraj(:,i) = Erem;
    slackTraj(:,i) = slack;
    
    % Propagate state with zero-hold for control inputs
    if i < T_steps
        %[t_plus, x_plus] = ode45(@(t,x) planarquad_dyn(t, x, uc, a, plant), [times(i) times(i+1)], x, options);
        [t_plus, x_plus] = ode23s(@(t,x) planarquad_dyn(t, x, uc, a, plant), [times(i) times(i+1)], x, options);
        x = x_plus(end,:)';
    end

end

%% Plot the result
plot_trajs;

%% Planar quad dynamics
function dxdt = planarquad_dyn(t, x, u, a, plant)

dxdt = plant.f_fcn(x) + plant.g_fcn(x) * u + plant.Y_fcn(x) * a;

end