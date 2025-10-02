%% x vs. x_nom
figure;
subplot(3,2,1); hold on;
plot(times,xnomTraj(1,:),'--');
plot(times,xTraj(1,:),'-');
xlabel('Time (s)')
ylabel('x (m)')
legend('Nominal',"CCM");

subplot(3,2,2); hold on;
plot(times,xnomTraj(2,:),'--');
plot(times,xTraj(2,:),'-');
xlabel('Time (s)')
ylabel('z (m)')

subplot(3,2,3); hold on;
plot(times,xnomTraj(3,:)*180/pi,'--');
plot(times,xTraj(3,:)*180/pi);
xlabel('Time (s)')
ylabel('Phi (deg)')

subplot(3,2,4); hold on;
plot(times,xnomTraj(4,:),'--');
plot(times,xTraj(4,:),'-');
xlabel('Time (s)')
ylabel('vx (m/s)')

subplot(3,2,5); hold on;
plot(times,xnomTraj(5,:),'--');
plot(times,xTraj(5,:),'-');
xlabel('Time (s)')
ylabel('vz (m/s)')

subplot(3,2,6); hold on;
plot(times,xnomTraj(6,:)*180/pi,'--');
plot(times,xTraj(6,:)*180/pi);
xlabel('Time (s)')
ylabel('Phi rate (deg/s)')

%% u vs. u_nom
figure;
plot(times,unomTraj(1,:),'b--',times,unomTraj(2,:),'r--'); hold on
plot(times,uTraj(1,:),'b-',times,uTraj(2,:),'r-');
xlabel('Time (s)');
ylabel('u (N)');
legend('u_{nom,1}', 'u_{nom,2}','u_1: CCM','u_2: CCM');

%% Slack
figure;
plot(times,slackTraj(1,:)); grid on
xlabel('Time (s)');
ylabel('CLF QP slack');

%% Error norm
% controller.cp_quantile here is actually max(Bw*w)
max_slack = max(slackTraj);
figure;
plot(times, vecnorm(xnomTraj - xTraj,2,1)); hold on
if controller.use_cp == false
    % ignore the slack since it shouldn't have been needed
    plot(times, sqrt(controller.w_upper/controller.w_lower) * norm(xnomTraj(:,1) - xTraj(:,1)) * exp(-controller.lambda.*times) ...
        + sqrt(controller.w_upper/controller.w_lower)*controller.cp_quantile/controller.lambda * (1-exp(-controller.lambda.*times)));
    legend('actual','og upper bound');
else
    plot(times, sqrt(controller.w_upper/controller.w_lower * norm(xnomTraj(:,1) - xTraj(:,1))^2 * exp(-2*controller.lambda.*times) ...
    + 2*max_slack*controller.w_upper * (1-exp(-2*controller.lambda.*times))) ); hold on
    %
    plot(times, sqrt(controller.w_upper/controller.w_lower) * norm(xnomTraj(:,1) - xTraj(:,1)) * exp(-controller.lambda.*times) ...
        + sqrt(controller.w_upper/controller.w_lower)*controller.cp_quantile/controller.lambda * (1-exp(-controller.lambda.*times)));
    legend('actual','tightened upper bound', 'og upper bound');
end
xlabel('Time (s)');
ylabel('||x||_2');

grid on

%% Riemannian distance
figure;
plot(times, sqrt(energyTraj)); hold on
if controller.use_cp == false
    plot(times, sqrt(energyTraj(1)) * exp(-controller.lambda.*times) ...
        + controller.cp_quantile/controller.lambda/sqrt(controller.w_lower) * (1-exp(-controller.lambda.*times)));
    legend("actual", "og upper bound");
else
    plot(times, sqrt(energyTraj(1) * exp(-2*controller.lambda.*times) ...
        + (1-exp(-2*controller.lambda.*times)) * 2*max_slack));
    %
    plot(times, sqrt(energyTraj(1)) * exp(-controller.lambda.*times) ...
        + controller.cp_quantile/controller.lambda/sqrt(controller.w_lower) * (1-exp(-controller.lambda.*times))); hold on

    legend("actual","tightened upper bound", "og upper bound")
end
ylim([0,inf]);
xlabel('Time (s)');
ylabel('Riemann distance: sqrt E(t)');
grid on

%%
figure;
hold on;
h1 = plot(xnomTraj(1,:),xnomTraj(2,:),'b--');
h2 = plot(xTraj(1,:),xTraj(2,:),'r-');
scatter(xnomTraj(1,1),xnomTraj(2,1),'bo')
scatter(xnomTraj(1,end),xnomTraj(2,end),'b*')
scatter(xTraj(1,end),xTraj(2,end),'r*')
xlabel('x (m)')
ylabel('z (m)')
legend('Nominal', "actual");
grid on
