#include <commands/DriveCommandTeleop.h>

DriveCommandTeleop::DriveCommandTeleop() : CommandBase("HandleDrive") {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires((frc::Subsystem*) drivetrain.get());
}

// Called just before this Command runs the first time
void DriveCommandTeleop::Initialize() {
	drivetrain->SetDriveTrainSpeed(0.0, 0.0);
}

// Called repeatedly when this Command is scheduled to run
void DriveCommandTeleop::Execute() {
	drivetrain->SetDriveTrainSpeed(oi->getLeftStickY(), oi->getRightStickY());
}

// Make this return true when this Command no longer needs to run execute()
bool DriveCommandTeleop::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveCommandTeleop::End() {
	drivetrain->SetDriveTrainSpeed(0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveCommandTeleop::Interrupted() {

}
