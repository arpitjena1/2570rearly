#include "intake.h"

using namespace vex;

double conveyor_power;
double hood_power;
bool col = true;
void driverColorSortTask(){
    if(col){
        if((ballDetect.hue() > 110 && ballDetect.hue() < 135) && conveyor_power != 0){
            middleGoal.set(false);
            bottomIntake.spin(vex::directionType::fwd, -127, vex::velocityUnits::pct);
            hood.spin(vex::directionType::fwd, 127, vex::velocityUnits::pct);
        }
        middleGoal.set(true);
        bottomIntake.spin(vex::directionType::fwd, conveyor_power, vex::velocityUnits::pct);
        hood.spin(vex::directionType::fwd, hood_power, vex::velocityUnits::pct);
    } else{
        if((ballDetect.hue() < 10 && ballDetect.hue() > 0) && conveyor_power != 0){
            middleGoal.set(false);
            bottomIntake.spin(vex::directionType::fwd, -127, vex::velocityUnits::pct);
            hood.spin(vex::directionType::fwd, 127, vex::velocityUnits::pct);
        }
        middleGoal.set(true);
        bottomIntake.spin(vex::directionType::fwd, conveyor_power, vex::velocityUnits::pct);
        hood.spin(vex::directionType::fwd, hood_power, vex::velocityUnits::pct);
}}
void auto_anti_jam(){
    while(true){
          if(fabs(bottomIntake.velocity(vex::velocityUnits::pct)) <= 5 && conveyor_power != 0){
            bottomIntake.spin(vex::directionType::fwd, -127, vex::velocityUnits::pct);
            vex::wait(150, vex::msec);
            bottomIntake.spin(vex::directionType::fwd, conveyor_power, vex::velocityUnits::pct);
        }
        if(fabs(hood.velocity(vex::velocityUnits::pct)) <= 5 && hood_power != 0){
            hood.spin(vex::directionType::fwd, 127, vex::velocityUnits::pct);
            vex::wait(150, vex::msec);
            hood.spin(vex::directionType::fwd, hood_power, vex::velocityUnits::pct);
        }
    }
}
void anti_jam(){
  vex::wait(50,msec);
  if(fabs(bottomIntake.velocity(vex::velocityUnits::pct)) <= 2 && conveyor_power != 0){
    bottomIntake.spin(vex::directionType::fwd, -127, vex::velocityUnits::pct);
    vex::wait(300, vex::msec);
    bottomIntake.spin(vex::directionType::fwd, conveyor_power, vex::velocityUnits::pct);
  }
  if(fabs(hood.velocity(vex::velocityUnits::pct)) <= 5 && hood_power != 0){
    hood.spin(vex::directionType::fwd, 127, vex::velocityUnits::pct);
    vex::wait(300, vex::msec);
    hood.spin(vex::directionType::fwd, hood_power, vex::velocityUnits::pct);
  }
}
void intake_long_goal(){
  middleGoal.set(false);
  bottomIntake.spin(vex::directionType::fwd, 127, vex::velocityUnits::pct);
  hood.spin(vex::directionType::fwd, -127, vex::velocityUnits::pct);
  conveyor_power = 127;
  hood_power = -127;
}

void intake_middle_goal(){
  middleGoal.set(true);
  middleGoalDescore.set(true);
  bottomIntake.spin(vex::directionType::fwd, 127, vex::velocityUnits::pct);
  hood.spin(vex::directionType::fwd, 127, vex::velocityUnits::pct);
  conveyor_power = 127;
  hood_power = 127;
}
void intake_store(){
  middleGoal.set(false);
  bottomIntake.spin(vex::directionType::fwd, 127, vex::velocityUnits::pct);
  hood.spin(vex::directionType::fwd, 16, vex::velocityUnits::pct);
  conveyor_power = 127;
  hood_power = 16;
}
void stop_intake(){
  bottomIntake.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct);
  hood.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct);
  conveyor_power = 0;
  hood_power = 0;
}
void colorSortTask(){
  if(col){
    while(!(ballDetect.hue() > 110 && ballDetect.hue() <135) ){
    bottomIntake.spin(vex::directionType::fwd, 127, vex::velocityUnits::pct);
    hood.spin(vex::directionType::fwd, -127, vex::velocityUnits::pct);
    if((ballDetect.hue() > 110 && ballDetect.hue() < 135) ){
      middleGoal.set(false);
      bottomIntake.spin(vex::directionType::fwd, -127, vex::velocityUnits::pct);
      hood.spin(vex::directionType::fwd, 127, vex::velocityUnits::pct);
      break;
    }
  }
  } else{
  while(!(ballDetect.hue() <10 && ballDetect.hue() >0) ){
    bottomIntake.spin(vex::directionType::fwd, 127, vex::velocityUnits::pct);
    hood.spin(vex::directionType::fwd, -127, vex::velocityUnits::pct);
    if((ballDetect.hue() <10 && ballDetect.hue() > 0) ){
      middleGoal.set(false);
      bottomIntake.spin(vex::directionType::fwd, -127, vex::velocityUnits::pct);
      hood.spin(vex::directionType::fwd, 127, vex::velocityUnits::pct);
      break;
    }
  }
}}


