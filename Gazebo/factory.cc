#include <ignition/math/Pose3.hh>
#include "gazebo/physics/physics.hh"
#include "gazebo/common/common.hh"
#include "gazebo/gazebo.hh"
#include <string>

namespace gazebo
{
class Factory : public WorldPlugin
{
  public: void Load(physics::WorldPtr _parent, sdf::ElementPtr /*_sdf*/)
  {

    /* Disable the physics engine. */
    //_parent->EnablePhysicsEngine(false);

    // Option 2: Insert model from string via function call.
    // Insert a sphere model from string

    double x = 1;
    double y = 0;
    double z = 0;

    std::string strX;
    std::string strY;
    std::string strZ;
    std::string strI;

    std::string strDimX;
    std::string strDimY;
    std::string strDimZ;
    
    /* Values for obstacles. 
     * Format: X, Y, Z Coordinates and Length, Height, Width Values */
    double tData[90] =  {  
    -8.1000,    0.1000,    2.0000,    0.2000,    0.2000,    4.0000, 
    8.1000,    0.1000,    2.0000,    0.2000,    0.2000,    4.0000,
         0,    0.1000,    3.9000,   16.0000,    0.2000,    0.2000,
   -8.1000,   29.9000,    2.0000,    0.2000,    0.2000,    4.0000,
    8.1000,   29.9000,    2.0000,    0.2000,    0.2000,    4.0000,
         0,   29.9000,    3.9000,   16.0000,    0.2000,    0.2000,
         0,    3.0000,    1.0000,    1.0000,    0.5000,    2.0000,
    2.0000,   10.0000,    0.5000,    4.0000,    0.5000,    1.0000,
    4.5000,   10.0000,    2.0000,    1.0000,    0.5000,    4.0000,
   -2.0000,   18.0000,    2.0000,    2.0000,    0.5000,    4.0000,
   -1.0000,   20.0000,    2.0000,    0.5000,    4.0000,    4.0000,
   -3.0000,   15.0000,    3.5000,    0.5000,    6.0000,    1.0000,
   -3.0000,   10.0000,    2.0000,    0.5000,    4.0000,    4.0000,
    1.5000,   25.0000,    2.0000,    1.0000,    0.5000,    4.0000,
    4.0000,   25.0000,    3.0000,    4.0000,    0.5000,    2.0000};

    double tShape[3] = {0,0,0};
    double tCoord[3] = {0,0,0};
    
    /* Values for waypoints.
     * Format: X, Y, Z Coordinates. */
    double wData[15] = {     
     0,     6,     1,
     3,    10,     3,
    -1,    15,     1,
    -3,    20,     2,
     3,    25,     1};

     double wCoord[3] = {0,0,0};
     double wRadius = 1.0;

    
    /* Create the SDF for the Waypoints. */
    for (int i=0; i < 15; i+=3) {
        sdf::SDF sphereSDF;
        strI = std::to_string(i);
        
        wCoord[0] = wData[i];
        wCoord[1] = wData[i+1]; 
        wCoord[2] = wData[i+2];

        strX = std::to_string(wCoord[0]);
        strY = std::to_string(wCoord[1]);
        strZ = std::to_string(wCoord[2]);

        /* Sphere Radius */
        strDimX = std::to_string(1.0);

        sphereSDF.SetFromString(
           "<sdf version ='1.6'>\
              <model name ='waypoint"+strI+"'>\
                <pose>"+strX+" "+strY+" "+strZ+" 0 0 0</pose>\
                <static>1</static>\
                <link name ='link'>\
                  <pose>0 0 0 0 0 0</pose>"+/*\
                  <collision name ='collision'>\
                    <max_contacts>1</max_contacts>\
                    <geometry>\
                      <sphere><radius>"+strDimX+"</radius></sphere>\
                    </geometry>\
                    <surface>\
                        <contact>\
                            <collide_without_contact>\
                                1\
                            </collide_without_contact>\
                        </contact>\
                    </surface>\
                  </collision>\*/
                  "<visual name ='visual'>\
                    <geometry>\
                      <sphere><radius>"+strDimX+"</radius></sphere>\
                    </geometry>\
                    <transparency>1</transparency>\
                  </visual>\
                </link>\
              </model>\
            </sdf>");

        sdf::ElementPtr model = sphereSDF.Root()->GetElement("model");
        model->GetAttribute("name")->SetFromString("waypoint_i"+strI);
        _parent->InsertModelSDF(sphereSDF);
        
        std::cerr << wCoord[0] << " " <<  wCoord[1] << " " <<  wCoord[2] << " " <<   "\n";

    }

    /* Create the SDF for the Obstacles. */
    for (int i=0; i <  85; i+=6) {
        sdf::SDF boxSDF;
        strI = std::to_string(i);

        tCoord[0] = tData[i];
        tCoord[1] = tData[i+1];
        tCoord[2] = tData[i+2];
        tShape[0] = tData[i+3];
        tShape[1] = tData[i+4];
        tShape[2] = tData[i+5];
    
        strX = std::to_string(tCoord[0]);
        strY = std::to_string(tCoord[1]);
        strZ = std::to_string(tCoord[2]);

        strDimX = std::to_string(tShape[0]);
        strDimY = std::to_string(tShape[1]);
        strDimZ = std::to_string(tShape[2]);

        boxSDF.SetFromString(
           "<sdf version ='1.6'>\
              <model name ='box"+strI+"'>\
                <pose>"+strX+" "+strY+" "+strZ+" 0 0 0</pose>\
                <static>1</static>\
                <link name ='link'>\
                  <pose>0 0 0 0 0 0</pose>"
                  /*<collision name ='collision"+strI+"'>\
                    <max_contacts>1</max_contacts>\
                    <geometry>\
                      <box><size>"+strDimX+" "+strDimY+" "+strDimY+"</size></box>\
                    </geometry>\
                    <surface>\
                      <contact>\
                        <collide_without_contact>true</collide_without_contact>\
                      </contact>\
                    </surface>\
                  </collision>\*/
                  +"<visual name ='visual'>\
                    <geometry>\
                      <box><size>"+strDimX+" "+strDimY+" "+strDimZ+"</size></box>\
                    </geometry>\
                  </visual>\
                </link>\
              </model>\
            </sdf>");
        // Demonstrate using a custom model name.
        sdf::ElementPtr model = boxSDF.Root()->GetElement("model");
        model->GetAttribute("name")->SetFromString("unique_i"+strI);
        _parent->InsertModelSDF(boxSDF);
        
        std::cerr << tCoord[0] << " " <<  tCoord[1] << " " <<  tCoord[2] << " " <<   "\n";
        std::cerr << tShape[0] << " " <<  tShape[1] << " " <<  tShape[2] << " " <<   "\n";
    }

  }
};

// Register this plugin with the simulator
GZ_REGISTER_WORLD_PLUGIN(Factory)
}
