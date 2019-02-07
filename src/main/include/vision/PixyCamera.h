/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "libpixyusb2.h"
#include <PIDLoop.h>
#include <frc/WPILib.h>
#include <frc/commands/Subsystem.h>

using namespace frc;
using namespace wpi;

class PixyCamera : public Subsystem {

  private:
  Pixy2 pixy;
  Servo* pan;
  Servo* tilt;

 public:
  PixyCamera();
  void InitDefaultCommand() override;
  Pixy2 getPixy();
  Block trackOrangeBall();
  Block trackVisionTarget();
  int16_t acquireBlock();
  Block *trackBlock(uint8_t ind);
  int16_t index;
  PIDLoop *panLoop;
  PIDLoop *tiltLoop;

};
