#ifndef _GAZEBO_CONTACT_PLUGIN_HH_
#define _GAZEBO_CONTACT_PLUGIN_HH_

#include <string>

#include <thread>
#include "ros/ros.h"
#include "ros/callback_queue.h"
#include "ros/subscribe_options.h"
#include "ros/advertise_options.h"
#include "std_msgs/Int32.h"
#include "geometry_msgs/Point.h"
#include "std_msgs/Float64.h"
#include "geometry_msgs/Quaternion.h"
#include "std_msgs/String.h"

#include <gazebo/gazebo.hh>
#include <gazebo/sensors/sensors.hh>
#include <gazebo_plugins/PubQueue.h>


namespace gazebo
{
  /// \brief An example plugin for a contact sensor.
  class ContactPlugin : public SensorPlugin
  {
    /// \brief Constructor.
    public: ContactPlugin();

    /// \brief Destructor.
    public: virtual ~ContactPlugin();

    /// \brief Load the sensor plugin.
    /// \param[in] _sensor Pointer to the sensor that loaded this plugin.
    /// \param[in] _sdf SDF element that describes the plugin.
    public: virtual void Load(sensors::SensorPtr _sensor, sdf::ElementPtr _sdf);

    /// \brief Callback that receives the contact sensor's update signal.
    private: virtual void OnUpdate();

    /// \brief Pointer to the contact sensor
    private: sensors::ContactSensorPtr parentSensor;

    /// \brief Connection that maintains a link between the contact sensor's
    /// updated signal and the OnUpdate callback.
    private: event::ConnectionPtr updateConnection;

    /* Stuff that is concerned with ROS. */
	private: std::unique_ptr<ros::NodeHandle> rosNode;
    private: ros::Publisher rosPub;
    //private: std_msgs::String msg;
    private: std_msgs::Int32 msg;
    private: PubQueue<std_msgs::Int32>::Ptr pub_Queue;
    private: PubMultiQueue pmq;

  };
}
#endif
