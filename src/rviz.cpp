#include "rviz.h"


#include <iostream>

using namespace std;

Rviz::Rviz(int argc, char** argv)
{
//    ros::init(argc, argv, "showpath");
//    ros::NodeHandle n;
//    ros::Publisher path_pub = n.advertise<nav_msgs::Path>("trajectory", 1, true);
//

}

void Rviz::Path(const Pose &pose, double th, int argc, char** argv)
{
    ros::init(argc, argv, "showpath");
    ros::NodeHandle n;
    ros::Publisher path_pub = n.advertise<nav_msgs::Path>("trajectory", 1, true);


    nav_msgs::Path path;
    path.header.stamp = ros::Time::now();
    path.header.frame_id = "odom";
    geometry_msgs::PoseStamped this_pose_stamped;
    this_pose_stamped.pose.position.x = pose.position.x;
    this_pose_stamped.pose.position.y = pose.position.y;
    geometry_msgs::Quaternion goal_quat = tf::createQuaternionMsgFromYaw(th);
    this_pose_stamped.pose.orientation.x = goal_quat.x;
    this_pose_stamped.pose.orientation.y = goal_quat.y;
    this_pose_stamped.pose.orientation.z = goal_quat.z;
    this_pose_stamped.pose.orientation.w = goal_quat.w;
    this_pose_stamped.header.stamp = ros::Time::now();
    this_pose_stamped.header.frame_id = "odom";
    path.poses.push_back(this_pose_stamped);

    path_pub.publish(path);
    ros::spinOnce();
    cout << "path" << " " << pose.position.y << endl;
}
