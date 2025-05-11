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


void Slee5_Auto() {
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
  chassis.pid_drive_set(-19.4_in, 80, true);  //was previously -19.6, 90 
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
  chassis.pid_drive_set(-6_in, DRIVE_SPEED, true); //Previously 7inches  
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

void Slee5_Auto_Hotel_Field() {
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
  chassis.pid_drive_set(-19.4_in, 80, true);  //was previously -19.6, 90 
  chassis.pid_wait();
  MogoClamp.set(true);
  pros::delay(500);
  chassis.pid_drive_set(46_in, DRIVE_SPEED, true);  
  setIntake(105);
  setChain(105);
  chassis.pid_wait_until(24_in); // was 25'
  MogoClamp.set(false);
  chassis.pid_wait_quick_chain();
  setIntake(0);
  setChain(0);
  chassis.pid_drive_set(-5.3_in, DRIVE_SPEED, true); //Previously 7inches then 6' then 5' then 6'
  chassis.pid_wait();
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-43.5_in, 90, true);  
  chassis.pid_wait();
  MogoClamp.set(true);
  pros::delay(500);
  PneumaticArm.set(true);
  setIntake(105);
  setChain(105);

  chassis.pid_drive_set(-7.5_in, DRIVE_SPEED, true);  
  chassis.pid_wait();

  chassis.pid_turn_set(0, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(5.25_in, DRIVE_SPEED, true);  //was 5
  chassis.pid_wait();

  chassis.pid_drive_set(-5.25_in, DRIVE_SPEED, true);  //was 5
  chassis.pid_wait();

  chassis.pid_drive_set(5.75_in, DRIVE_SPEED, true);  //was 5.65
  chassis.pid_wait_until(3.5_in);
  setIntake(0);
  chassis.pid_wait();

  chassis.pid_turn_set(-90, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-30_in, DRIVE_SPEED, true);  
  chassis.pid_wait();

  chassis.pid_turn_set(0, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-10_in, DRIVE_SPEED, true);  
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

void Slee5_Skills() {
  IntakeHolder.set(true); //Unfolding Intake

  setIntake(105);
  setChain(105);


  chassis.pid_drive_set(34_in, 90); 
  chassis.pid_wait_until(26_in);
  setIntake(0);
  setChain(0);
  chassis.pid_wait();

  chassis.pid_turn_set(90_deg, 90);
  chassis.pid_wait();

  chassis.pid_drive_set(-24_in, 90); 
  chassis.pid_wait();
  MogoClamp.set(true);
  setIntake(95);
  setChain(95);

  chassis.pid_turn_set(180_deg, 90);
  chassis.pid_wait();

  chassis.pid_drive_set(4_in, 90); 
  chassis.pid_wait();
  chassis.pid_drive_set(-4_in, 90); 
  chassis.pid_wait();

  chassis.pid_drive_set(24_in, 90); //Uncomment under and put + sign
  chassis.pid_wait();

  chassis.pid_turn_set(-45_deg, 90);
  chassis.pid_wait();

  chassis.pid_drive_set(24_in, 90); 
  chassis.pid_wait();

  chassis.pid_drive_set(-24_in, 90); 
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, 90);
  chassis.pid_wait();

  chassis.pid_turn_relative_set(180_deg, 90);
  chassis.pid_wait();

  chassis.pid_drive_set(24_in, 90); 
  chassis.pid_wait();

  chassis.pid_drive_set(-24_in, 90); 
  chassis.pid_wait();

  chassis.pid_turn_relative_set(180_deg, 90);
  chassis.pid_wait();

  chassis.pid_drive_set(78_in, 90); 
  chassis.pid_wait();

  chassis.pid_drive_set(-108_in, 90); 
  chassis.pid_wait();

  MogoClamp.set(false);







}