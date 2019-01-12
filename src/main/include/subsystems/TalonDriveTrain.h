/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/WPILib.h>
#include <frc/Spark.h>
#include <ctre/Phoenix.h>

using namespace frc;

class TalonDriveTrain : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  
  WPI_TalonSRX * rightFront;
	WPI_TalonSRX * rightBack;
	WPI_TalonSRX * leftFront;
	WPI_TalonSRX * leftBack;

 public:
  TalonDriveTrain();
  void InitDefaultCommand();
	void SetDriveTrainSpeed(double leftSpeed, double rightSpeed);
};
