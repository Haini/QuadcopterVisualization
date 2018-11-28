%% Initializes the race control.
disp('--- initRaceControl ---');

%% Add paths (for this init file only).
addpath('../../geom3d/');
addpath('../../geom3d/geom3d/');
addpath('../../geom3d/meshes3d/');
addpath('../../geom3d/coldetect/');

%% Check if required variables and functions are available.
if ~exist('obstacles','var')
    error('initRaceControl: Obstacles not yet loaded. Call initWorld first.');
end
if ~exist('createCube.m','file')
    error('initRaceControl: Some function from geom3d library is missing.');
end

%% Instantiate some local variables.
num_obs = size(obstacles,1);

%% Create a template bounding box, a cuboid.
% creates 1x1x1 cube
[cube_v, cube_f] = createCube;
% move center to (0,0,0)
cube_v = bsxfun(@minus, cube_v, mean(cube_v, 1));
% transform bounding box to triangles
cube_f = triangulateFaces(cube_f);

%% Create bounding box for quadrotor.
% scale to dimensions of quadrotor
sca = createScaling3d(0.45, 0.45, 0.06); % l, w, h
v = transformPoint3d(cube_v, sca); % scale first and separately!
% rotate bounding box by 45°
rot = createRotationOz(pi()/4);
v = transformPoint3d(v, rot);
quadrotor_AABB.vertices = v;
quadrotor_AABB.faces = cube_f;
disp('initRaceControl: Created bounding box for quadrotor (quadrotor_AABB).');

%% Create bounding boxes for obstacles.
% A box is described by a vector (x,y,z,l,w,h). The first 3 elements
% (x,y,z) give the center position of the box. The last 3 elements (l,w,h)
% give the size of the box. Each obstacle will be described by a bounding
% box, described by triangles (12, for each side of the box 2), whereas
% each triangle is described by 3 points. The bounding box will have the
% format: 12 rows = triangles and 9 cols = 3x3d points.
obstacles_AABB = zeros(size(cube_f,1), size(cube_f,2)*3, num_obs);

for i = 1:num_obs
    % scale and move to position
    sca = createScaling3d(obstacles(i,4:6));
    tra = createTranslation3d(obstacles(i,1:3));
    v = transformPoint3d(cube_v, sca); % scale first and separately!
    v = transformPoint3d(v, tra);
    % drawMesh(v,cube_f);
    % convert description of bounding box (needed by coldetect function)
    o_AABB = verticesAndFaces2verticesOnly(v,cube_f);
    obstacles_AABB(:,:,i) = o_AABB;
end
disp('initRaceControl: Created bounding boxes for obstacles (obstacles_AABB).');

%% compile rtspeed

mex -outdir ../ ../rtspeed.c 

%% Clear used variables.
clear i
clear cube_v cube_f v f sca tra rot
clear num_obs o_AABB

disp('initRaceControl: Done.');