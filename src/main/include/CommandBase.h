
#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <memory>
#include <string>

#include <frc/Commands/Command.h>

#include "OI.h"

#include <subsystems/DriveTrain.h>
#include <subsystems/FlagWaver.h>
#include <subsystems/BellRinger.h>
#include <vision/PixyCamera.h>


/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use
 * CommandBase::exampleSubsystem
 */
class CommandBase : public frc::Command {
public:
	CommandBase(const std::string& name);
	CommandBase() = default;

	static void init();

	// Create a single static instance of all of your subsystems
	static std::unique_ptr<DriveTrain> drivetrain;
	static std::unique_ptr<FlagWaver> flagwaver;
	static std::unique_ptr<PixyCamera> pixy;
	static std::unique_ptr<OI> oi;
	static std::unique_ptr<BellRinger> bellringer;
};

#endif  // COMMAND_BASE_H

