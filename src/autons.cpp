#include "vex.h"

/**
 * Resets the constants for auton movement.
 * Modify these to change the default behavior of functions like
 * drive_distance(). For explanations of the difference between
 * drive, heading, turning, and swinging, as well as the PID and
 * exit conditions, check the docs.
 */

void default_constants(){
  // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
  chassis.set_drive_constants(10, 1.5, 0, 10, 0);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .42, .03, 3.5, 15);
  chassis.set_swing_constants(12, .3, .001, 2, 15);

  // Each exit condition set is in the form of (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(1.5, 30, 5000);
  chassis.set_turn_exit_conditions(1, 30, 3000);
  chassis.set_swing_exit_conditions(1, 300, 3000);
}

/**
 * Sets constants to be more effective for odom movements.
 * For functions like drive_to_point(), it's often better to have
 * a slower max_voltage and greater settle_error than you would otherwise.
 */

void odom_constants(){
  default_constants();
  chassis.heading_max_voltage = 6;
  chassis.drive_max_voltage = 8;
  chassis.drive_settle_error = 1;
  chassis.boomerang_lead = .5;
  chassis.drive_min_voltage = 0;
}

/* -------------------------------------------------------------------------------------*/
/* SKILLSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
float X_position, float Y_position, float drive_min_voltage, float drive_max_voltage, 
float heading_max_voltage, float drive_settle_error, float drive_settle_time, float drive_timeout
*/
// chassis.drive_stop(vex::hold);
void skills() {




  chassis.set_coordinates(0,0,0);
  

  chassis.drive_to_point(0, 12.5, 0, 8, 8, 10, 0, 2000);
  chassis.turn_to_angle(270, 10, 1, 0, 2000);

  
  chassis.drive_stop(vex::brake);  
}

/* -------------------------------------------------------------------------------------*/

/**
 * The expected behavior is to return to the start position.
 */

void drive_test(){

  chassis.set_coordinates(0,0,0);
  bottomIntake.spin(vex::directionType::fwd, 127, vex::velocityUnits::pct);
  hood.spin(vex::directionType::fwd, 5, vex::velocityUnits::pct);
  //stack
  vex::task matchloadDeployOne([] {
    vex::wait(1100, vex::msec);
    matchloader.set(true);
    return 0;
  });
  chassis.drive_to_point(-7.8, 32.5, 0, 5, 5, 1, 10, 2000);
  chassis.drive_distance(-8);
  stop_intake();
  chassis.turn_to_angle(-134, 6, 1, 2, 2000);
  vex::task middleGo([] {
    middleGoal.set(true);
    vex::wait(450, vex::msec);
    middleGoalDescore.set(true);
    intake_middle_goal();
    return 0;
  });
  chassis.drive_with_voltage(-5, -5);
  vex::wait(500, msec);
  chassis.drive_with_voltage(0, 0);
  vex::wait(1000, msec);
  middleGoal.set(true);
  stop_intake();
  chassis.drive_max_voltage = 6;
  chassis.drive_to_point(-27.6, 10);
  intake_store();
  chassis.turn_to_angle(180);
  matchloader.set(true);
  chassis.drive_with_voltage(8,8);
  vex::wait(900,msec);
  chassis.drive_with_voltage(-8,-8);
  vex::wait(100, msec);
  chassis.drive_with_voltage(12,12);
  vex::wait(350,msec);
  chassis.drive_with_voltage(-8,-8);
  vex::wait(100,msec);
  chassis.drive_with_voltage(0,0);
  chassis.drive_to_point(-29, 15);
  chassis.turn_to_angle(-180);
  vex::task scoreLongGoal([] {
    vex::wait(900, vex::msec);
    intake_long_goal();

    return 0;
  });
  chassis.drive_timeout = 1200;
  chassis.drive_distance(-18);
  vex::wait(500, msec);
  chassis.drive_distance(15);
  vex::wait(10, msec);
  chassis.drive_to_point(-32, 35.5);
  vex::wait(900, msec);
  chassis.drive_with_voltage(0, 0);
  








  

  
}

/**
 * The expected behavior is to return to the start angle, after making a complete turn.
 */

void turn_test(){
  
  chassis.set_coordinates(0,0,0);
  bottomIntake.spin(vex::directionType::fwd, 127, vex::velocityUnits::pct);
  hood.spin(vex::directionType::fwd, 5, vex::velocityUnits::pct);

  //stack
  vex::task matchloadDeployOne([] {
    vex::wait(1100, vex::msec);
    matchloader.set(true);
    return 0;
  });
  chassis.drive_to_point(-7.8, 32.5, 0, 5, 5, 10, 10, 2000);
  chassis.turn_to_angle(-160, 8, 1, 2, 2000);
  chassis.drive_to_point(-26.5, 20, 0,6, 2, 0.5, 0, 2000);
  bottomIntake.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct);
  hood.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct);
  chassis.turn_to_angle(180);
  vex::task scoreLongGoalOne([] {
    vex::wait(400, vex::msec);
    bottomIntake.spin(vex::directionType::fwd, 127, vex::velocityUnits::pct);
    hood.spin(vex::directionType::fwd, -127, vex::velocityUnits::pct);
    return 0;
  });
  chassis.drive_to_point(-28, 28, 0, 8, 2, 10, 0, 4000);
  vex::wait(2000, vex::msec);
  chassis.drive_to_point(-28, 20, 0, 7, 0.1, 10, 0, 4000);
  chassis.turn_to_angle(180, 10, 1, 0, 2000);
  bottomIntake.spin(vex::directionType::fwd, 127, vex::velocityUnits::pct);
  hood.spin(vex::directionType::fwd, 15, vex::velocityUnits::pct);
  chassis.drive_with_voltage(6,6);
  vex::wait(800,msec);
  chassis.drive_with_voltage(-8,-8);
  vex::wait(100, msec);
  chassis.drive_with_voltage(8,8);
  vex::wait(300,msec);
  chassis.drive_with_voltage(-8,-8);
  vex::wait(100,msec);
  chassis.drive_with_voltage(8,8);
  vex::wait(300,msec);
  chassis.drive_with_voltage(-8,-8);
  vex::wait(100,msec);
  chassis.drive_with_voltage(8,8);
  vex::wait(300,msec);
  chassis.drive_with_voltage(-8,-8);
  vex::wait(100,msec);
  vex::task scoreLongGoalTwo([] {
    vex::wait(1000, vex::msec);
    bottomIntake.spin(vex::directionType::fwd, 127, vex::velocityUnits::pct);
    hood.spin(vex::directionType::fwd, -127, vex::velocityUnits::pct);
    return 0;
  });
  chassis.drive_to_point(-28, 22, 0, 8, 0.4, 10, 0, 4000);
  chassis.turn_to_angle(180, 10, 1, 0, 2000);
  chassis.drive_to_point(-28, 28, 0, 8, 0.4, 10, 0, 4000);
  vex::wait(1500, vex::msec);
  chassis.drive_distance(13);
  vex::wait(50,msec);
  chassis.drive_with_voltage(-12,-12);
  vex::wait(900,msec);
  chassis.drive_with_voltage(0,0);
  
}

/**
 * 0,30
turn -90
-6,30
30,40
 */

void swing_test(){
  chassis.set_coordinates(0,0,0);
  vex::task antij([] {
    vex::wait(200, vex::msec);
    anti_jam();
    return 0;
  });
  chassis.drive_max_voltage = 6;
  chassis.drive_distance(32.5);
  bottomIntake.spin(vex::directionType::fwd, -70, vex::velocityUnits::pct);
  chassis.drive_stop(vex::brake);
  vex::wait(300, msec);
  chassis.drive_max_voltage = 4;
  chassis.drive_distance(-6);
  chassis.turn_to_angle(90);
  bottomIntake.spin(vex::directionType::fwd, 127, vex::velocityUnits::pct);
  hood.spin(vex::directionType::fwd, 5, vex::velocityUnits::pct);
  chassis.drive_max_voltage = 6;
  chassis.drive_distance(15);
  chassis.drive_stop(vex::brake);
  vex::task depmat([] {
    vex::wait(200, vex::msec);
    matchloader.set(true);
    return 0;
  });
  chassis.turn_to_angle(150);
  chassis.drive_max_voltage = 6;
  chassis.drive_to_point(25, 25, 0, 7, 2, 10, 0, 4000);
  chassis.drive_to_point(31, 12, 0, 7, 2, 10, 0, 4000);
  chassis.turn_to_angle(180);
  chassis.drive_max_voltage = 6;
  chassis.drive_timeout = 1200;
  chassis.drive_distance(-18.4);
  matchloader.set(false);
  bottomIntake.spin(vex::directionType::fwd, 127, vex::velocityUnits::pct);
  hood.spin(vex::directionType::fwd, -127, vex::velocityUnits::pct);
  vex::wait(1400, vex::msec);
  chassis.drive_distance(15);
  chassis.turn_to_angle(-90);
  bottomIntake.spin(vex::directionType::fwd, 127, vex::velocityUnits::pct);
  hood.spin(vex::directionType::fwd, 5, vex::velocityUnits::pct);
  chassis.drive_to_point(0, 20, -5, 11, 2, 10, 0, 4000);
  chassis.drive_to_point(-25, 20, 0, 7, 2, 10, 0, 4000);
  vex::task depmat2([] {
    vex::wait(200, vex::msec);
    matchloader.set(true);
    return 0;
  });
  chassis.turn_to_angle(180);
  chassis.drive_to_point(-49.8, 15, 0, 7, 2, 10, 0, 4000);
  chassis.turn_to_angle(180, 10, 1, 0, 2000);
  chassis.drive_stop(vex::brake);
  chassis.drive_with_voltage(6,6);
  vex::wait(800,msec);
  chassis.drive_with_voltage(-8,-8);
  vex::wait(100, msec);
  chassis.drive_with_voltage(8,8);
  vex::wait(300,msec);
  chassis.drive_with_voltage(-8,-8);
  vex::wait(100,msec);
  chassis.drive_with_voltage(0,0);
  vex::wait(100,msec);
  chassis.drive_to_point(-55, 15);
  chassis.turn_to_angle(180);
  vex::task score([] {
    vex::wait(500, vex::msec);
    intake_long_goal();
    return 0;
  });
  chassis.drive_distance(-20);





  /*
  chassis.set_coordinates(0,0,0);
  bottomIntake.spin(vex::directionType::fwd, 127, vex::velocityUnits::pct);
  hood.spin(vex::directionType::fwd, 5, vex::velocityUnits::pct);
  chassis.drive_max_voltage = 6;
  chassis.drive_distance(29);
  vex::task matchLoadBar([] {
    vex::wait(100, vex::msec);
    matchloader.set(true);
    return 0;
  });
  chassis.turn_to_angle(-90);
  chassis.drive_max_voltage = 8;
  chassis.drive_with_voltage(8,8);
  vex::wait(1100,msec);
  chassis.drive_with_voltage(-8,-8);
  vex::wait(100, msec);
  vex::task scoreLongGoal([] {
    vex::wait(1300, vex::msec);
    bottomIntake.spin(vex::directionType::fwd, 127, vex::velocityUnits::pct);
    hood.spin(vex::directionType::fwd, -127, vex::velocityUnits::pct);
    return 0;
  });
  chassis.drive_to_point(5, 31.8, 0, 7, 2, 10, 0, 4000);
  chassis.turn_to_angle(-90);
  chassis.drive_timeout = 1400;
  chassis.drive_to_point(29, 31.8, 0, 7, 2, 10, 0, 4000);
  chassis.drive_timeout = 4000;
  vex::wait(1700,msec);
  matchloader.set(false);
  chassis.drive_to_point(20, 30, 0, 9, 0.4, 10, 0, 4000);
  bottomIntake.spin(vex::directionType::fwd, 127, vex::velocityUnits::pct);
  hood.spin(vex::directionType::fwd, 5, vex::velocityUnits::pct);
  chassis.turn_to_angle(160, 10, 1, 1, 2000);
  chassis.drive_to_point(24.5, 14, 0, 5.5, 0.4, 10, 0, 4000);
  matchloader.set(true);
  chassis.turn_max_voltage = 5;
  chassis.turn_to_angle(-43);
  middleGoal.set(true);
  chassis.drive_max_voltage = 8;
  chassis.turn_max_voltage = 8;
  chassis.drive_distance(-15);
  chassis.drive_stop(brake);
  matchloader.set(false);
  bottomIntake.spin(vex::directionType::fwd, 127, vex::velocityUnits::pct);
  hood.spin(vex::directionType::fwd, 5, vex::velocityUnits::pct);
  middleGoal.set(false);
  vex::wait(1600, msec);
  chassis.drive_to_point(23, 10, 0, 10, 0.4, 10, 0, 4000);
  chassis.turn_to_angle(180, 10, 1, 0, 2000);

  chassis.drive_to_point(23, -30, 0, 10, 0.4, 10, 0, 4000);
  vex::task depmat([] {
    vex::wait(100, vex::msec);
    matchloader.set(true);
    return 0;
  });
  chassis.turn_to_angle(180);
  chassis.drive_to_point(17, -36, 0, 5.8, 0.4, 10, 0, 4000);
  chassis.turn_to_angle(-90);

  */


  


  



}

/**
 * A little of this, a little of that; it should end roughly where it started.
 */

void full_test(){
  chassis.drive_distance(24);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(-36);
  chassis.right_swing_to_angle(-90);
  chassis.drive_distance(24);
  chassis.turn_to_angle(0);
}

/**
 * Doesn't drive the robot, but just prints coordinates to the Brain screen 
 * so you can check if they are accurate to life. Push the robot around and
 * see if the coordinates increase like you'd expect.
 */

void odom_test(){
  chassis.set_coordinates(0, 0, 0);
  while(1){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(5,20, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(5,40, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(5,60, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(5,80, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(5,100, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    task::sleep(20);
  }
}

/**
 * Should end in the same place it began, but the second movement
 * will be curved while the first is straight.
 */

void tank_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.turn_to_point(24, 24);
  chassis.drive_to_point(24,24);
  chassis.drive_to_point(0,0);
  chassis.turn_to_angle(0);
}

/**
 * Drives in a square while making a full turn in the process. Should
 * end where it started.
 */

void holonomic_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.holonomic_drive_to_pose(0, 18, 90);
  chassis.holonomic_drive_to_pose(18, 0, 180);
  chassis.holonomic_drive_to_pose(0, 18, 270);
  chassis.holonomic_drive_to_pose(0, 0, 0);
}