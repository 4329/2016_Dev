// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Fire.h"
#include "../Robot_Config.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

Fire::Fire(bool pos1): Command() {
	Requires(Robot::shooter.get());
	Requires(Robot::intake.get());
	//Requires(Robot::sensorPkg.get());
    shot = false;
    TimeOut = 5.0;
	hasStalled = false;
	abort = false;
	isPos1 = pos1;
}


// Called just before this Command runs the first time
void Fire::Initialize() {
	TimeOut = Robot::theConfig->_ShooterCfg.Fire_Timeout;
	SetTimeout(TimeOut);
	hasStalled = false;
	abort = false;
	SmartDashboard::PutBoolean("Shot Aborted",false);
}

// Called repeatedly when this Command is scheduled to run
void Fire::Execute() {
	printf("Fire Executing\n");
	float tgt = Robot::shooter->Fire();
	if (!shot) SmartDashboard::PutNumber("Shooter Firing target",tgt);

	int stall = Robot::shooter->Is_Stalling();
	if (stall > 0) SmartDashboard::PutBoolean("Shooter Stalled",true);

	if (stall >= 5)
	{
		if (!hasStalled)
		{
			printf("Shooter stall detected. Expelling ball.\n");
		}
		// If the shooter is stalling
		hasStalled = true;

		// Command the ball away from the shooter.
		Robot::intake->SetIntake(false,Robot::intake->Get_PreFireOut());
	} else
	{
		if (hasStalled)
		{
			// if we detected stalling the last execution,
			// lets see if moving the ball back has resolved the problem.
			if (Robot::shooter->Is_Stalling() <= 0)
			{
				// if no longer stalling then stop the intake.
				Robot::intake->StopIntake();
				hasStalled = false;
				printf("Stall has been resolved. Proceeding with shot.\n");
				SmartDashboard::PutBoolean("Shooter Stalled",false);
			} else
			{
				if (Robot::shooter->Is_Stalling() >= 10)
				{
					// if serious stall abort the shot.
					abort = true;
					printf("Aborting shot due to shooter stall\n");
					SmartDashboard::PutBoolean("Shot Aborted",true);
				}
			}
		}
	}

	if (Robot::shooter->ReadyToFire())
	{
		if (Robot::sensorPkg->RobotHasBall())
		{
			Robot::intake->SetIntake(true);
		}
	}
	shot = true;
}

// Make this return true when this Command no longer needs to run execute()
bool Fire::IsFinished() {
	if (abort) return true;
    if (Robot::sensorPkg->RobotHasBall())
   	{
   	   return false;
   	}
    return true;
}

// Called once after isFinished returns true
void Fire::End() {
	SmartDashboard::PutBoolean("Shooting",false);
	Robot::shooter->Stop();
	Robot::intake->StopIntake();
	shot = false;
	hasStalled = false;
	abort = false;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Fire::Interrupted() {
	End();
}
