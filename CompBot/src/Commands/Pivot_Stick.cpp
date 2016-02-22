// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Pivot_Stick.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

Pivot_Stick::Pivot_Stick(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::intake.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::brake.get());
}
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void Pivot_Stick::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void Pivot_Stick::Execute() {
	axisState = Robot::oi->getOperatorInterface()->Get_AxisState();
	if (axisState.Raw_LY != 0)
	{
		Robot::brake->Release();
		Robot::intake->SetPivot(axisState.Raw_LY);
	} else
	{
		Robot::intake->SetPivot(axisState.Raw_LY);
		Robot::brake->Engage();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool Pivot_Stick::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void Pivot_Stick::End() {
	Robot::intake->StopIntake();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Pivot_Stick::Interrupted() {

}
