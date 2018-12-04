/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <commands/FlagWaveTeleop.h>

FlagWaveTeleop::FlagWaveTeleop() : CommandBase("HandleWave") {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires((frc::Subsystem*) flagwaver.get());
}

// Called just before this Command runs the first time
void FlagWaveTeleop::Initialize() {
	flagwaver->SetMotorSpeed(0.0);
}

// Called repeatedly when this Command is scheduled to run
void FlagWaveTeleop::Execute() {
	flagwaver->SetMotorSpeed(oi->getMechStickY());
}

// Make this return true when this Command no longer needs to run execute()
bool FlagWaveTeleop::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void FlagWaveTeleop::End() {
	flagwaver->SetMotorSpeed(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FlagWaveTeleop::Interrupted() {

}
