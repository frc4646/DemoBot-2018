/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/BellRinger.h"
#include "commands/BellRingTeleOp.h"

BellRinger::BellRinger() : Subsystem("BellRingerTeleOp"), bellRingerMotor(4) {}

void BellRinger::InitDefaultCommand() {
   SetDefaultCommand(new BellRingTeleOp());
}

void BellRinger::SetMotorSpeed(double speed)
{
    bellRingerMotor.Set(speed);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
