cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

find_package(roscpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

include_directories(${roscpp_INCLUDE_DIRS})
include_directories(${std_msgs_INCLUDE_DIRS})
include_directories(${geometry_msgs_INCLUDE_DIRS})

# Find GAZEBO
find_package(gazebo REQUIRED)
include_directories(${GAZEBO_INCLUDE_DIRS})
link_directories(${GAZEBO_LIBRARY_DIRS})
# set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GAZEBO_CXX_FLAGS}")

#list(APPEND CMAKE_CXX_FLAGS "${GAZEBO_CXX_FLAGS}")

# Build our plugin
add_library(quadcontrol SHARED quadcontrol.cc)
add_library(factory SHARED factory.cc)
add_library(contact SHARED ContactPlugin.cc)
target_link_libraries(contact ${GAZEBO_LIBRARIES} ${roscpp_LIBRARIES})
target_link_libraries(quadcontrol ${GAZEBO_LIBRARIES} ${roscpp_LIBRARIES})
target_link_libraries(factory ${GAZEBO_LIBRARIES})
