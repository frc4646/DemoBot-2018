/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <OI.h>

#include <frc/WPILib.h>
//#include <Joystick.h> //Added Dec 3

using namespace frc;
using namespace wpi;

OI::OI() : leftStick(0), rightStick(1), mechStick(2) {

}
double OI::getLeftStickY(){
	return leftStick.GetRawAxis(1);
}
double OI::getRightStickY(){
	return rightStick.GetRawAxis(1);
}
double OI::getMechStickY(){
	return mechStick.GetRawAxis(1);
}
