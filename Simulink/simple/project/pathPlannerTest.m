close all;
clf;


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
tic;
nodes = pathPlanner([0,0,1],waypoints,obstacles, obstacles_AABB, quadrotor_AABB,[-10,0,0],[10,30,6],1500);
toc

last=nodes(1,:);
for n=2:size(nodes,1)
    
    v = [last;nodes(n,:)];
    plot3(v(:,1),v(:,2),v(:,3),'LineWidth',6);hold on;
    last=nodes(n,:);
end
