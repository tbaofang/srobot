#include "samples.h"
#include "commom.h"
#include "msg.h"
#include "rviz.h"

#include <math.h>
void Samples::DrawCircle(int argc, char** argv)
{
    Pose pose;
//    Rviz rv(argc, argv);

    double x = 0.0;
    double y = 0.0;
    double th = 0.0;
    double vx = 0.1;
    double vy = -0.1;
    double vth = 0.1;

    struct timeval current_time, last_time;
    gettimeofday(&last_time, NULL);
    gettimeofday(&current_time, NULL);


    ros::init(argc, argv, "showpath");
    ros::NodeHandle n;
    ros::Publisher path_pub = n.advertise<nav_msgs::Path>("trajectory", 1, true);
    nav_msgs::Path path;

    Commom com;
    // while(true){
    while(ros::ok()){
        gettimeofday(&current_time, NULL);
        double dt = current_time.tv_sec-last_time.tv_sec + (double)(current_time.tv_usec - last_time.tv_usec)/1000000;
        double delta_x = (vx*cos(th) - vy*sin(th))*dt;
        double delta_y = (vx*sin(th) + vy*cos(th))*dt;
        double delta_th = vth*dt;

        x += delta_x;
        y += delta_y;
        th +=delta_th;

        pose.position.x = x;
        pose.position.y = y;
        cout << dt << " " << pose.position.x << " " << pose.position.y << endl;
        gettimeofday(&last_time, NULL);
        com.Sleep(1000);

        // Path(pose, th, argc, argv);


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
}
