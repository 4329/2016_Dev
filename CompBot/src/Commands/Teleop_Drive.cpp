// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Teleop_Drive.h"

Teleop_Drive::Teleop_Drive(): Command() {
	Requires(Robot::driveTrain.get());
}
// Called just before this Command runs the first time
void Teleop_Drive::Initialize() {
	Robot::driveTrain->LiveConfigure();
	Robot::driveTrain->Set_VoltageMode();
}

// Called repeatedly when this Command is scheduled to run
void Teleop_Drive::Execute() {
	axisState = Robot::oi->getDriverInterface()->Get_AxisState();
	Robot::driveTrain->SetDrive(axisState);

}

// Make this return true when this Command no longer needs to run execute()
bool Teleop_Drive::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void Teleop_Drive::End() {
	Robot::driveTrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Teleop_Drive::Interrupted() {

}
