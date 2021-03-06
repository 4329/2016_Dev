// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Autonomous_Simple.h"
#include "../Robot_Config.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

Autonomous_Simple::Autonomous_Simple(): Command() {
        // Use requires() here to declare subsystem dependencies
	printf("Autonomous_Simple Constructor Start\n");
	Requires(Robot::driveTrain.get());
	Throttle = 0.0;

	if (Robot::theConfig.get() != nullptr) {
		printf("Autonomous_Simple AutoConfig Ptr Good\n");
		TimeOut = Robot::theConfig->_AutoCfg.Simple_TimeToRunSecs;
		MaxThrottle = Robot::theConfig->_AutoCfg.Simple_MaxThrottle;
		Throttle_Ramp = Robot::theConfig->_AutoCfg.Simple_ThrottleRamp;
		dist = Robot::theConfig->_AutoCfg.Simple_Distance;
	} else
	{
		printf("Autonomous_Simple AutoConfig Ptr is Null\n");
	}
	first = false;
	hasMoved = false;
	printf("Autonomous_Simple Constructor Complete\n");
}
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void Autonomous_Simple::Initialize() {
	printf("Autonomous_Simple Initialize Start\n");
	Robot::driveTrain->Set_VoltageMode();
	Robot::driveTrain->Zero_DriveEncoders();
	first = false;
	hasMoved = false;
	SetTimeout(TimeOut);
	targetpulses = dist * Robot::driveTrain->Get_PulsesPerInch();
	startingPoint = Robot::driveTrain->Get_CurrentPosition();

	printf("Autonomous_Simple TimeOut = %f MaxThrottle = %f Throttle_Ramp = %f dist = %f\n",TimeOut,MaxThrottle, Throttle_Ramp,dist);
	printf("Autonomous_Simple targetpulses = %f startingPoint = %f\n",targetpulses,startingPoint);
	printf("Autonomous_Simple Initialize Complete\n");
}

// Called repeatedly when this Command is scheduled to run
void Autonomous_Simple::Execute() {
	if (first == false)
	{
		first = true;
		hasMoved = false;
		Robot::driveTrain->Zero_DriveEncoders();
		Throttle = 0.0;
		targetpulses = dist * Robot::driveTrain->Get_PulsesPerInch();
		startingPoint = Robot::driveTrain->Get_CurrentPosition();
	}

	if (dist < 0)
	{
		if (Throttle > (-1 * MaxThrottle) )
		{
			Throttle -= Throttle_Ramp;
		}
	} else
	{
		if (Throttle < MaxThrottle )
		{
			Throttle += Throttle_Ramp;
		}
	}

	Robot::driveTrain->AutoDrive_Move(Throttle);
	printf("Auto_Simple exe Throttle %f \n", Throttle);
}

// Make this return true when this Command no longer needs to run execute()
bool Autonomous_Simple::IsFinished() {
	currentPoint = Robot::driveTrain->Get_CurrentPosition();
	if (currentPoint > targetpulses)
	{
		delta = currentPoint - targetpulses;
	} else
	{
		delta = targetpulses - currentPoint;
	}

	printf("AS IsFinished CP = %f TP = %f delta = %f  lastDelta = %f\n", currentPoint, targetpulses, delta, lastDelta);

	if ((hasMoved == true) && (delta == lastDelta))
	{
		//return true;  // No Movement;
	} else
	{
		//if (delta != abs(targetpulses - currentPoint)) hasMoved = true;
	}

	if ((lastDelta != 0) && (abs(lastDelta) < abs(delta)))
	{
		printf("Returning because target overshot last %f cur %f\n" , lastDelta, delta);
		//return true;
	}

	if (abs(delta) <= allowedError )
	{
		printf("Returning cpos %f tgt %f \n", currentPoint, targetpulses);
		//return true;
	}

	lastDelta = delta;

	printf("Timeout %f\n",TimeOut);
    return IsTimedOut();
}

// Called once after isFinished returns true
void Autonomous_Simple::End() {
	Robot::driveTrain->Stop();
	Throttle = 0.0;
	first = false;
	hasMoved = false;
	printf("Auto_Simple Stop Complete\n");
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Autonomous_Simple::Interrupted() {
	End();
	printf("Auto_Simple Interrupted Complete\n");
}
