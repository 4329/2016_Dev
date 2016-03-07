// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "Intake.h"
#include "../RobotMap.h"
#include "../Robot.h"


Intake::Intake() : Subsystem("Intake") , Configurable("Intake") {

    intakeTalon = RobotMap::intakeTalon;

    CheckConfig("InSpeed");
	Configure();

}

void Intake::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
	//SetDefaultCommand(new Pivot_Stick());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

Intake::~Intake()
{

}

void Intake::RetrieveConfig()
{
	Intake_InSpeed                  = Preferences::GetInstance()->GetFloat("Intake::InSpeed",-1.0);
	Intake_OutSpeed                 = Preferences::GetInstance()->GetFloat("Intake::OutSpeed",1.0);

	Intake_Talon_Enabled            = Preferences::GetInstance()->GetBoolean("Intake::Talon::Enabled",true);
	Intake_Talon_CANID              = Preferences::GetInstance()->GetInt("Intake::Talon::CANID",5);
	Intake_Talon_Reversed           = Preferences::GetInstance()->GetBoolean("Intake::Talon::Reversed",false);
	Intake_Talon_EnableVoltRampRate = Preferences::GetInstance()->GetBoolean("Intake::Talon::EnableVoltRampRate",false);
	Intake_Talon_VoltRampRate       = Preferences::GetInstance()->GetDouble("Intake::Talon::VoltRampRate",5.0);
}

void Intake::Configure()
{
	if (Intake_Talon_Enabled)
	{
		if(Intake_Talon_EnableVoltRampRate)
		{
			intakeTalon->SetVoltageRampRate(Intake_Talon_VoltRampRate);
		}
	}
}

void Intake::LiveConfigure()
{
	RetrieveConfig();
	Configure();
}


void Intake::SaveConfig()
{
	Preferences::GetInstance()->PutFloat("Intake::InSpeed",Intake_InSpeed);
	Preferences::GetInstance()->PutFloat("Intake::OutSpeed",Intake_OutSpeed);

	Preferences::GetInstance()->PutBoolean("Intake::Talon::Enabled",Intake_Talon_Enabled);
	Preferences::GetInstance()->PutInt("Intake::Talon::CANID",Intake_Talon_CANID);
	Preferences::GetInstance()->PutBoolean("Intake::Talon::Reversed",Intake_Talon_Reversed);
	Preferences::GetInstance()->PutBoolean("Intake::Talon::EnableVoltRampRate",Intake_Talon_EnableVoltRampRate);
	Preferences::GetInstance()->PutDouble("Intake::Talon::VoltRampRate",Intake_Talon_VoltRampRate);
}

/*
void Intake::CreateConfig()
{
	Preferences::GetInstance()->PutFloat("Intake::InSpeed",-1.0);
	Preferences::GetInstance()->PutFloat("Intake::OutSpeed",1.0);

	Preferences::GetInstance()->PutBoolean("Intake::Talon::Enabled",true);
	Preferences::GetInstance()->PutInt("Intake::Talon::CANID",5);
	Preferences::GetInstance()->PutBoolean("Intake::Talon::Reversed",false);
	Preferences::GetInstance()->PutBoolean("Intake::Talon::EnableVoltRampRate",false);
	Preferences::GetInstance()->PutDouble("Intake::Talon::VoltRampRate",5.0);
}

*/

void Intake::SetIntake(bool in, float percent_speed)
{
	if (in)
	{
		intakeTalon->Set(Intake_InSpeed * percent_speed);
	} else
	{
		intakeTalon->Set(Intake_OutSpeed * percent_speed);
	}
}

void Intake::StopIntake()
{
	intakeTalon->Set(0);
}


float Intake::Limit(float num)
{
	if (num > 0.50)
	{
		return 0.50;
	}
	if (num < -0.50)
	{
		return -0.50;
	}
	return num;
}

bool Intake::RobotHasBall()
{
	if (Robot::sensorPkg->RobotHasBall())
	{
		return true;
	}
	return false;
}

bool Intake::IsBallAtShooter()
{
	if (Robot::sensorPkg->IsBallAtShooter())
	{
		return true;
	}
	return false;
}

