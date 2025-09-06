#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen.
brain  Brain;
//drive
motor rightFront = motor(PORT2, ratio6_1, false);
motor rightTop = motor(PORT11, ratio6_1, false);
motor rightBack = motor(PORT15, ratio6_1, false);
motor leftFront = motor(PORT16, ratio6_1, true);
motor leftTop = motor(PORT20, ratio6_1, true);
motor leftBack = motor(PORT10, ratio6_1, true);

//intake
motor bottomIntake = motor(PORT13, ratio6_1, false);
motor hood = motor(PORT19, ratio6_1, false);

//sensors
inertial Gyro = inertial(PORT21);
rotation R_ForwardTracker = rotation(PORT11, false);
rotation R_SidewaysTracker = rotation(PORT4, false);
optical ballDetect = optical(PORT21);

//pistons
digital_out middleGoal = digital_out(Brain.ThreeWirePort.D);
digital_out matchloader = digital_out(Brain.ThreeWirePort.B);
digital_out rightWing = digital_out(Brain.ThreeWirePort.A);
digital_out leftWing = digital_out(Brain.ThreeWirePort.E);
digital_out middleGoalDescore = digital_out(Brain.ThreeWirePort.E);
controller Controller1(primary);
//The motor constructor takes motors as (port, ratio, reversed), so for example
//motor LeftFront = motor(PORT1, ratio6_1, false);

//Add your devices below, and don't forget to do the same in robot-config.h:


void vexcodeInit( void ) {
  // nothing to initialize
}