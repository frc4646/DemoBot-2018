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

using namespace frc;

class BellRinger : public frc::Subsystem {
 private:
  Spark bellRingerMotor;

 public:
  BellRinger();
  void InitDefaultCommand() override;
  void SetMotorSpeed(double speed);
};
