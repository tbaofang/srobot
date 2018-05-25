#include "header.h"
#include "msg.h"
#include "commom.h"
#include "samples.h"


int main(int argc, char** argv)
{
    Samples sample;
    sample.DrawCircle(argc, argv);
    

    Pose pose(10., 20.);
    cout << pose.position.x <<endl;
    cout << pose.position.y <<endl;
    cout << pose.position.z <<endl;
    cout << "hello robot" << endl;

    Commom com;
    struct timeval start, end;
    gettimeofday(&start, NULL);
    com.Sleep(3);
    gettimeofday(&end, NULL);
    int timeuse = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec -start.tv_usec;
    cout << "timeuse:" << timeuse << endl;



    return 0;
}
