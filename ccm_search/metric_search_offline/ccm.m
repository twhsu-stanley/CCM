function [cond_num_W_opt,W_upper,W_lower,W_bar,max_residual] = ccm(plant,controller,W,dW_dt,paras_W,lambda,state_set)

n = plant.n; % number of states
nu = plant.nu; % number of inputs

% PSD constraints
M_pos = plant.g_perp' * (dW_dt - plant.A * W - (plant.A * W)' - 2 * lambda * W) * plant.g_perp;
% A = df_dx or A = df_dx + dY_dx * a

% y and y1 are dummy variables used to convert matrix PSD constraints into scalar SOS constraints
y = sdpvar(n,1);
y1 = sdpvar(n-nu,1); 
yMy = y1' * M_pos * y1;

% Introduce metric bounds and objective
W_lower = sdpvar;
W_upper = sdpvar;
obj = W_upper;
W_bar = sdpvar(n,n,'symmetric');

F = [];

% CCM bounds
if ~isa(dW_dt,'sdpvar') % indicates that W is constant, i.e., state independent
else
    y_Wupper_W_y =  y' * (W_bar - W) * y;
    y_W_Wlower_y =  y' * W * y - W_lower * (y' * y);
end

% Decision variables
paras = paras_W;
paras = [paras; W_lower; W_bar(:)];

if state_set.consider_state_set == 1
    % considering the state constraints using S procedure        
    for i = 1:length(state_set.box_lim)               
        
        % First part: enforce metric bounds only on the state limits of W_states (which may incude the uncertainty parameter, a)
        if (i <= state_set.num_consts_4_W_states || i > state_set.num_consts_4_W_states + length(state_set.other_lim_states))...
                && isa(dW_dt,'sdpvar')
            
            % lower bound
            [~,c_Ll,v_Ll] = polynomial([state_set.W_states; y], state_set.lagrange_deg_W); % Lagrange multiliers for enforcing constraints
            if ~(isfield(state_set,'lagrange_quadratic_only') && state_set.lagrange_quadratic_only == 0)
                % only take the terms quadratic in y
                index = [];
                for k = 1:length(v_Ll)
                    if sum(degree(v_Ll(k),y)) == 2
                        index = [index k];
                    end
                end
                c_Ll = c_Ll(index); 
                v_Ll = v_Ll(index);
            end
            Ll = c_Ll' * v_Ll;
            
            % upper bound
            [~,c_Lu,v_Lu] = polynomial([state_set.W_states; y],state_set.lagrange_deg_W); % Lagrange multiliers for enforcing constraints  
            % only take the terms quadratic in y
            if ~(isfield(state_set,'lagrange_quadratic_only') && state_set.lagrange_quadratic_only == 0)
                index = [];
                for k=1:length(v_Lu)
                    if sum(degree(v_Lu(k),y)) == 2
                        index = [index k];
                    end
                end
                c_Lu = c_Lu(index); 
                v_Lu = v_Lu(index);
            end
            Lu = c_Lu' * v_Lu;
            
            y_Wupper_W_y =  y_Wupper_W_y - Lu * state_set.box_lim(i);
            y_W_Wlower_y =  y_W_Wlower_y - Ll * state_set.box_lim(i);
           
            paras = [paras; vec(c_Ll); vec(c_Lu)];
            F = [F sos(Ll) sos(Lu)];
        end

        % Second part: Enforce the second CCM condition (M_pos) in the state limits of all states and a
        [~,c_Lm,v_Lm] = polynomial([state_set.W_states; state_set.other_lim_states; y1], state_set.lagrange_deg_ccm); 
        if ~(isfield(state_set,'lagrange_quadratic_only') && state_set.lagrange_quadratic_only == 0)
             % only take the terms quadratic in y
            index = [];
            for k = 1:length(v_Lm)
                if sum(degree(v_Lm(k),y1)) == 2
                    index = [index k];
                end
            end
            c_Lm = c_Lm(index); 
            v_Lm = v_Lm(index);
        end
        Lm = c_Lm' * v_Lm;
        yMy = yMy - Lm * state_set.box_lim(i);  

        paras = [paras; vec(c_Lm)];
        F = [F sos(Lm)];    
    end
end

if ~isa(dW_dt,'sdpvar')  % indicates that W is constant
    F = [F sos(yMy) W_bar>=W  W>=W_lower*eye(n) W_lower>= controller.W_lower_bound  W_upper*eye(n)>=W_bar];
else
    F = [F sos(yMy) sos(y_W_Wlower_y) sos(y_Wupper_W_y) W_lower>= controller.W_lower_bound  W_upper*eye(n)>=W_bar]; 
end

ops = sdpsettings('solver','mosek','sos.numblkdg',1e-7); %, Need to try this

[sol, v, Q, res] = solvesos(F, obj, ops, paras);

max_residual = max(res)
disp(sol.info);
W_upper = value(W_upper); 
W_lower = value(W_lower);
cond_num_W_opt = W_upper/W_lower;
W_bar = value(W_bar);
