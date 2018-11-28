%% Initializes the world.
disp('--- initWorld ---');

%% Open the world to save obstacles/boxes to.
world = vrworld('world_tmpl');
open(world);

%% Load sources for the objects to add to the world.
load('waypoints');
disp('initWorld: Loaded waypoints.');
load('obstacles');
disp('initWorld: Loaded obstacles.');

%% Add waypoints with position.
% A waypoint is described by a vector (x,y,z), i.e., its position. In VRML
% the axes y and z are interchanged, so these coordinates have to be
% swapped.

% create waypoints in the world
for i=1:size(waypoints,1)
    % add waypoint to world
    name = strcat('waypoint_', num2str(i));
    transform = vrnode(world, name, 'Transform');
    
    % specialize
    transform.('translation') = [waypoints(i,1) waypoints(i,3) waypoints(i,2)];
    
    % appearance & geometry
    shape = vrnode(transform, 'children', '', 'Shape');
    appearance = vrnode(shape, 'appearance', '', 'Appearance');
    material = vrnode(appearance, 'material', '', 'Material');
    material.('diffuseColor') = [1 0 0];
    material.('transparency') = 0.5;
    geometry = vrnode(shape, 'geometry', '', 'Sphere');
    geometry.('radius') = 0.5;
end
disp('initWorld: Added waypoints to the world.');

%% Add boxes with position and size of obstacles.
% A box is described by a vector (x,y,z,l,w,h). The first 3 elements
% (x,y,z) give the center position of the box. The last 3 elements (l,w,h)
% give the size of the box.

% create obstacles in the world
for i=1:size(obstacles,1)
    % add obstacle to world
    name = strcat('block_', num2str(i));
    transform = vrnode(world, name, 'Transform');
    
    % specialize
    transform.('translation') = [obstacles(i,1) obstacles(i,3) obstacles(i,2)];
    transform.('scale') = [obstacles(i,4) obstacles(i,6) obstacles(i,5)];
    
    % appearance & geometry
    shape = vrnode(transform, 'children', '', 'Shape');
    appearance = vrnode(shape, 'appearance', '', 'Appearance');
    textureTransform = vrnode(appearance, 'textureTransform', '', 'TextureTransform');
    textureTransform.('scale') = [1 1];
    texture = vrnode(appearance, 'texture', '', 'ImageTexture');
    texture.('url') = 'stone.jpg';
    %material = vrnode(appearance, 'material', '', 'Material');
    geometry = vrnode(shape, 'geometry', '', 'Box');
    geometry.('size') = [1 1 1];
end
disp('initWorld: Added obstacles to the world.');

%% Check nodes of the world.
%save(world, 'px4.wrl');     % save under a new name
close(world);
disp('initWorld: Saved the world (px4.wrl).');

%% Clear used variables.
clear name transform 
clear shape appearance textureTransform texture material geometry
clear world

disp('initWorld: Done.');