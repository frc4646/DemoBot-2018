/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/Commands/Subsystem.h>

#include <frc/WPILib.h>
#include <frc/Spark.h>
using namespace frc;
class FlagWaver : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Spark flagMotor;

public:
	FlagWaver();
	void InitDefaultCommand() override;
	void SetMotorSpeed(double speed);
};

