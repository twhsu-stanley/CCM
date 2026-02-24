clear
clc

%% add paths
addpath(genpath("../../../../../YALMIP/"));
addpath("C:\Program Files\Mosek\11.0\toolbox\r2019b");
addpath("../../../../ccm_search/metric_search_offline");
addpath("../../../../ccm_search/control_law_online");

yalmip('clear');

%% General settings
save_rsts = 1; % whether to save the results to a file 

%% Load plant
construct_uncertain_planarquad;  

%% Settings for searching CCM
controller.type = "CCM";
lambda = 0.8; % 1.2
controller.lambda = lambda;
controller.W_lower_bound = 1e-2; % lower bound for the dual metric W
Wstates_index = [3 4]; % indices of states on which the CCM depends

% NOTE: In this system, g(x) is constant and only acts on states #5 and #6.
% By choosing Wstates_index = [3 4], columns of g(x) automatically forms a Killing field
% for W (the 1st strong CCM condition)
% TODO: Currently, the ccm function does not enforce this 1st strong CCM condition
% This must be fixed!!!!!!!!!

% State constraints imposed when searching CCM
consider_state_set = 1; % whether to consider a compact set for the states when formulating the constraints

% limits for states
p_lim = pi/3;
pd_lim = pi/3;
vx_lim = 1.0;
vz_lim = 1.0;
state_set.p_lim = p_lim;
state_set.pd_lim = pd_lim;
state_set.vx_lim = vx_lim;
state_set.vz_lim = vz_lim;
state_set.box_lim = [p_lim^2-x(3)^2; vx_lim^2-x(4)^2; pd_lim^2-x(6)^2; vz_lim^2-x(5)^2]; % W_states to the front

% limits for uncertainty parameters
a1_lim = 0.5;
a2_lim = 0.25;
a3_lim = 0.5;
a4_lim = 0.25;
state_set.a1_lim = a1_lim;
state_set.a2_lim = a2_lim;
state_set.a3_lim = a3_lim;
state_set.a4_lim = a4_lim;
if na == 1
    state_set.box_lim = [state_set.box_lim * 0.1; a1_lim^2-a(1)^2] * 0.001;
elseif na == 2
    state_set.box_lim = [state_set.box_lim * 0.1; a1_lim^2-a(1)^2; a2_lim^2-a(2)^2] * 0.001;
elseif na == 4
    state_set.box_lim = [state_set.box_lim * 0.001; a1_lim^2-a(1)^2; a2_lim^2-a(2)^2; a3_lim^2-a(3)^2; a4_lim^2-a(4)^2] * 0.01;
end
state_set.num_consts_4_W_states = 2; % # of constraints in box_lim that involve states on which the metric W depends
state_set.other_lim_states = [x(6); x(5)]; 
state_set.lagrange_deg_W = 2;   % degree of Lagrangian for enforcing the bounds of W
state_set.lagrange_deg_ccm = 2; % degree of Lagrangian for enforcing the 2nd strong ccm condition

% NOTE: state_set.box_lim must be defined as [limits for W_states; limits for other states; limits for a's]

%% Parameterization of W(x,a)
if na == 1
    W_states = [x(Wstates_index); a]; % extend W_states to incorporate a
    v_W = monolist(W_states, 4);
elseif na == 2
    W_states = [x(Wstates_index); a]; % extend W_states to incorporate a
    v_W = monolist(W_states, 4); % monomials of W_states up to some degree
elseif na == 4
    W_states = [x(Wstates_index); a(1:3)]; % extend W_states to incorporate a
    v_W = monolist(W_states, 3); % monomials of W_states up to some degree
    % TEST 1
    %v_W = [v_W; kron(monolist(x(Wstates_index), 4, 4), monolist(a, 1))];
    % TEST 2
    %v_W = kron(monolist(x(Wstates_index), 3), monolist(a(1:3), 2));
end
n_monos_W = length(v_W);
dv_W_dx = jacobian(v_W, x(Wstates_index)); % take derivatives w.r.t. x(Wstates_index)

dv_W_da1 = jacobian(v_W, a(1)); % take derivatives w.r.t. a
if na >= 2
    dv_W_da2 = jacobian(v_W, a(2));
end
if na >= 3
    dv_W_da3 = jacobian(v_W, a(3));
end
if na >= 4
    dv_W_da4 = jacobian(v_W, a(4));
end

W_coef = sdpvar(n,n,n_monos_W); % creates symbolic decision variables using YALMIP   
W = zeros(n);
for i = 1:n_monos_W
    W = W + W_coef(:,:,i) * v_W(i);
end

dv_W_dt = dv_W_dx * (f(Wstates_index) + Y(Wstates_index,:) * a); % TODO: check correctness
% NOTE: dv_W_da * da/dt = dv_W_da * 0 = 0 because a is constant

dW_dt = zeros(n);
for i = 1:n_monos_W
    dW_dt = dW_dt + W_coef(:,:,i) * dv_W_dt(i);
end

state_set.consider_state_set = consider_state_set;
state_set.W_states = W_states;
state_set.W_states_index = Wstates_index;

%% Search for CCM
% YALMIP (SOS) and Mosek are used to solve the SOS problem
%controller.lambda = lambda;
paras_W = W_coef(:);

[cond_num_W, w_upper, w_lower, W_bar, max_res] = ccm(plant, controller, W, dW_dt, paras_W, lambda, state_set);

controller.w_upper = w_upper;
controller.w_lower = w_lower;
controller.W_bar = W_bar;

%% Extract functions W_fcn & dW_fcn
W_coef = value(W_coef);  
W_coef(abs(W_coef) <= 1e-10) = 0;

x = x_store; % must ensure that v_W and s contain "x" instead of "x_store"
W_fcn = zeros(n);
for i = 1:n_monos_W
    W_fcn = W_fcn + W_coef(:,:,i) * v_W(i);
end
W_fcn = clean(W_fcn, 1e-10);
dv_W_dx = clean(dv_W_dx, 1e-10);

s = sdisplay(W_fcn);
s2 = sdisplay(dv_W_dx);
s3 = sdisplay(dv_W_da1);
if na >= 2
    s4 = sdisplay(dv_W_da2);
end
if na >= 3
    s5 = sdisplay(dv_W_da3);
end
if na >= 4
    s6 = sdisplay(dv_W_da4);
end

syms x [n 1]
syms a [na 1]
syms W_fcn [n n]
for i = 1:n
    for j = 1:n
        W_fcn(i,j) = eval(s{i,j});
    end
end
matlabFunction(W_fcn,'File',['na',num2str(na),'/W_fcn'],'Vars',{x,a});
W_fcn = matlabFunction(W_fcn,'Vars',{x,a});

% Derivatives of W w.r.t. states
[n1,n2] = size(dv_W_dx);
syms dv_W_dx_sym [n1 n2]
for i = 1:n1
    for j = 1:n2
        dv_W_dx_sym(i,j) = eval(s2{i,j});
    end
end
dW_dphi = zeros(n);
dW_dvx = zeros(n);
for i = 1:n_monos_W
    dW_dphi = dW_dphi + W_coef(:,:,i) * dv_W_dx_sym(i,1); 
    dW_dvx = dW_dvx + W_coef(:,:,i) * dv_W_dx_sym(i,2);
end
matlabFunction(dW_dphi,'File',['na',num2str(na),'/dW_dphi'],'Vars',{x,a});
matlabFunction(dW_dvx,'File',['na',num2str(na),'/dW_dvx'],'Vars',{x,a});
dW_dphi = matlabFunction(dW_dphi,'Vars',{x,a});
dW_dvx = matlabFunction(dW_dvx,'Vars',{x,a});
%
dW_dxi_fcn = @(i,x,a) (i==3) * dW_dphi(x,a) + (i==4) * dW_dvx(x,a);
dW_dxi_fcn_str = func2str(dW_dxi_fcn);
dW_dxi_fcn_str = strcat('function dW_dxi = dW_dxi_fcn(i,x,a)\n', 'dW_dxi = ', dW_dxi_fcn_str(9:end), ';');
fid = fopen(['na',num2str(na),'/dW_dxi_fcn.m'],'w');
fprintf(fid, dW_dxi_fcn_str);
fclose(fid);

% Derivatives of W w.r.t. uncertainty parameter: a
[n1,n2] = size(dv_W_da1);
syms dv_W_da1_sym [n1 n2]
for i = 1:n1
    for j = 1:n2
        dv_W_da1_sym(i,j) = eval(s3{i,j});
    end
end
dW_da1 = zeros(n);
for i = 1:n_monos_W
    dW_da1 = dW_da1 + W_coef(:,:,i) * dv_W_da1_sym(i,1); 
end
matlabFunction(dW_da1,'File',['na',num2str(na),'/dW_da1'],'Vars',{x,a});
dW_da1 = matlabFunction(dW_da1,'Vars',{x,a});

if na >= 2
    % for a2
    [n1,n2] = size(dv_W_da2);
    syms dv_W_da2_sym [n1 n2]
    for i = 1:n1
        for j = 1:n2
            dv_W_da2_sym(i,j) = eval(s4{i,j});
        end
    end
    dW_da2 = zeros(n);
    for i = 1:n_monos_W
        dW_da2 = dW_da2 + W_coef(:,:,i) * dv_W_da2_sym(i,1); 
    end
    matlabFunction(dW_da2,'File',['na',num2str(na),'/dW_da2'],'Vars',{x,a});
    dW_da2 = matlabFunction(dW_da2,'Vars',{x,a});
end
if na >= 3
    % for a3
    [n1,n2] = size(dv_W_da3);
    syms dv_W_da3_sym [n1 n2]
    for i = 1:n1
        for j = 1:n2
            dv_W_da3_sym(i,j) = eval(s5{i,j});
        end
    end
    dW_da3 = zeros(n);
    for i = 1:n_monos_W
        dW_da3 = dW_da3 + W_coef(:,:,i) * dv_W_da3_sym(i,1); 
    end
    matlabFunction(dW_da3,'File',['na',num2str(na),'/dW_da3'],'Vars',{x,a});
    dW_da3 = matlabFunction(dW_da3,'Vars',{x,a});
end
if na >= 4
    % for a4
    [n1,n2] = size(dv_W_da4);
    syms dv_W_da4_sym [n1 n2]
    for i = 1:n1
        for j = 1:n2
            dv_W_da4_sym(i,j) = eval(s6{i,j});
        end
    end
    dW_da4 = zeros(n);
    for i = 1:n_monos_W
        dW_da4 = dW_da4 + W_coef(:,:,i) * dv_W_da4_sym(i,1); 
    end
    matlabFunction(dW_da4,'File',['na',num2str(na),'/dW_da4'],'Vars',{x,a});
    dW_da4 = matlabFunction(dW_da4,'Vars',{x,a});
end

if na == 1
    dW_dai_fcn = @(i,x,a) (i==1) * dW_da1(x,a);
elseif na == 2
    dW_dai_fcn = @(i,x,a) (i==1) * dW_da1(x,a) + (i==2) * dW_da2(x,a);
elseif na == 4
    dW_dai_fcn = @(i,x,a) (i==1) * dW_da1(x,a) + (i==2) * dW_da2(x,a) + (i==3) * dW_da3(x,a) + (i==4) * dW_da4(x,a);
end
dW_dai_fcn_str = func2str(dW_dai_fcn);
dW_dai_fcn_str = strcat('function dW_dai = dW_dai_fcn(i,x,a)\n', 'dW_dai = ', dW_dai_fcn_str(9:end), ';');
fid = fopen(['na',num2str(na),'/dW_dai_fcn.m'],'w');
fprintf(fid, dW_dai_fcn_str);
fclose(fid);

controller.W_fcn = W_fcn;
controller.dW_dxi_fcn = dW_dxi_fcn;
controller.dW_dai_fcn = dW_dai_fcn;

%% Check CCM conditions (and compute the tubes for planning)
% TODO: remove some fields that cannot be properly saved
if isfield(plant,'df_dx')
    plant = rmfield(plant,{'df_dx'});
end

if isfield(plant,'A')
    plant = rmfield(plant,{'A'});
end

if isfield(state_set,'box_lim')
    state_set = rmfield(state_set,{'box_lim','other_lim_states','W_states'});
end
plant.state_set = state_set;

%% Save data
if save_rsts == 1
    file_name = ['na',num2str(na),'/uccm_' num2str(controller.lambda) '_na' num2str(na) '.mat'];
    save(file_name,'plant','controller','state_set');
end