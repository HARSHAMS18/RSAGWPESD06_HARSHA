% Projectile Motion Simulation 
% Parameters
initial_velocity = input("Enter the initial Velocity :");    % Initial velocity (m/s)
angle = input("Enter the angle :");        % Launch angle (degrees)
g = 9.81;                 % Gravitational acceleration (m/s^2)

% Convert angle to radians
theta = deg2rad(angle);

% Calculate initial velocity components
vx = initial_velocity * cos(theta);
vy = initial_velocity * sin(theta);

% Time of flight
time_of_flight = (2 * vy) / g;

% Range and maximum height
range = vx * time_of_flight;
max_height = (vy^2) / (2 * g);

% Time vector for trajectory
t = linspace(0, time_of_flight, 100);

% Trajectory equations
x = vx * t;                     % Horizontal position
y = vy * t - (0.5 * g * t.^2);  % Vertical position

% Plot trajectory
figure;
plot(x, y, 'b-', 'LineWidth', 1.5);
hold on;

% Mark range and max height
plot(range, 0, 'ro', 'MarkerSize', 8, 'DisplayName', 'Range');
plot(range/2, max_height, 'go', 'MarkerSize', 8, 'DisplayName', 'Max Height');

% Labels and title
xlabel('Distance (m)');
ylabel('Height (m)');
title('Projectile Motion Trajectory');
legend('Trajectory', 'Range', 'Max Height');
grid on;
hold off;

% Display results
fprintf('Range: %.2f meters\n', range);
fprintf('Maximum Height: %.2f meters\n', max_height);
fprintf('Time of Flight: %.2f seconds\n', time_of_flight);
