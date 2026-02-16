function u = compute_u_ccm(x, x_nom, u_nom, Erem, gamma_s, ...
                           H, controller_lambda, use_cp, cp_quantile, ...
                           plant_fx, plant_fx_nom, plant_Bx, plant_Bx_nom, plant_Bwx)

% Formulate it as a min-norm CLF QP problem
% min [u' slack] H [u; slack]
% Constraints : A[u; slack] + B <= 0
%
% Output: u = [uc, slack]

if use_cp
    Theta = chol(inv(W_fcn1(x)));
    sigma_max = max(svd(Theta*plant_Bwx)); % maximum singular value % this is locally Lipschitz
    constraint_tightening = sigma_max * cp_quantile * sqrt(Erem);
else
    constraint_tightening = 0;
end

gamma_s1_Mx = gamma_s(:,end)'/W_fcn1(x);
A = [gamma_s1_Mx * plant_Bx, -1];
B = gamma_s1_Mx * (plant_fx + plant_Bx * u_nom) ...
    - gamma_s(:,1)'/W_fcn1(x_nom) * (plant_fx_nom + plant_Bx_nom * u_nom) ...
    + controller_lambda * Erem ...
    + constraint_tightening;

% Analytic solution
if B <= 0
    lambda = 0;
else
    denom = A*inv(H)*A';
    if denom < 1e-8
        lambda = 0;
    else
        lambda = 2*B/(A*inv(H)*A');
    end
end
u = -1/2 * lambda * inv(H)' * A';
% uc = u_nom + u(1:nu);
% slack = u(end);
