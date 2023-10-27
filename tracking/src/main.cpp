/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       李国宇                                                       */
/*    Created:      2023/10/26 19:20:07                                       */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;

// define your global instances of motors and other devices here
vex::vision Vision10(10);

int main() {
    motor motor01(20,true);
    motor motor02(19,true);
    motor motor03(18,true);
    motor motor11(11);
    motor motor12(12);
    motor motor13(13);
     double v1=0;
     double vm=10;
  while(1)
  {
    Vision10.takeSnapshot(green);
    int x=Vision10.objects[0].centerX;
    //int y=Vision10.objects[0].centerY;
    v1=((double)x-(315/2))/157;
    if (x==0){
    motor01.spin(fwd,0,pct);
    motor02.spin(fwd,0,pct);
    motor03.spin(fwd,0,pct);
    motor11.spin(fwd,0,pct);
    motor12.spin(fwd,0,pct);
    motor13.spin(fwd,0,pct);
    }
    else{
      motor01.spin(fwd,vm+v1*vm,pct);
    motor02.spin(fwd,vm+v1*vm,pct);
    motor03.spin(fwd,vm+v1*vm,pct);
    motor11.spin(fwd,vm-v1*vm,pct);
    motor12.spin(fwd,vm-v1*vm,pct);
    motor13.spin(fwd,vm-v1*vm,pct);
    x=0;
    }
    
  }
  
  
}
