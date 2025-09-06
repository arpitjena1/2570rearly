using namespace vex;

extern brain Brain;

//To set up a motor called LeftFront here, you'd use
//extern motor LeftFront;

//Add your devices below, and don't forget to do the same in robot-config.cpp:
//---------------------------------------------------
extern motor leftFront;
extern motor leftTop;
extern motor leftBack;
extern motor rightFront;
extern motor rightTop;
extern motor rightBack;

//---------------------------------------------------
extern motor bottomIntake;
extern motor hood;

//---------------------------------------------------
extern inertial Gyro;
extern rotation R_ForwardTracker;
extern rotation R_SidewaysTracker;
extern optical ballDetect;

//---------------------------------------------------
extern digital_out middleGoal;
extern digital_out matchloader;
extern digital_out leftWing;
extern digital_out rightWing;
extern digital_out middleGoalDescore;

extern controller Controller1;
void  vexcodeInit( void );