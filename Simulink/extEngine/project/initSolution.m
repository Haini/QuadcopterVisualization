%% Your inits may come here.
disp('--- initSolution ---');

try
    nodes = pathPlanner([0,0,1],waypoints,obstacles, obstacles_AABB, quadrotor_AABB,[-10,0,0],[10,30,6],1000);
    
    disp('initSolution: Done.');
catch MExc
    disp(MExc.message);
end