function [hasAllPassed, passedNow] = hasPassedWaypoints(position, waypoints)
%HASPASSEDWAYPOINTS Returns true if all waypoints have been passed, otherwise false.
%
%   position The position of the quadrotor, described by a 3-dim vector
%   [x;y;z].
%   waypoints The position of waypoints as a matrix. Each row holds the
%   position of a waypoint as [x y z].
%
%   hasAllPassed A boolean indicating if all waypoints have been passed.
%   passedNow The index of the waypoint in matrix waypoints that is catched
%   at this moment.
%
%   If a waypoint is passed, i.e., the distance between quadrotor and the
%   center of the waypoint is smaller than the waypoint's radius, an
%   appropriate waypoint flag is set. When all flags are set this function
%   returns true.
%
%   Note the radius is hardcoded here. So check the radius of a waypoint in
%   initWorld.m.
persistent passedWaypoints;     % clear with "clear hasPassedWaypoints"

%% some needed variables
hasAllPassed = false;
passedNow = 0;
num_wp = size(waypoints,1);
radius = 0.5;   % used in initWorld.m

%% indicates which waypoint has been passed
if isempty(passedWaypoints)
    passedWaypoints = zeros(num_wp,1);  % initialize with zero-vector
end

%% check if quadrotor position meets a waypoint
for i = 1:num_wp
    % calculate distance to waypoint center
    d = dot(position' - waypoints(i,:), position' - waypoints(i,:));
    d = sqrt(d);

    if d < radius
        passedWaypoints(i) = 1;
        passedNow = i;
        
        % if the waypoints are assumed to be not overlapping, one can leave
        % the loop
        break;
    end
end

%% set return values
if sum(passedWaypoints) == num_wp
    hasAllPassed = true; 
end

end
