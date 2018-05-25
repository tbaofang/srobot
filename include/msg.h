#ifndef MSG_H
#define MSG_H


class Position
{
    public:
        double x;
        double y;
        double z;
        Position(double x_=0, double y_=0, double z_=0):x(x_),y(y_),z(z_){}
};
class Quaternion
{
    public:
        double x;
        double y;
        double z;
        double w;
        Quaternion(double x_=0, double y_=0, double z_=0, double w_=0):x(x_),y(y_),z(z_),w(w_){}
};
class Pose
{
    public:
        Position position;
        Quaternion quaternion;
        Pose(double px=0,double py=0,double pz=0,double qx=0,double qy=0,double qz=0,double qw=0):position(px,py,pz),quaternion(qx,qy,qz,qw){}
};


#endif
