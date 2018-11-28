# Quadcopter Visualization with Simulink and V-REP / Gazebo

## Content of Repository


## Gazebo Instructions

### Get Gazebo
On Ubuntu, just `sudo apt-get gazebo7 gazebo7-common gazebo7-plugin-base libgazebo7`.

gcc / g++ 6.3 have been used and tested with this release, if segfaults happen, the compiler version may be the culprit.

### Run Gazebo
To build the plugins, follow the [tutorial](http://gazebosim.org/tutorials?tut=plugins_hello_world&cat=write_plugin).

#### Excerpt from Tutorial
Create a build directory in the Gazebo project root, if none exists.

`$ cd ./Gazebo`

`$ mkdir build`

`$ cd ./build`

Create the make files:

`$ cmake ../`

Compile the binaries:

`$ make`

To tell Gazebo, where the compiled plugins are, one needs to export the `GAZEBO_PLUGIN_PATH` (or add it to your environment): 

`$ export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:YourPathToProject/Gazebo/build`

Make sure that a `roscore` server is already up and running

Run gzserver: `$ gzserver ../quadcopter.world --verbose`

Run gzclient: `$ gzclient`

The Gazebo simulation is then already up and running, just start the Simulink simulation.

## V-REP Instructions

### Get V-REP
Download [here](http://www.coppeliarobotics.com/downloads.html).

With the release of 3.5, the RosInterface should now work out of the box for Ubuntu 16.04.

For older versions, see this [guide](http://www.coppeliarobotics.com/helpFiles/en/rosTutorialIndigo.htm).

### Run V-REP
Make sure, that a `roscore` server is already up and running.

Just `cd` into the downloaded and extracted folder and run `./vrep.sh`, then in the toolbar `File -> Open File` the requested `*.ttt` file (most likely `final_quadcopter.ttt`)

The V-REP Simulation needs then to be started by pressing the play button in the toolbar.

Don't save the simulation after a run if nothing was changed - obstacles could duplicate on next launch.

## Simulink Instructions

### Run Simulink

- Start up matlab
- Open the Init.m file
- Execute it
- Open the corresponding simulink `*.slx` file
- Make sure that a `roscore` server is running
- Execute the simulation
