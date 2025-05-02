#include "main.h"

//Motors
pros::Motor IntakeMotor(-6,pros::v5::MotorGears::green);
pros::Motor ChainMotor(3,pros::v5::MotorGears::green);
pros::Motor ArmMotor(4,pros::v5::MotorGears::green,pros::v5::MotorUnits::counts);

//Pneumatics
ez::Piston MogoClamp('A',true);