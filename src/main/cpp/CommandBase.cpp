#include "CommandBase.h"

#include <frc/Commands/Scheduler.h>


// Initialize a single static instance of all of your subsystems. The following
// line should be repeated for each subsystem in the project.



std::unique_ptr<TalonDriveTrain> CommandBase::drivetrain = NULL;
std::unique_ptr<FlagWaver> CommandBase::flagwaver = NULL;
std::unique_ptr<OI> CommandBase::oi = std::make_unique<OI>();
std::unique_ptr<BellRinger> CommandBase::bellringer = NULL;

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}

void CommandBase::init() {
	drivetrain.reset(new TalonDriveTrain());
	//flagwaver.reset(new FlagWaver());
	bellringer.reset(new BellRinger());

}
