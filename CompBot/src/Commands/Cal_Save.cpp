// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Cal_Save.h"
#include "../RobotMap.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

Cal_Save::Cal_Save(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
	printf("Cal_Save begin\n");
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::sensorPkg.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
    printf("Cal_Save end\n");
}
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void Cal_Save::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void Cal_Save::Execute() {
	//Robot::intake->sensors->StoreCalibration();
}

// Make this return true when this Command no longer needs to run execute()
bool Cal_Save::IsFinished() {
    return true;
}

// Called once after isFinished returns true
void Cal_Save::End() {
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Cal_Save::Interrupted() {

}
