#ifndef RVIZ_H
#define RVIZ_H

#include "msg.h"

#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Quaternion.h>
#include <nav_msgs/Path.h>
#include <ros/ros.h>
#include <tf/tf.h>

class Rviz
{
    public:
        ros::Publisher path_pub;
        Rviz(int argc, char** argv);
        void Path(const Pose &pose, double th, int argc, char** argv);
};

#endif
