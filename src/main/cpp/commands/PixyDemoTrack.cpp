/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/PixyDemoTrack.h"

PixyDemoTrack::PixyDemoTrack() : CommandBase("PixyDemoTrack") {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires((frc::Subsystem*) pixy.get());
  run = 0;
}

// Called just before this Command runs the first time
void PixyDemoTrack::Initialize() {
  pixy->trackOrangeBall();
}

// Called repeatedly when this Command is scheduled to run
void PixyDemoTrack::Execute() {
  /*
 if(run%2 ==0)
 {
  pixy->trackOrangeBall();
 }

run++;
*/
pixy->trackOrangeBall();
}

// Make this return true when this Command no longer needs to run execute()
bool PixyDemoTrack::IsFinished() { return false; }

// Called once after isFinished returns true
void PixyDemoTrack::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PixyDemoTrack::Interrupted() {}
