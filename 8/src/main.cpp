/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       李国宇                                                       */
/*    Created:      2023/10/4 19:52:22                                        */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen


// define your global instances of motors and other devices here

const double d=45/2;//d为底盘宽的一半
const double r=5/2;//r为小轮半径
int main() {

    Brain.Screen.printAt( 10, 50, "start moving" );
    double c=r*2*M_PI;
    while(1) {
    double w=(2*M_PI)/10;
    vex::motor motor1(0);
    vex::motor motor2(9);
    double v1=(w*50-(d*w))/c*60;
    double v2=(w*50+(d*w))/c*60;
    motor1.spin(vex::directionType::fwd,v1,vex::velocityUnits::rpm);
    motor2.spin(vex::directionType::fwd,-v2,vex::velocityUnits::rpm);
    this_thread::sleep_for(M_PI/w);
    motor2.spin(vex::directionType::fwd,-v1,vex::velocityUnits::rpm);
    motor1.spin(vex::directionType::fwd,v2,vex::velocityUnits::rpm);
    this_thread::sleep_for(2*M_PI/w);
    motor1.spin(vex::directionType::fwd,v1,vex::velocityUnits::rpm);
    motor2.spin(vex::directionType::fwd,-v2,vex::velocityUnits::rpm);
    this_thread::sleep_for(M_PI/w);
    }
    return 0;
}

void move(double &x0,double &y0,double &x,double &y)
{
    double x0=0,y0=0,o0=0;
    double dis=sqrt(pow(x,x0)+pow(y,y0));
    double o=atan2(y-y0,x-x0);
    //double w=o/5;
    double o1=o-o0;
    while(o1>M_PI)
    o1-=2*M_PI;
    while(o1<M_PI)
    o1+=2*M_PI;
    double w=o1/2;
    double v1,v2;
    v1=50+w*d;
    v2=50-w*d;
    //缺少判断是否到移动到点的语句
}
