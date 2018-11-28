#include "ContactPlugin.hh"

using namespace gazebo;
GZ_REGISTER_SENSOR_PLUGIN(ContactPlugin)

/////////////////////////////////////////////////
ContactPlugin::ContactPlugin() : SensorPlugin()
{
}

/////////////////////////////////////////////////
ContactPlugin::~ContactPlugin()
{
}

/////////////////////////////////////////////////
void ContactPlugin::Load(sensors::SensorPtr _sensor, sdf::ElementPtr /*_sdf*/)
{
  std::cout << "Calling ContactPlugin Load Function...\n";

  /** Init Ros if it is not already done by another plugin. */
  if (!ros::isInitialized())
  {
      int argc = 0;
      char **argv = NULL;
      printf("Starting ROS!\n\r");
      ros::init(argc, argv, "gazebo_client", ros::init_options::NoSigintHandler);
      printf("ROS start success...\n\r");
  }

  this->rosNode.reset(new ros::NodeHandle("gazebo_publish"));
  this->pmq.startServiceThread();
  this->pub_Queue = this->pmq.addPub<std_msgs::Int32>();
  this->rosPub = this->rosNode->advertise<std_msgs::Int32>("/custom", 100);

  // Get the parent sensor.
  this->parentSensor =
    std::dynamic_pointer_cast<sensors::ContactSensor>(_sensor);

  // Make sure the parent sensor is valid.
  if (!this->parentSensor)
  {
    gzerr << "ContactPlugin requires a ContactSensor.\n";
    return;
  }

  std::cout << "Name of Parent Sensor [" << this->parentSensor->Name() <<"]\n";
  
  // Connect to the sensor update event.
  this->updateConnection = this->parentSensor->ConnectUpdated(
      std::bind(&ContactPlugin::OnUpdate, this));
    
  // Set the update rate to 100Hz
  this->parentSensor->SetUpdateRate(100);

  // Make sure the parent sensor is active.
  this->parentSensor->SetActive(true);
}

/////////////////////////////////////////////////
void ContactPlugin::OnUpdate()
{
  // Get all the contacts.
  msgs::Contacts contacts;
  contacts = this->parentSensor->Contacts();
  for (unsigned int i = 0; i < contacts.contact_size(); ++i)
  {
    std::cout << "Collision between[" << contacts.contact(i).collision1()
              << "] and [" << contacts.contact(i).collision2() << "]\n";
    msg.data = contacts.contact(i).position(0).x();
    this->pub_Queue->push(msg, this->rosPub);

    for (unsigned int j = 0; j < contacts.contact(i).position_size(); ++j)
    {
      std::cout << j << "  Position:"
                << contacts.contact(i).position(j).x() << " "
                << contacts.contact(i).position(j).y() << " "
                << contacts.contact(i).position(j).z() << "\n";
      std::cout << "   Normal:"
                << contacts.contact(i).normal(j).x() << " "
                << contacts.contact(i).normal(j).y() << " "
                << contacts.contact(i).normal(j).z() << "\n";
      std::cout << "   Depth:" << contacts.contact(i).depth(j) << "\n";
    }
  }
}
