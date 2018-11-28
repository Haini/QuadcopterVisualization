function tpoints = transformPoints3d(points, transform)
%TRANSFORMPOINTS3D Transform an array of points with a 3D affine transform
%
%   TPOINT = transformPoints3d(POINTS, TRANSFORM); 
%   where POINTS is an array of points of the form [xi yi zi], and
%   TRANSFORM is a [4x4] matrix, returns the point transformed according to
%   the affine transform specified by TRANSFORM.

%% check inputs
% points given?
if size(points, 1) == 0
    error('transformPoints3d: No input points.')
end
% check for 3d point
if sum(size(points(1,:)) == [1 3]) ~= 2
    error('transformPoints3d: Wrong dimensions of input points. 3d points expected.')
end

% check for 4x4 transform matrix
if sum(size(transform) == [4 4]) ~= 2
    error('transformPoints3d: Wrong dimensions of input transform. 4x4 transform matrix is needed.')
end

%% convert coordinates
num_points  = size(points,1);
res = zeros(num_points,4);

% process each point one by one, writing in existing array
for i = 1:num_points
    res(i,:) = [points(i,:) 1] * transform';
end

tpoints = res(:,1:3);