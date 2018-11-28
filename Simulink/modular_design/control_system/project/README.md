Quadcopter ESELU WS16
=====================

This is a simulation of a quadrocopter flying through a virtual world
with obstacles and waypoints.


Contents
--------

geom3d - Collects functions and libraries concerning 3D geometry.
\_ coldetect - Matlab wrapper for collision detection (VCollide lib).
   \_ VCollide - Sources of the collision detection algorithm.
\_ geom3d - Used by race control for 3d translations.
\_ meshes3d - Used by race control for data preparation.
quaternions - Collects functions to transform between quaternions and
angles or rotation matrices.
subsystems - Collects Matlab Simulink subsystems of the simulation.
\_ race_control - Model for checking correctness of flight.
world - Data and init script for the virtual world.
init.m - Initializes the simulation, called at startup automatically.
initSolution.m - A script called at the end of the simulation initialization.
                 It can be used to initialize your solution.
quadcopter_eselu.slx - Matlab Simulink simulation.


Installation
------------

No installation needed. Opening quadcopter_ese.slx will add all
paths of the subdirectories and will initialize the workspace.


Race Control
------------

Measures race time, tracks waypoints, tracks obstacle/ground crashes.

You may have to build the sources for collision detection (only for Linux 64bit
available).


Have fun,
  Denise Ratasich
