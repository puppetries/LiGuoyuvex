/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       李国宇                                                       */
/*    Created:      2023/10/20 20:27:46                                       */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen


// define your global instances of motors and other devices here


int main()
{
    //定义马达，控制器和初始速度
    motor motor01(20,true);
    motor motor02(19,true);
    motor motor03(18,true);
    motor motor11(11);
    motor motor12(12);
    motor motor13(13);
    int vm=25;
    int vm1=12;
    controller c1;
    int lx=0;
    int ly=0;
    int rx=0;
    int ry=0;
    int v1=0;
    int v2=0;
    int v3=0;
    int v4=0;
    brain b;
    motor motor1(1);
    motor motor2(2,true);
    motor motor3(3,true);
    motor motor4(4);
    while(1)
    {
        //小车底盘运动
        ly=c1.Axis3.position(pct);
        lx=c1.Axis4.position(pct);
        ry=c1.Axis2.position(pct);
        rx=c1.Axis1.position(pct);
        v1=((float)ly/100)*vm;
        v2=((float)lx/100)*vm;
        v3=((float)ry/100)*vm1;
        v4=((float)rx/100)*vm1;
        motor01.spin(fwd,v1+v2+v3+v4,pct);
        motor02.spin(fwd,v1+v2+v3+v4,pct);
        motor03.spin(fwd,v1+v2+v3+v4,pct);
        motor11.spin(fwd,v1-v2+v3-v4,pct);
        motor12.spin(fwd,v1-v2+v3-v4,pct);
        motor13.spin(fwd,v1-v2+v3-v4,pct);
        c1.Screen.setCursor(1,1);
        c1.Screen.print(v1+v2+v3+v4);
        c1.Screen.setCursor(1,6);
        c1.Screen.print(v1);
        //小车送出粽子
        if(c1.ButtonL1.pressing())
        {
            motor1.spin(fwd,100,rpm);
            motor2.spin(fwd,100,rpm);
        }
        //小车拿粽子
        else if(c1.ButtonL2.pressing())
        {
            motor1.spin(fwd,-100,rpm);
            motor2.spin(fwd,-100,rpm);
        }
        else
        {
            motor1.spin(fwd,0,rpm);
            motor2.spin(fwd,0,rpm);
        }
        //小车投掷粽子
        /*if(c1.ButtonR1.pressing())//快速一直投
        {
            motor3.spin(fwd,50,rpm);
            motor4.spin(fwd,50,rpm);
        }
        else if(c1.ButtonR2.pressing())//慢慢投
        {
            motor3.spin(fwd,5,rpm);
            motor4.spin(fwd,5,rpm);
        }
        else
        {
            motor3.spin(fwd,0,rpm);
            motor4.spin(fwd,0,rpm);
        }*/
        if(c1.ButtonR1.pressing()&&motor3.spinFor(-50,deg,-50,rpm))//停住投
        {
            motor3.spinFor(-290,deg,50,rpm);
            motor4.spinFor(-290,deg,50,rpm);
        }
        else if(c1.ButtonR2.pressing())
        {
            motor3.spin(fwd,-50,rpm);
            motor4.spin(fwd,-50,rpm);
        }
        else
        {
            motor3.stop(hold);
            motor4.stop(hold);
        }
    }
return 0;
}