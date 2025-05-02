#include "main.h"

void setIntake(int intakePower) {
    IntakeMotor.move(intakePower);
}

void setChain(int chainPower) {
    ChainMotor.move(chainPower);
}

void setLift(int armPower) {
    ArmMotor.move(armPower);
}

//extern ez::PID liftPID(0.5,0,0,0,"Lift"); //Tune

// void liftWait() {
//     while(liftPID.exit_condition(ArmMotor,true)==ez::RUNNING) {
//     pros::delay(ez::util::DELAY_TIME);
//     }
// }

// void liftTask() {
//     pros::delay(2000);
//     while(true) {
//         setLift(liftPID.compute(ArmMotor.get_position()));
//     }
// }

