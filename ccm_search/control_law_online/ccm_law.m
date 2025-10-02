function [uc, Erem, slack]= ccm_law(t,x_nom,u_nom,x,plant,controller)
geodesic = controller.geodesic; 
n = plant.n;
nu = plant.nu; %size(plant.B,2);
N = geodesic.N;
D = geodesic.D;

persistent t_pre beq_pre copt_pre Erem_pre
if isempty(t_pre) || (t == 0)
    t_pre = -3;
    beq_pre = zeros(2*n,1);
    copt_pre = zeros(n*(D+1),1);
    Erem_pre = Inf;
end

% get the initial value of c corresponding to a straight line
c0 = zeros(n*(D+1),1);
i = 1:n;
c0((i-1)*(D+1)+1,1) = x_nom;
c0((i-1)*(D+1)+2,1) = x - x_nom;

if isempty(geodesic.nlprob) 
    % indicates that the geodesic is (assumed to be) a straight line    
    c0 = transpose(reshape(c0,D+1,n)); % the ith row corresponds to the ith element
    gamma = c0*geodesic.T;
    gamma_s = c0*geodesic.Tdot;
    
    Erem = 0;
    for k=1:N+1  
        tmp = gamma_s(:,k)'*(controller.W_fcn(gamma(:,k))\gamma_s(:,k))*geodesic.w_cheby(k);
        Erem = Erem+ tmp ; % noite that W_fcn needs to be selected for each specific example. 
    end 
else
    beq = [x_nom;x];

    if norm(beq-beq_pre)<1e-8 && ~isinf(Erem_pre)
        copt = copt_pre;
        Erem = Erem_pre;
    else
        geodesic.nlprob.beq = beq;
        geodesic.nlprob.x0 = c0;
        [copt,Erem,exitflag,info] = fmincon(geodesic.nlprob);
        if exitflag < 0
            disp('geodesic optimization problem failed!');
        end
        beq_pre = beq;
        copt_pre = copt;
        Erem_pre = Erem;
    end
        
    % vectorized format (more computationally efficient)
    copt = transpose(reshape(copt,D+1,n)); % the ith row corresponds to the ith element
    gamma = copt*geodesic.T;
    gamma_s = copt*geodesic.Tdot;

    % Verify whether the curve found is really a geodesic
    %{
    % according to equation (11) in Leung  & Manchester
    error = 0;
    for k=1:N+1
        error = error + (gamma_s(:,k)'*(controller.W_fcn(gamma(:,k))\gamma_s(:,k))-Erem)^2*geodesic.w_cheby(k);
    end
    error = sqrt(error)/Erem;
    if error>=1e-5
    %     disp('The curve optimized is probably not a geodesic!');
        fprintf(1,'t= %.2e, Error = %.3e, the curve optimized is probably not a geodesic!\n',t,error);
        if error> 1e-2
            pause;
        end
    end
    %}
end

plant_fx = plant.f_fcn(x);
plant_fx_nom = plant.f_fcn(x_nom);
plant_Bx = plant.B_fcn(x);
plant_Bx_nom = plant.B_fcn(x_nom);
plant_Bwx = plant.Bw_fcn(x);

weight_input = 1;
weight_slack = 1000;
H = [weight_input * eye(nu), zeros(nu, 1);
    zeros(1, nu), weight_slack];

if isfield(controller,'use_generated_code') && controller.use_generated_code == 1 && ~isempty(geodesic.nlprob)
    u = compute_u_ccm_mex(x, x_nom, u_nom, Erem, gamma_s, ...
                          H, controller.lambda, int8(controller.use_cp), controller.cp_quantile, ...
                          plant_fx, plant_fx_nom, plant_Bx, plant_Bx_nom, plant_Bwx);
    % compute_u_ccm(x, x_nom, u_nom, Erem, gamma_s, ...
    %               H, controller_lambda, use_cp, cp_quantile, ...
    %               plant_fx, plant_fx_nom, plant_Bx, plant_Bx_nom, plant_Bwx);
    uc = u_nom + u(1:nu);
    slack = u(end);
else
    % Formulate it as a min-norm CLF QP problem
    % min [u' slack] H [u; slack]
    % Constraints : A[u; slack] + B <= 0
    
    Theta = chol(inv(controller.W_fcn(x)));
    sigma_max = max(svd(Theta * plant_Bwx)); % maximum singular value % this is locally Lipschitz

    gamma_s1_Mx = gamma_s(:,end)'/controller.W_fcn(x);
    A = [gamma_s1_Mx * plant_Bx, -1];
    B = gamma_s1_Mx * (plant_fx + plant_Bx * u_nom) ...
        - gamma_s(:,1)'/controller.W_fcn(x_nom) * (plant_fx_nom + plant_Bx_nom * u_nom) ...
        + controller.lambda * Erem ...
        + sigma_max * controller.cp_quantile * sqrt(Erem) * controller.use_cp;
    
    % Use quadprog to solve the QP
    %{
    f = [zeros(size(u_nom)); 0];
    [u, ~, exitflag, ~] = quadprog(H, f, A, -B, [], [], [], [], [], []);
    if exitflag == 1
        uc = u_nom + u(1:nu);
    else
        warning("Something went wrong when solving the QP using quadprog");
        uc = u_nom;
    end
    slack = u(end);
    %}

    % Analytic solution
    if B <= 0
        lambda = 0;
    else
        denom = A*inv(H)*A';
        if denom < 1e-8
            lambda = 0; % this might not be needed as the last entry of A is -1
        else
            lambda = 2*B/(A*inv(H)*A');
        end
    end
    u = -1/2 * lambda * inv(H)' * A';
    uc = u_nom + u(1:nu);
    slack = u(end);
end

if (t-t_pre>= 0.4) && mod(t,1)< 0.1
    t_pre = t;
end

end