#include "samples.h"
#include "commom.h"
#include "msg.h"
#include "rviz.h"

#include <math.h>
void Samples::DrawCircle(int argc, char** argv)
{
    Pose pose;
    Rviz rv(argc, argv);

    double x = 0.0;
    double y = 0.0;
    double th = 0.0;
    double vx = 0.1;
    double vy = -0.1;
    double vth = 0.1;

    struct timeval current_time, last_time;
    gettimeofday(&last_time, NULL);
    gettimeofday(&current_time, NULL);

    Commom com;
    while(true){
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
        rv.Path(pose, th, argc, argv);
        gettimeofday(&last_time, NULL);
        com.Sleep(1000);
    }
}
