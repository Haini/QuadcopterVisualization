%% initialization
close all;
clear all;                  % clear persistent variables, etc.

cd ..
addpath('coldetect');
addpath('geom3d');
addpath('meshes3d');

cd coldetect
%
%mex coldetect.cpp VCollide.lib RAPID.lib   % Win 32bit (build libs first)
mex coldetect.cpp libVCollide.a libRAPID.a  % Linux 64bit
cd ..
    
%% define two boxes
% cubes represented as vertices and faces
[c1_v, c1_f] = createCube;
[c2_v, c2_f] = createCube;

% scale and translate
sca = createScaling3d(2,2,2);
tra = createTranslation3d(0.5,0.5,3);
v = transformPoint3d(c1_v, sca);
c1_v = transformPoint3d(v, tra);

%% prepare for coldetect
% transform bounding box to triangles
c1_f = triangulateFaces(c1_f);
c2_f = triangulateFaces(c2_f);

% bounding boxes of cubes
c1_OBB = verticesAndFaces2verticesOnly(c1_v, c1_f);
c2_OBB = verticesAndFaces2verticesOnly(c2_v, c2_f);

% transformation (none -> identity matrix)

% The matrices TRANS1 and TRANS2 define the transformations of objects.
% They both have twelve columns and have the same number of rows. Each row
% (e1, ..., e12) defines a single transformation matrix: 
% [ e4  e5  e6 e1] 
% [ e7  e8  e9 e2] 
% [e10 e11 e12 e3] 
% [ 0 0 0 1]
notrans = [0 0 0 1 0 0 0 1 0 0 0 1];
%notrans = repmat(notrans, [size(c1_OBB,1) 1]); % notrans for each point in OBB

%% draw the cubes
drawMesh(c1_v, c1_f)
drawMesh(c2_v, c2_f)

res = coldetect(c1_OBB, c2_OBB, notrans, notrans);
if res > 0
    disp('collision')
else
    disp('no collision')
end