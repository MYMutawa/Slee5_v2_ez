#include "main.h"

/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// These are out of 127
const int DRIVE_SPEED = 110;
const int TURN_SPEED = 110;
const int SWING_SPEED = 110;

///
// Constants
///
void default_constants() {
  // P, I, D, and Start I
  chassis.pid_drive_constants_set(20.0, 0.0, 100.0);         // Fwd/rev constants, used for odom and non odom motions
  chassis.pid_heading_constants_set(11.0, 0.0, 20.0);        // Holds the robot straight while going forward without odom
  chassis.pid_turn_constants_set(3.0, 0.05, 20.0, 15.0);     // Turn in place constants
  chassis.pid_swing_constants_set(6.0, 0.0, 65.0);           // Swing constants
  chassis.pid_odom_angular_constants_set(6.5, 0.0, 52.5);    // Angular control for odom motions
  chassis.pid_odom_boomerang_constants_set(5.8, 0.0, 32.5);  // Angular control for boomerang motions

  // Exit conditions
  chassis.pid_turn_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_swing_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 500_ms, 500_ms);
  chassis.pid_odom_turn_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 750_ms);
  chassis.pid_odom_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 500_ms, 750_ms);
  chassis.pid_turn_chain_constant_set(3_deg);
  chassis.pid_swing_chain_constant_set(5_deg);
  chassis.pid_drive_chain_constant_set(3_in);

  // Slew constants
  chassis.slew_turn_constants_set(3_deg, 70);
  chassis.slew_drive_constants_set(3_in, 70);
  chassis.slew_swing_constants_set(3_in, 80);

  // The amount that turns are prioritized over driving in odom motions
  // - if you have tracking wheels, you can run this higher.  1.0 is the max
  chassis.odom_turn_bias_set(0.9);

  chassis.odom_look_ahead_set(7_in);           // This is how far ahead in the path the robot looks at
  chassis.odom_boomerang_distance_set(16_in);  // This sets the maximum distance away from target that the carrot point can be
  chassis.odom_boomerang_dlead_set(0.625);     // This handles how aggressive the end of boomerang motions are

  chassis.pid_angle_behavior_set(ez::shortest);  // Changes the default behavior for turning, this defaults it to the shortest path there
}

void drive_48(){
  chassis.pid_drive_set(48_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}
void drive_96(){
  chassis.pid_drive_set(96_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}
void driveBack_48(){
  chassis.pid_drive_set(48_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_drive_set(-48_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}
void driveBack_96(){
  chassis.pid_drive_set(96_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_drive_set(-96_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}
void turn_90(){
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
}
void turn_180(){
  chassis.pid_turn_set(180_deg, TURN_SPEED);
  chassis.pid_wait();
}
void turn_360(){
  chassis.pid_turn_set(360_deg, TURN_SPEED);
  chassis.pid_wait();
}
void turnBack(){
  chassis.pid_turn_set(360_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();
}

void slee5Auto(){
  // Code_distance = 1.8181*distance
  // distancde = code_distance/1.8181
  chassis.pid_drive_set(-31_in, DRIVE_SPEED, true,true);  //task1
  chassis.pid_wait();
  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-24_in, 60, true);  
  chassis.pid_wait();
  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-16_in, DRIVE_SPEED, true);  
  chassis.pid_wait();
  MogoClamp.set(true);
  pros::delay(1000);

  chassis.pid_drive_set(11_in, 70, true);
  chassis.pid_wait();
  setChain(90);               //task2
  pros::delay(2000);

  chassis.pid_drive_set(16.5_in, 80, true); 
  chassis.pid_wait();
  MogoClamp.set(false);
  chassis.pid_drive_set(13_in, 80, true);     //task3
  chassis.pid_wait();
  chassis.pid_turn_set(87_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-11_in, 60, true); 
  chassis.pid_wait();


  chassis.pid_drive_set(-9_in, 35, true);  
  chassis.pid_wait();
  MogoClamp.set(true);
  pros::delay(1000);

  chassis.pid_drive_set(-30_in, 60, true);    //task4
  chassis.pid_wait(); 


  chassis.pid_turn_set(65_deg, TURN_SPEED);
  chassis.pid_wait();
  // pros::delay(2000);
  setChain(90);
  setIntake(90);
  chassis.pid_drive_set(25_in, 60, true); 
  chassis.pid_wait();
  pros::delay(1000);

  chassis.pid_turn_set(100_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(25_in, 60, true); 
  chassis.pid_wait();
  pros::delay(2000);

  // chassis.pid_drive_set(10_in, DRIVE_SPEED, true);
  // chassis.pid_wait();
  // chassis.pid_swing_set(ez::RIGHT_SWING, 90_deg, 110, 0);
  // chassis.pid_wait();
  // setChain(0);
}

void Ladder_MOGO() {
  // The first parameter is ez::LEFT_SWING or ez::RIGHT_SWING
  // The second parameter is the target in degrees
  // The third parameter is the speed of the moving side of the drive
  // The fourth parameter is the speed of the still side of the drive, this allows for wider arcs
  IntakeHolder.set(true);
  chassis.pid_drive_set(-29_in, DRIVE_SPEED, true,true);  //task1
  chassis.pid_wait();
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(19_in, DRIVE_SPEED, true);  
  chassis.pid_wait();
  chassis.pid_turn_set(0, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-19.6_in, 90, true);  
  chassis.pid_wait();
  MogoClamp.set(true);
  pros::delay(500);
  chassis.pid_drive_set(46_in, DRIVE_SPEED, true);  
  setIntake(95);
  setChain(95);
  chassis.pid_wait_until(25_in);
  MogoClamp.set(false);
  chassis.pid_wait_quick_chain();
  setIntake(0);
  setChain(0);
  chassis.pid_drive_set(-7_in, DRIVE_SPEED, true);  
  chassis.pid_wait();
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-44_in, DRIVE_SPEED, true);  
  chassis.pid_wait();
  MogoClamp.set(true);
  pros::delay(500);
  setIntake(95);
  setChain(95);

  chassis.pid_drive_set(-7.5_in, DRIVE_SPEED, true);  
  chassis.pid_wait();

  chassis.pid_turn_set(0, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(5_in, DRIVE_SPEED, true);  
  chassis.pid_wait();

  chassis.pid_drive_set(-5_in, DRIVE_SPEED, true);  
  chassis.pid_wait();

  chassis.pid_turn_set(-90, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-60_in, DRIVE_SPEED, true);  
  chassis.pid_wait();





  // chassis.pid_drive_set(50_in, DRIVE_SPEED, true);  
  // chassis.pid_wait();
  // setIntake(0);
  // setChain(0);
}
// . . .
// Make your own autonomous functions here!
// . . .