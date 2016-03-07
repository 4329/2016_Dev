// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "ConfigUpdate.h"
#include "../RobotMap.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/Intake.h"
#include "Subsystems/Pivot.h"
#include "Subsystems/PDP.h"
#include "Subsystems/Pneumatics.h"
#include "Subsystems/Scaler.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/TargettingAssist.h"
#include "Subsystems/Sensors.h"
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "Subsystems/Brake.h"
#include "Subsystems/Stabilizer.h"
#include "Subsystems/Video.h"


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

ConfigUpdate::ConfigUpdate(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
	Requires(Robot::driveTrain.get());
	Requires(Robot::intake.get());
	Requires(Robot::pivot.get());
	Requires(Robot::shooter.get());
	Requires(Robot::brake.get());
	Requires(Robot::scaler.get());
	Requires(Robot::stabilizer.get());
	Requires(Robot::sensorPkg.get());
	Requires(Robot::video.get());
}
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void ConfigUpdate::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void ConfigUpdate::Execute() {
	Robot::driveTrain->LiveConfigure();
	Robot::intake->LiveConfigure();
	Robot::pivot->LiveConfigure();
	Robot::shooter->LiveConfigure();
	Robot::brake->LiveConfigure();
	Robot::scaler->LiveConfigure();
	Robot::stabilizer->LiveConfigure();
	Robot::sensorPkg->LiveConfigure();
	Robot::video->LiveConfigure();
	Robot::oi->LiveConfigure();
}

// Make this return true when this Command no longer needs to run execute()
bool ConfigUpdate::IsFinished() {
    return true;
}

// Called once after isFinished returns true
void ConfigUpdate::End() {
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ConfigUpdate::Interrupted() {

}
