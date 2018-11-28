%% Initializes the simulation.
close all;
clear all;                     % clear persistent variables, etc.

try
    %% paths
    addpath('subsystems');      % add path to subsystems
    addpath('subsystems/race_control');
    addpath('world');           % add path to world

    % add geom3d libs to path
    if ~exist('geom3d','dir')
        error('geom3d library missing. Folder must be located in root folder of this simulation.');
    end
    addpath('geom3d/');
    addpath('geom3d/geom3d/');
    addpath('geom3d/meshes3d/');
    addpath('geom3d/coldetect/');
    addpath('quaternions');
    
    %% compile
    %cd subsystems
    %mex rtspeed.c
    %cd ..
    cd geom3d/coldetect
    %
   
    %for MAKEFILE and instructions see geom3d/coldetect/v-collide-2.01.tar.gz
    if ispc
    	mex coldetect.cpp VCollide.lib RAPID.lib   % Win (build 32bit or 64bit libs first)
    elseif isunix
    	mex coldetect.cpp libVCollide.a libRAPID.a  % Linux (build 32bit or 64bit libs first)
    else
        warning('Unsupported OS');
    end
    cd ../..
    disp('Compilation done.');

    %% variables
    load('bus_datatypes');      % load bus data types
    disp('Loaded variables.');

    %% world
    cd world
    initWorld;
    cd ..

    %% race control
    if exist('subsystems/race_control/initRaceControl.m','file')
        cd subsystems/race_control
        initRaceControl;
        cd ../..
    else
        warning('Race Control is not fully available yet. Hence you are not able to take lap time, check for collisions or check if all waypoints have been passed.');
    end

    %% individual inits
    initSolution;
    
    disp('---');
    disp('Initialization done.');
catch MExc
    disp(MExc.message);
end
