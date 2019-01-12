/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/TalonDriveTrain.h"
#include <RobotMap.h>

#include <commands/DriveCommandTeleop.h>

using namespace frc;

TalonDriveTrain::TalonDriveTrain() : Subsystem("TalonDriveTrain") {
  // rightFront.SetInverted(true);
  //rightBack.SetInverted(true);
  leftBack = new WPI_TalonSRX(3);
  leftFront = new WPI_TalonSRX(1);
  rightFront = new WPI_TalonSRX(2);
  rightBack = new WPI_TalonSRX(4);

}


void TalonDriveTrain::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());

  SetDefaultCommand(new DriveCommandTeleop());

}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void TalonDriveTrain::SetDriveTrainSpeed(double leftSpeed, double rightSpeed){
	leftFront->Set(leftSpeed);
	leftBack->Set(leftSpeed);
  
	rightFront->Set(rightSpeed);
	rightBack->Set(rightSpeed);
}