/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/


#include "commands/BellRingTeleOp.h"

BellRingTeleOp::BellRingTeleOp() : CommandBase("BellRinger"){
    Requires((frc::Subsystem*) bellringer.get());
}

// Called just before this Command runs the first time
void BellRingTeleOp::Initialize() {
    bellringer->SetMotorSpeed(0);
}

// Called repeatedly when this Command is scheduled to run
void BellRingTeleOp::Execute() {
  bellringer->SetMotorSpeed(oi->getGamepadTriggers());
}

// Make this return true when this Command no longer needs to run execute()
bool BellRingTeleOp::IsFinished() { return false; }

// Called once after isFinished returns true
void BellRingTeleOp::End() {
   bellringer->SetMotorSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BellRingTeleOp::Interrupted() {}
