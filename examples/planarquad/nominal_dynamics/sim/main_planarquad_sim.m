clc;
clear;
close all
addpath trajGen_pvtol trajGen_pvtol/nominal_trajs 
addpath('../metric');
addpath('../../utilities');

%% Simulation settings
file_controller = '../metric/ccm_0.8.mat'; % CCM
load(file_controller);

sim_config.include_obs = 0;         % whether to include the obstacles
sim_config.include_dist = 0;        % include the disturbance  
sim_config.replan_nom_traj = 0;     % whether to replan a trajectory **1 doesn't work
sim_config.dt_sim = 1/100;

n = 6;
nu = 2;

% The following are only needed if replan_nom_traj == 1, which doesn't work now
% sim_config.include_tube = 0;       % whether to tighten the state bounds in planning a nominal trajectory
% sim_config.tight_input_bnd = 0;    % whether to tighten the input bounds in planning a nominal trajectory
% sim_config.duration = 2;           % sim duration
% xF = [5 5 0 0 0 0]';              % final state
% umax = 3*plant.m*plant.g;         % control limit
% u_bnd = [0 0; umax umax]';
% x_bnd = [-inf -inf -state_set.p_lim -state_set.vx_lim, -state_set.vz_lim, -state_set.pd_lim;
%           inf  inf  state_set.p_lim  state_set.vx_lim   state_set.vz_lim   state_set.pd_lim]';

%% Plan or load a nominal trajecotory 
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

% For testing the unmatched uncertainty %%%%%%%%%%%%%%%%%%%
%{
plant.Y_fcn = @(x) [0;
                    0;
                    0;
                    cos(x(3));
                    -sin(x(3));
                    0];
a = 0.4;
%}
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Initialization
x0 = [0.5;0.5;0;0;0;0];
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
    
    [uc, Erem, slack] = ccm_law(t, xd, ud, x, plant, controller);
    uTraj(:,i) = uc;
    energyTraj(:,i) = Erem;
    slackTraj(:,i) = slack;

    % Propagate state with zero-hold for control inputs
    if i < T_steps
        %[t_plus, x_plus] = ode45(@(t,x) planarquad_dyn(t, x, uc, plant), [times(i) times(i+1)], x, options);
        [t_plus, x_plus] = ode23s(@(t,x) planarquad_dyn(t, x, uc, plant), [times(i) times(i+1)], x, options);
        x = x_plus(end,:)';
    end

end

%% Plot the result
plot_trajs;

%% Planar quad dynamics
function dxdt = planarquad_dyn(t, x, u, plant)

dxdt = plant.f_fcn(x) + plant.g_fcn(x) * u;

end

%function dxdt = planarquad_dyn(t, x, u, a, plant)

%dxdt = plant.f_fcn(x) + plant.g_fcn(x) * u + plant.Y_fcn(x) * a;

%end