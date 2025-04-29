#include "main.h"

void setIntake(int intakePower) {
    IntakeMotor.move(intakePower);
}

void setChain(int chainPower) {
    ChainMotor.move(chainPower);
}