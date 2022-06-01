#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include "ros/ros.h"
#include "geometry_msgs/Twist.h" 
#include "sensor_msgs/LaserScan.h" 
#include "sensor_msgs/PointCloud.h" 
#include  "geometry_msgs/PoseStamped.h" 
#include "geometry_msgs/TransformStamped.h"
#include "tf/transform_listener.h"                        
#include <laser_geometry/laser_geometry.h>
#include <math.h>
#include <visualization_msgs/Marker.h>
#include <sensor_msgs/PointCloud2.h>
#include <bits/stdc++.h>
using namespace std;
#include <vector>


ros::Publisher cmd_pub;
ros::Publisher pcl_pub;
ros::Publisher pub_pointCloudStatic;
ros::Publisher pub_pointCloudDynamic ;
ros::Publisher marker_pub; 
ros::Publisher velocity_pub;

ros::Subscriber scan_sub; 
ros::Subscriber goal_sub; 
ros::Subscriber vel_sub;

laser_geometry::LaserProjection projector_;
geometry_msgs::PoseStamped received_goal;
bool goal_available = false;
double resultant_force;

void processLaserData()
{

}


void scanCallbackS (const sensor_msgs::LaserScan::ConstPtr& scan_in)
{

     
     static tf::TransformListener listener_;
     static tf::TransformListener goal_tf_listener_;

     std::vector<float> laser_ranges;
     laser_ranges = scan_in->ranges;

     ROS_INFO("Number of laser points: %d", laser_ranges.size());


     // Transforming Laserscan to PointCloud

     if(!listener_.waitForTransform(
        scan_in->header.frame_id,
        "base_link",
        scan_in->header.stamp + ros::Duration().fromSec(scan_in->ranges.size()*scan_in->time_increment),
        ros::Duration(1.0))){
     return;
     }

     sensor_msgs::PointCloud cloud;
     projector_.transformLaserScanToPointCloud("base_link",*scan_in,
          cloud,listener_);

     // Do something with cloud.
  
     ROS_INFO("Number of cloud points: %d", laser_ranges.size());
     // ROS_INFO("First point in the cloud: (%g, %g)", cloud.points[0].x, cloud.points[0].y);

     // Store multiple PointCloud data in vector as vector elements 

     vector<vector<float> PointCloud;
        for(unsigned  int i=0; i < PointCloud.size(); i++)
        { 
    
         PointCloud.push_back(laser_ranges);

        } 
     
        
     // iterate which element of vector we want to compare 
     int & numRef = PointCloud.at(0);
     int & numRef = PointCloud.at(5);

     //vector<int> :: iterator iter = PointCloud.begin();

     // call Laserscan data 
     
     for (unsigned int i = 1; i < PointCloud.size(); i++) 
{
     if (PointCloud[i].size() == PointCloud[i-1].size()) 
    {
        cout << "Static Environemnt Detected " << endl;
    }
    else 
    {
        cout << "Dynamic Environment Detected " << endl;
    }
}



     // iterate to the next one and erase the previous one 




     // call Laserscan data again 


     

     // Converting Laser_scan vevtor to arrays and compare 
     int arr1[360];
     int arr2[360];
     int n = sizeof(arr1) / sizeof(int);
     //int n = laser_ranges.size();
     int m = sizeof(arr2) / sizeof(int);
    //int m = arr2.size();
     std::copy(laser_ranges.begin(), laser_ranges.end(),arr1);
     std::copy(laser_ranges1.begin(), laser_ranges1.end(),arr2);

     // Returns true if arr1[0..n-1] and arr2[0..m-1]
     // contain same elements.
     bool areEqual(int arr1[], int arr2[], int n, int m)
     {
     // If lengths of arrays are not equal
     if (n != m)
        return false;
 
     // Store arr1[] elements and their counts in
     // hash map
     unordered_map<int, int> mp;
     for (int i = 0; i < n; i++)
        mp[arr1[i]]++;
 
     // Traverse arr2[] elements and check if all
     // elements of arr2[] are present same number
     // of times or not.
     for (int i = 0; i < n; i++) {
        // If there is an element in arr2[], but
        // not in arr1[]
        if (mp.find(arr2[i]) == mp.end())
            return false;
 
        // If an element of arr2[] appears more
        // times than it appears in arr1[]
        if (mp[arr2[i]] == 0)
            return false;
 
        mp[arr2[i]]--;
    }
 
    return true;
}
 
 
    if (areEqual(arr1, arr2, n, m))
        cout << "it is static environment";
        pub_pointCloudStatic.publish();
    else
        cout << "it is dynamic environment";
        pub_pointCloudDynamic.publish();
    return 0;
    } 
}




       
     for (int i = 1; i < 360; i++) {
        if (laser_ranges[i] < max_dist) {
            max_dis = laser_ranges[i];
        }t
     if (laser_ranges )

     while((Tc - Ts ) <= Tf) 

    if (laser_ranges.size == )


     //pcl_pub.publish(cloud);
     //ROS_INFO("RUNNING");

    }

}






int main(int argc, char **argv)
{
  
 //Initializing ROS node
    ros::init(argc, argv, "dynamic_object_detection");		
    ros::NodeHandle n;
    ros::Duration time_between_ros_wakeups(0.1);

    scan_sub = n.subscribe("/scan",100,scanCallback);
    pub_pointCloudStatic = nh.advertise<sensor_msgs::PointCloud2>("pub_pointCloud", 1);

    while (ros::ok())
    {
      ros::spinOnce();
      processLaserData();
      time_between_ros_wakeups.sleep();
    }
    return 0;

  return 0;
}
