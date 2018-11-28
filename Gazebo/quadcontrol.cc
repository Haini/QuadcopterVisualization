/**
 * Taken with inspiration from: gazebosim.org/tutorials?tut=plugins_model
 * www.answer.gazebosim.org/question/2341/set-and-get-position-of-gazebo-model-using-ros-plugin/
 */

#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>

#include <thread>
#include "ros/ros.h"
#include "ros/callback_queue.h"
#include "ros/subscribe_options.h"
#include "std_msgs/Float32.h"
#include "geometry_msgs/Point.h"
#include "std_msgs/Float64.h"
#include "geometry_msgs/Quaternion.h"

//#include <boost/bind.hpp>
//#include <gazebo/common/common.hh>
//#include <gazebo/common/Plugin.hh>
//#include <stdio.h>

namespace gazebo {
	class QuadModel : public ModelPlugin
	{
		public: QuadModel() {}

		public: virtual void Load(physics::ModelPtr _model,  sdf::ElementPtr _sdf)
		{
			std::cerr << "Model Name is: [" << _model->GetName() << "]\n";
			printf("Loading Plugin!\n\r");
			if (!ros::isInitialized())
			{
				int argc = 0;
				char **argv = NULL;
				printf("Starting ROS!\n\r");
				ros::init(argc, argv, "gazebo_client", ros::init_options::NoSigintHandler);
				printf("ROS start success...\n\r");
			}

			this->model = _model;
			std::cerr << "Model Name is: " + this->model->GetName() << "\n";
			
			this->rosNode.reset(new ros::NodeHandle("gazebo_client"));
		    
            ros::SubscribeOptions so;
            /* Initialize the XYZ Node */
            try {
                so = 
                    //ros::SubscribeOptions::create<geometry_msgs::Point>("/" + this->model->GetName() + "/position_O",
                    ros::SubscribeOptions::create<geometry_msgs::Point>("/position_O",
                    1, boost::bind(&QuadModel::OnRosMsg, this, _1), 
                    ros::VoidPtr(), &this->rosQueue);
            } catch (const std::exception& e) {
                std::cerr << e.what();
            }
            std::cerr << "Successfully registerd /"<<this->model->GetName()<<"/position_O\n";
			this->rosSub = this->rosNode->subscribe(so);
            
            /* Initialize the Quaternion Node */
            ros::SubscribeOptions soQuat;
            try {
                soQuat = 
                    ros::SubscribeOptions::create<geometry_msgs::Quaternion>("/attitude_O", 
                    1, boost::bind(&QuadModel::OnRosMsgQuat, this, _1), 
                    ros::VoidPtr(), &this->rosQueue);
            } catch (const std::exception& e) {
                std::cerr << e.what();
            }
            this->rosSubQuat = this->rosNode->subscribe(soQuat);
			
			this->rosQueueThread = std::thread(std::bind(&QuadModel::QueueThread, this));


		}	

		private: std::unique_ptr<ros::NodeHandle> rosNode;
		private: ros::Subscriber rosSub;    /** Subscriber for Point Topic */
        private: ros::Subscriber rosSubQuat;/** Subscriber for Quat Topic */
		private: ros::CallbackQueue rosQueue;
		private: std::thread rosQueueThread;
		private: physics::ModelPtr model;
        private: double quatX = 0;
        private: double quatY = 0;
        private: double quatZ = 0;
        private: double quatW = 0;

		public: void OnRosMsgQuat(const geometry_msgs::QuaternionConstPtr &_msg)
        {
			quatX = _msg->x;
			quatY = _msg->y;
			quatZ = _msg->z;
			quatW = _msg->z;
        }

		public: void OnRosMsg(const geometry_msgs::PointConstPtr &_msg)
		{
            /* Update the collision detection */

			double x = _msg->x;
			double y = _msg->y;
			double z = _msg->z;

            math::Vector3 vect = math::Vector3(x, y, z);

            /* We make the assumption that the messages are in sync most of the time, as the queue limit in Simulink is 1. */
            math::Quaternion quat = math::Quaternion(quatW, quatX, quatY, quatZ);
			math::Pose pose = math::Pose(vect, quat);
            std::cerr << x << ", " << y << ", " << z << ", | " << quatW << ", " << quatX << ", " << quatY << quatZ <<"\n";
			this->model->SetWorldPose(pose);
		}

		private: void QueueThread()
		{
			static const double timeout = 0.01;
			while (this->rosNode->ok()) {
				this->rosQueue.callAvailable(ros::WallDuration(timeout));
			}
		}

	};
	GZ_REGISTER_MODEL_PLUGIN(QuadModel)
}
