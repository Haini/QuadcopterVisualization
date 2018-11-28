function crashed_obstacles = myHasCrashedObstacle( obstacles, obstacles_AABB, quadrotor_AABB, position, attitude ) %#codegen
%HASCRASHEDOBSTACLES Returns a vector indicated which obstacles have been collided with. 
%   
%   obstacles_AABB The axis-aligned bounding boxes of the obstacles.
%   quadrotor_AABB The axis-aligned bounding box of the quadrotor. This
%   bounding box will be transformed w.r.t. given position and attitude.
%   position The position of the quadrotor, described by a 3-dim vector
%   [x;y;z].
%   attitude The rotation of the quadrotor, described by a 3-dim array or
%   vector [roll pitch yaw] or a quaternion, a 4-dim array [q0 q1 q2 q3].
%
%   Returns:
%   crashed_obstacles A vector indicated which obstacles have been crashed.
%                     Note: last element in this vector represents the
%                     ground at hight 0.


% Mark coldetect external lib, such that the compiler never tries to
% compile coldetect, it just sets up a call to it.
%
% However, for standalone code generation, ALL inputs must be in MATLAB or
% C. The compiler cannot deconstruct a mex file and emit C code. So this is
% the way it should be coded: You'd directly use the C library that is used
% both by your MEX file and your coder project. Then from your MATLAB
% function you would call into this library using coder.ceval.
coder.extrinsic('coldetect');

% mark this function and all following calls as extrinsic, i.e., can only
% be simulated, no code generation
%coder.extrinsic('transformPoint3d','verticesAndFaces2verticesOnly');

%% some local variables
num_obs = size(obstacles_AABB,3);
x = position(1);
y = position(2);
z = position(3);
if length(attitude) == 3
    roll = attitude(1);
    pitch = attitude(2);
    yaw = attitude(3);
    
    % create 4x4 rotation matrix
    rotZ = createRotationOz(yaw);
    rotY = createRotationOy(pitch);
    rotX = createRotationOx(roll);
    rot = rotX * rotY * rotZ; 
elseif length(attitude) == 4
    % create 4x4 rotation matrix (no translation or rotation)
    rot = eye(4,4);
    % insert 3x3 rotation matrix calculated from quaternion
    rot(1:3,1:3) = qGetR(attitude);
end

%% initialize persistent variables (only once)

crashedObstacles = zeros(num_obs+1,1);  % initialize with zero-vector


%% transform quadrotor_AABB to oriented bounding box (OBB)
% convert unit basis to ellipsoid basis
tra = createTranslation3d([x y z]);
% rotation created above

% concatenate transforms
trans = tra * rot;

% transform mesh vertices
v = transformPoints3d(quadrotor_AABB.vertices, trans);
quadrotor_OBB = verticesAndFaces2verticesOnly(v, quadrotor_AABB.faces);

%% check if quadrotor collides with an obstacle
notrans = [0 0 0 1 0 0 0 1 0 0 0 1];
%notrans = repmat(notrans, [size(quadrotor_OBB,1) 1]); % no transformation for each point in a triangle
% go through all obstacles

obsdistance = zeros(num_obs,1);

% only check closest obstacles
num_obs_to_check = 4;
for i = 1:num_obs
    obsdistance(i) = norm(obstacles(i,1:3) - [x y z]);
end
[~, closest_obs_idx] = sort(obsdistance);

for i = 1:num_obs_to_check
    obsid = closest_obs_idx(i);
    res = 0;
    res = coldetect(quadrotor_OBB, obstacles_AABB(:,:,obsid), notrans, notrans);
    if res > 0
        crashedObstacles(obsid) = 1;
    end
end

% check if we crashed into the ground
if z < 0
    crashedObstacles(num_obs+1) = 1;
end
%% set return values
crashed_obstacles = crashedObstacles;

end
