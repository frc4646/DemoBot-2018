#ifndef DriveCommandTeleop_H
#define DriveCommandTeleop_H

#include <CommandBase.h>
//#include <Subsystems/DriveTrain.h>

#include <frc/WPILib.h>
#include <frc/Spark.h>

using namespace frc;
using namespace wpi;

class DriveCommandTeleop : public CommandBase {

private:
	//Spark shooterMotor;
public:
	DriveCommandTeleop();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveCommandTeleop_H
