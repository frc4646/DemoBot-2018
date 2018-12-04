#include <subsystems/DriveTrain.h>
#include <RobotMap.h>

#include <commands/DriveCommandTeleop.h>

using namespace frc;

DriveTrain::DriveTrain() : Subsystem("DriveTrain"), leftMini(1), leftRegular(0), rightMini(3), rightRegular(2) {
	leftMini.SetSafetyEnabled(false);
	rightMini.SetSafetyEnabled(false);
	leftRegular.SetSafetyEnabled(false);
	rightRegular.SetSafetyEnabled(false);

	rightMini.SetInverted(true);
	rightRegular.SetInverted(true);
}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());

	SetDefaultCommand(new DriveCommandTeleop());

}

void DriveTrain::SetDriveTrainSpeed(double leftSpeed, double rightSpeed){
	leftMini.Set(leftSpeed);
	leftRegular.Set(leftSpeed);

	rightMini.Set(rightSpeed);
	rightRegular.Set(rightSpeed);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
