function drawWorld( obstacles, waypoints )
%DRAWWORLD Draws the world with its obstacles and waypoints.
% for testing purposes

%% init figure
close all;
figure
axis([-8 8 0 30 0 4])
xlabel('x')
ylabel('y')
zlabel('z')

%% draw obstacles
for i=1:size(obstacles,1)
    l = obstacles(i,4);
    w = obstacles(i,5);
    h = obstacles(i,6);
    xmin = obstacles(i,1) - l/2;
    xmax = obstacles(i,1) + l/2;
    ymin = obstacles(i,2) - w/2;
    ymax = obstacles(i,2) + w/2;
    zmin = obstacles(i,3) - h/2;
    zmax = obstacles(i,3) + h/2;
    hold on;
    drawBox3d([xmin xmax ymin ymax zmin zmax]);
end

%% draw waypoints
for i=1:size(waypoints,1)
    hold on;
    drawSphere(waypoints(i,1), waypoints(i,2), waypoints(i,3), 0.5);
end

end

