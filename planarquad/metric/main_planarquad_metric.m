clear
clc

%% add paths
addpath(genpath("C:\ACXIS Code\YALMIP\"));
addpath("C:\Program Files\Mosek\11.0\toolbox\r2019b");
addpath("../../ccm_search/metric_search_offline");
addpath("../../ccm_search/control_law_online");

yalmip('clear');

%% General settings
save_rsts = 1; % whether to save the results to a file 

%% Load plant
construct_planarquad;  

%% Settings for searching CCM
controller.type = "CCM";
lambda = 1;
controller.lambda = lambda;
controller.W_lower_bound = 1e-2; % lower bound for the dual metric W
Wstates_index = [3 4];

% if controller.type == "CRCCM"
%     controller.epsilon = 1; % for the completion-of-squares
%     controller.cp_quantile = 1;
%     controller.eta = 2/controller.epsilon^2 / controller.W_lower_bound * controller.cp_quantile^2;
% end

% State constraints imposed when searching CCM
consider_state_set = 1; % whether to consider a compact set for the states when formulating the constraints
p_lim = pi/3;  % phi
pd_lim = pi/3; % phi_dot 
vx_lim = 2;    % vx
vz_lim = 1;    % vz
w_lim = 1;     % w (disturbance)
state_set.box_lim = [p_lim^2-x(3)^2; vx_lim^2-x(4)^2; pd_lim^2-x(6)^2;  vz_lim^2-x(5)^2]*0.001;
state_set.num_consts_4_W_states = 2;        % #constraints from box_lim that involve states on which the metric W depends
state_set.other_lim_states = [x(6);x(5)]; 
state_set.lagrange_deg_W = 4;               % degree of the lafor the bounds of W
state_set.lagrange_deg_ccm = 4;             % for ccm condition
state_set.p_lim = p_lim;
state_set.pd_lim = pd_lim;
state_set.vx_lim = vx_lim;
state_set.vz_lim = vz_lim;
state_set.w_lim = w_lim;

%% Parameterization of W
W_states = x(Wstates_index);
v_W = monolist(W_states,4);         % monomials of W_states up to degree 4
n_monos_W = length(v_W);
dv_W_dx = jacobian(v_W,W_states);

W_coef = sdpvar(n,n,n_monos_W); % creates symbolic decision variables using YALMIP   
W = zeros(n);
for i = 1:n_monos_W
    W = W + W_coef(:,:,i) * v_W(i);
end
if controller.type == "CCM" %|| controller.type == "CRCCM"
    dv_W_dt = dv_W_dx*f(Wstates_index);
% elseif controller.type == "RCCM"
%     % dv_W_dt could depend on w
%     dv_W_dt = dv_W_dx*(f(Wstates_index)+Bw(Wstates_index)*w);
end

dW_dt = zeros(n);
for i = 1:n_monos_W
    dW_dt = dW_dt + W_coef(:,:,i)*dv_W_dt(i);
end

state_set.consider_state_set = consider_state_set;
state_set.W_states = W_states;
state_set.W_states_index = Wstates_index;

%% Search for CCM
% YALMIP (SOS) and Mosek are used to solve the SOS problem
%controller.lambda = lambda;
paras_W = W_coef(:);

if controller.type == "CCM"
    [cond_num_W,w_upper,w_lower,W_bar,max_res] = ccm(plant,controller,W,dW_dt,paras_W,lambda,state_set);
% elseif controller.type == "CRCCM"
%     [cond_num_W,w_upper,w_lower,W_bar,max_res] = crccm(plant,controller,W,dW_dt,paras_W,lambda,state_set);
end
controller.w_upper = w_upper;
controller.w_lower = w_lower;
controller.W_bar = W_bar;

%% Extract functions W_fcn & dW_fcn
W_coef = value(W_coef);  
W_coef(abs(W_coef)<=1e-10) = 0;

x = x_store; % must ensure that v_W and s contain "x" instead of "x_store"
W_fcn = zeros(n);
for i=1:n_monos_W
    W_fcn = W_fcn + W_coef(:,:,i)*v_W(i);
end
W_fcn = clean(W_fcn, 1e-10);
dv_W_dx = clean(dv_W_dx, 1e-10);
s = sdisplay(W_fcn);
s2 = sdisplay(dv_W_dx);
syms x [n 1]
syms W_fcn [n n]
for i=1:n
    for j=1:n
        W_fcn(i,j) = eval(s{i,j});
    end
end
matlabFunction(W_fcn,'File','W_fcn1','Vars',{x});
W_fcn = matlabFunction(W_fcn,'Vars',{x});

[n1,n2]= size(dv_W_dx);
syms dv_W_dx_sym [n1 n2]

for i=1:n1
    for j=1:n2
        dv_W_dx_sym(i,j) = eval(s2{i,j});
    end
end    
dW_dphi = zeros(n);
dW_dvx = zeros(n);
for i=1:n_monos_W
    dW_dphi = dW_dphi + W_coef(:,:,i)*dv_W_dx_sym(i,1); 
    dW_dvx = dW_dvx + W_coef(:,:,i)*dv_W_dx_sym(i,2);
end

matlabFunction(dW_dphi,'File','dW_dphi','Vars',{x});
matlabFunction(dW_dvx,'File','dW_dvx','Vars',{x});
dW_dphi = matlabFunction(dW_dphi,'Vars',{x});
dW_dvx = matlabFunction(dW_dvx,'Vars',{x});

dW_dxi_fcn = @(i,x) (i==3)*dW_dphi(x)+(i==4)*dW_dvx(x);
dW_dxi_fcn_str = func2str(dW_dxi_fcn);
dW_dxi_fcn_str = strcat('function dW_dxi = dW_dxi_fcn1(i,x)\n', 'dW_dxi = ', dW_dxi_fcn_str(7:end), ';');
fid = fopen('dW_dxi_fcn1.m','w');
fprintf(fid,dW_dxi_fcn_str);
fclose(fid);

dW_dt_fcn = @(x) dW_dphi(x)*f_phi_fcn(x) + dW_dvx(x)*f_vx_fcn(x);

controller.W_fcn = W_fcn;
controller.dW_dxi_fcn = dW_dxi_fcn;
controller.dW_dt_fcn = dW_dt_fcn;

%% Check CCM conditions (and compute the tubes for planning)
if isfield(plant,'df_dx')
    plant= rmfield(plant,{'df_dx','Bw','w'});
end
if isfield(controller,'rho')
    controller= rmfield(controller,{'rho','c_rho','v_rho'});
end
if isfield(state_set,'box_lim')
    state_set = rmfield(state_set,{'box_lim','other_lim_states','W_states'});
end
plant.state_set = state_set;

compute_tubes;

%% Save data
if save_rsts == 1
    if controller.type == "CCM"
        file_name = ['ccm_' num2str(controller.lambda) '.mat'];
    % elseif controller.type == "CRCCM"
    %     file_name = ['crccm_' num2str(controller.lambda) '_epsilon_' num2str(controller.epsilon) '.mat'];
    end
    save(file_name,'plant','controller','state_set');
end

%% Generate the c codes for accelerating geodesic computation
% To use the generated codes, copy .mex and .mat files to the sim folder

% parameters used in the pseudospectral method for geodesic computation
geodesic_setting_for_codegen.D = 2; 
geodesic_setting_for_codegen.N = 8;
answer = questdlg('Do you want to generate the C codes for accelerating geodesic computation used for determining the control law?','Question for code generation','Yes','No','No');
switch answer 
    case 'Yes'
        generate_code_for_geodesic_cal(plant.n,plant.nu,plant.nw,geodesic_setting_for_codegen);        
        save('geodesic_setting_for_codegen.mat','geodesic_setting_for_codegen');
    case 'No'
end
