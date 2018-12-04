#ifndef DriveTrain_H
#define DriveTrain_H

#include <frc/Commands/Subsystem.h>

//#include <Commands/DriveCommandTeleop.h>

#include <frc/WPILib.h>
#include <frc/Spark.h>

using namespace frc;
using namespace wpi;

class DriveTrain : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Spark leftMini;
	Spark leftRegular;

	Spark rightMini;
	Spark rightRegular;

public:
	DriveTrain();
	void InitDefaultCommand();
	void SetDriveTrainSpeed(double leftSpeed, double rightSpeed);
};

#endif  // DriveTrain_H
