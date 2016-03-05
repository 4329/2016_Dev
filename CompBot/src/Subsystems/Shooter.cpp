// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Shooter_Config.h"

#include "Shooter.h"
#include "../RobotMap.h"
#include "../Commands/Shoot.h"


Shooter::Shooter() : Subsystem("Shooter") , Configurable("Shooter") {
    TopTalon    = RobotMap::shooterTopTalon;
    BottomTalon = RobotMap::shooterBottomTalon;

    myConfig = new Shooter_Config;

	if (!ConfigExists()) CreateConfig();

    RetrieveConfig();
	Configure();
    isShooting = false;
}

void Shooter::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    SetDefaultCommand(new Shoot());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

Shooter::~Shooter()
{
	delete myConfig;
}

void Shooter::RetrieveConfig()
{
	myConfig->Shooter_Speed1 = Preferences::GetInstance()->GetFloat("Shooter::Speed1",-5000);
	myConfig->Shooter_Speed2 = Preferences::GetInstance()->GetFloat("Shooter::Speed2",0.75);

	myConfig->Shooter_TopTalon_Enabled = Preferences::GetInstance()->GetBoolean("Shooter::TopTalon::Enabled",true);
	myConfig->Shooter_TopTalon_CANID = Preferences::GetInstance()->GetInt("Shooter::TopTalon::CANID",8);
	myConfig->Shooter_TopTalon_Reversed = Preferences::GetInstance()->GetBoolean("Shooter::TopTalon::Reversed",false);
	myConfig->Shooter_TopTalon_HasSensor = Preferences::GetInstance()->GetBoolean("Shooter::TopTalon::HasSensor",false);
	myConfig->Shooter_TopTalon_SensorReversed = Preferences::GetInstance()->GetBoolean("Shooter::TopTalon::SensorReversed",false);
	myConfig->Shooter_TopTalon_EnablePID = Preferences::GetInstance()->GetBoolean("Shooter::TopTalon::EnablePID",false);
	myConfig->Shooter_TopTalon_EnableVoltRampRate = Preferences::GetInstance()->GetBoolean("Shooter::TopTalon::EnableVoltRampRate",true);
	myConfig->Shooter_TopTalon_VoltRampRate = Preferences::GetInstance()->GetDouble("Shooter::TopTalon::VoltRampRate",4.0);
	myConfig->Shooter_TopTalon_PID_CL_PM_Error = Preferences::GetInstance()->GetInt("Shooter::TopTalon::PID::CL::PM::Error",10);
    myConfig->Shooter_TopTalon_Slaved = Preferences::GetInstance()->GetBoolean("Shooter::TopTalon::Slaved",true);
    myConfig->Shooter_TopTalon_MasterCANID = Preferences::GetInstance()->GetInt("Shooter::TopTalon::MasterCANID",9);

	myConfig->Shooter_BottomTalon_Enabled = Preferences::GetInstance()->GetBoolean("Shooter::BottomTalon::Enabled",true);
	myConfig->Shooter_BottomTalon_CANID = Preferences::GetInstance()->GetInt("Shooter::BottomTalon::CANID",9);
	myConfig->Shooter_BottomTalon_Reversed = Preferences::GetInstance()->GetBoolean("Shooter::BottomTalon::Reversed",false);
	myConfig->Shooter_BottomTalon_HasSensor = Preferences::GetInstance()->GetBoolean("Shooter::BottomTalon::HasSensor",true);
	myConfig->Shooter_BottomTalon_SensorReversed = Preferences::GetInstance()->GetBoolean("Shooter::BottomTalon::SensorReversed",false);
	myConfig->Shooter_BottomTalon_EnablePID = Preferences::GetInstance()->GetBoolean("Shooter::BottomTalon::EnablePID",true);
	myConfig->Shooter_BottomTalon_Profile_0_PID_P = Preferences::GetInstance()->GetDouble("Shooter::BottomTalon::Profile::0::PID::P",1.0);
	myConfig->Shooter_BottomTalon_Profile_0_PID_I = Preferences::GetInstance()->GetDouble("Shooter::BottomTalon::Profile::0::PID::I",0.01);
	myConfig->Shooter_BottomTalon_Profile_0_PID_D = Preferences::GetInstance()->GetDouble("Shooter::BottomTalon::Profile::0::PID::D",0.0);
	myConfig->Shooter_BottomTalon_Profile_0_PID_F = Preferences::GetInstance()->GetDouble("Shooter::BottomTalon::Profile::0::PID::F",0.01);
	myConfig->Shooter_BottomTalon_Profile_0_IZone = Preferences::GetInstance()->GetInt("Shooter::BottomTalon::Profile::0::IZone",256);
	myConfig->Shooter_BottomTalon_Profile_0_EnableCLRampRate = Preferences::GetInstance()->GetBoolean("Shooter::BottomTalon::Profile::0::EnableCLRampRate",false);
	myConfig->Shooter_BottomTalon_Profile_0_CLRampRate = Preferences::GetInstance()->GetDouble("Shooter::BottomTalon::Profile::0::CLRampRate",2500);
	myConfig->Shooter_BottomTalon_EnableVoltRampRate = Preferences::GetInstance()->GetBoolean("Shooter::BottomTalon::EnableVoltRampRate",true);
	myConfig->Shooter_BottomTalon_VoltRampRate = Preferences::GetInstance()->GetDouble("Shooter::BottomTalon::VoltRampRate",4.0);
	myConfig->Shooter_BottomTalon_PID_CL_PM_Error = Preferences::GetInstance()->GetInt("Shooter::BottomTalon::PID::CL::PM::Error",10);
    myConfig->Shooter_BottomTalon_Slaved = Preferences::GetInstance()->GetBoolean("Shooter::BottomTalon::Slaved",false);
    myConfig->Shooter_BottomTalon_MasterCANID = Preferences::GetInstance()->GetInt("Shooter::BottomTalon::MasterCANID",0);

}

void Shooter::Configure()
{
	if (myConfig->Shooter_TopTalon_Enabled)
	{
		printf("S:Configure ST1 enabled\n");
        if (myConfig->Shooter_TopTalon_HasSensor)
        {
    		printf("S:Configure ST1 Has Sensor\n");
        	TopTalon->SetFeedbackDevice(CANTalon::QuadEncoder);
			if (myConfig->Shooter_TopTalon_SensorReversed)
			{
				printf("S:Configure ST1 Sensor Reversed\n");
				TopTalon->SetSensorDirection(true);
			} else
			{
				TopTalon->SetSensorDirection(false);
			}
        }
        if (myConfig->Shooter_TopTalon_EnablePID)
        {
        	printf("S:Configure ST1 PID enabled\n");
        }

		if(myConfig->Shooter_TopTalon_EnableVoltRampRate)
		{
			printf("S:Configure ST1 enable volt ramp rate %f\n",myConfig->Shooter_TopTalon_VoltRampRate);
			TopTalon->SetVoltageRampRate(myConfig->Shooter_TopTalon_VoltRampRate);
		}

		if(myConfig->Shooter_TopTalon_Slaved)
		{
			printf("S:Configure ST1 enable slave %d\n",myConfig->Shooter_TopTalon_MasterCANID);
			TopTalon->SetControlMode(CANSpeedController::kFollower);
			TopTalon->Set(myConfig->Shooter_TopTalon_MasterCANID);
		}
	}

	if (myConfig->Shooter_BottomTalon_Enabled)
	{
		printf("S:Configure ST2 enabled\n");
        if (myConfig->Shooter_BottomTalon_HasSensor)
        {
        	BottomTalon->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
			if (myConfig->Shooter_BottomTalon_SensorReversed)
			{
				BottomTalon->SetSensorDirection(true);
			} else
			{
				BottomTalon->SetSensorDirection(false);
			}
        }
        if (myConfig->Shooter_BottomTalon_EnablePID)
        {
        	printf("S:Configure ST2 PID enabled\n");
        	BottomTalon->SelectProfileSlot(0);
        	BottomTalon->SetP(myConfig->Shooter_BottomTalon_Profile_0_PID_P);
        	BottomTalon->SetI(myConfig->Shooter_BottomTalon_Profile_0_PID_I);
        	BottomTalon->SetD(myConfig->Shooter_BottomTalon_Profile_0_PID_D);
        	BottomTalon->SetF(myConfig->Shooter_BottomTalon_Profile_0_PID_F);
			if (myConfig->Shooter_BottomTalon_Profile_0_EnableCLRampRate)
			{
				BottomTalon->SetCloseLoopRampRate(myConfig->Shooter_BottomTalon_Profile_0_CLRampRate);
			}

			BottomTalon->SetIzone(myConfig->Shooter_BottomTalon_Profile_0_IZone);
        }

		if(myConfig->Shooter_BottomTalon_EnableVoltRampRate)
		{
			printf("S:Configure ST2 enable volt ramp rate %f\n",myConfig->Shooter_BottomTalon_VoltRampRate);
			BottomTalon->SetVoltageRampRate(myConfig->Shooter_BottomTalon_VoltRampRate);
		}
		if(myConfig->Shooter_BottomTalon_Slaved)
		{
			BottomTalon->SetControlMode(CANSpeedController::kFollower);
			BottomTalon->Set(myConfig->Shooter_BottomTalon_MasterCANID);
		}
	}
	BottomTalon->SetControlMode(CANSpeedController::kSpeed);
}

void Shooter::SaveConfig()
{
	Preferences::GetInstance()->PutFloat("Shooter::Speed1",myConfig->Shooter_Speed1);
	Preferences::GetInstance()->PutFloat("Shooter::Speed2",myConfig->Shooter_Speed2);

	Preferences::GetInstance()->PutBoolean("Shooter::TopTalon::Enabled",myConfig->Shooter_TopTalon_Enabled);
	Preferences::GetInstance()->PutInt("Shooter::TopTalon::CANID",myConfig->Shooter_TopTalon_CANID);
	Preferences::GetInstance()->PutBoolean("Shooter::TopTalon::Reversed",myConfig->Shooter_TopTalon_Reversed);
	Preferences::GetInstance()->PutBoolean("Shooter::TopTalon::HasSensor",myConfig->Shooter_TopTalon_HasSensor);
	Preferences::GetInstance()->PutBoolean("Shooter::TopTalon::SensorReversed",myConfig->Shooter_TopTalon_SensorReversed);
	Preferences::GetInstance()->PutBoolean("Shooter::TopTalon::EnablePID",myConfig->Shooter_TopTalon_EnablePID);
	Preferences::GetInstance()->PutBoolean("Shooter::TopTalon::EnableVoltRampRate",myConfig->Shooter_TopTalon_EnableVoltRampRate);
	Preferences::GetInstance()->PutDouble("Shooter::TopTalon::VoltRampRate",myConfig->Shooter_TopTalon_VoltRampRate);
	Preferences::GetInstance()->PutInt("Shooter::TopTalon::PID::CL::PM::Error",myConfig->Shooter_TopTalon_PID_CL_PM_Error);
    Preferences::GetInstance()->PutBoolean("Shooter::TopTalon::Slaved",myConfig->Shooter_TopTalon_Slaved);
    Preferences::GetInstance()->PutInt("Shooter::TopTalon::MasterCANID",myConfig->Shooter_TopTalon_MasterCANID);

	Preferences::GetInstance()->PutBoolean("Shooter::BottomTalon::Enabled",myConfig->Shooter_BottomTalon_Enabled);
	Preferences::GetInstance()->PutInt("Shooter::BottomTalon::CANID",myConfig->Shooter_BottomTalon_CANID);
	Preferences::GetInstance()->PutBoolean("Shooter::BottomTalon::Reversed",myConfig->Shooter_BottomTalon_Reversed);
	Preferences::GetInstance()->PutBoolean("Shooter::BottomTalon::HasSensor",myConfig->Shooter_BottomTalon_HasSensor);
	Preferences::GetInstance()->PutBoolean("Shooter::BottomTalon::SensorReversed",myConfig->Shooter_BottomTalon_SensorReversed);
	Preferences::GetInstance()->PutBoolean("Shooter::BottomTalon::EnablePID",myConfig->Shooter_BottomTalon_EnablePID);
	Preferences::GetInstance()->PutDouble("Shooter::BottomTalon::Profile::0::PID::P",myConfig->Shooter_BottomTalon_Profile_0_PID_P);
	Preferences::GetInstance()->PutDouble("Shooter::BottomTalon::Profile::0::PID::I",myConfig->Shooter_BottomTalon_Profile_0_PID_I);
	Preferences::GetInstance()->PutDouble("Shooter::BottomTalon::Profile::0::PID::D",myConfig->Shooter_BottomTalon_Profile_0_PID_D);
	Preferences::GetInstance()->PutDouble("Shooter::BottomTalon::Profile::0::PID::F",myConfig->Shooter_BottomTalon_Profile_0_PID_F);
	Preferences::GetInstance()->PutInt("Shooter::BottomTalon::Profile::0::IZone",myConfig->Shooter_BottomTalon_Profile_0_IZone);
	Preferences::GetInstance()->PutBoolean("Shooter::BottomTalon::Profile::0::EnableCLRampRate",myConfig->Shooter_BottomTalon_Profile_0_EnableCLRampRate);
	Preferences::GetInstance()->PutDouble("Shooter::BottomTalon::Profile::0::CLRampRate",myConfig->Shooter_BottomTalon_Profile_0_CLRampRate);
	Preferences::GetInstance()->PutBoolean("Shooter::BottomTalon::EnableVoltRampRate",myConfig->Shooter_BottomTalon_EnableVoltRampRate);
	Preferences::GetInstance()->PutDouble("Shooter::BottomTalon::VoltRampRate",myConfig->Shooter_BottomTalon_VoltRampRate);
	Preferences::GetInstance()->PutInt("Shooter::BottomTalon::PID::CL::PM::Error",myConfig->Shooter_BottomTalon_PID_CL_PM_Error);
    Preferences::GetInstance()->PutBoolean("Shooter::BottomTalon::Slaved",myConfig->Shooter_BottomTalon_Slaved);
    Preferences::GetInstance()->PutInt("Shooter::BottomTalon::MasterCANID",myConfig->Shooter_BottomTalon_MasterCANID);

}

void Shooter::CreateConfig()
{
    Preferences::GetInstance()->PutFloat("Shooter::Speed1",-4100.0);
	Preferences::GetInstance()->PutFloat("Shooter::Speed2",0.75);

	Preferences::GetInstance()->PutBoolean("Shooter::TopTalon::Enabled",true);
	Preferences::GetInstance()->PutInt("Shooter::TopTalon::CANID",8);
	Preferences::GetInstance()->PutBoolean("Shooter::TopTalon::Reversed",false);
	Preferences::GetInstance()->PutBoolean("Shooter::TopTalon::HasSensor",false);
	Preferences::GetInstance()->PutBoolean("Shooter::TopTalon::SensorReversed",false);
	Preferences::GetInstance()->PutBoolean("Shooter::TopTalon::EnablePID",false);
	Preferences::GetInstance()->PutBoolean("Shooter::TopTalon::EnableVoltRampRate",true);
	Preferences::GetInstance()->PutDouble("Shooter::TopTalon::VoltRampRate",4.0);
	Preferences::GetInstance()->PutInt("Shooter::TopTalon::PID::CL::PM::Error",10);
    Preferences::GetInstance()->PutBoolean("Shooter::TopTalon::Slaved",true);
    Preferences::GetInstance()->PutInt("Shooter::TopTalon::MasterCANID",9);

	Preferences::GetInstance()->PutBoolean("Shooter::BottomTalon::Enabled",true);
	Preferences::GetInstance()->PutInt("Shooter::BottomTalon::CANID",9);
	Preferences::GetInstance()->PutBoolean("Shooter::BottomTalon::Reversed",false);
	Preferences::GetInstance()->PutBoolean("Shooter::BottomTalon::HasSensor",true);
	Preferences::GetInstance()->PutBoolean("Shooter::BottomTalon::SensorReversed",false);
	Preferences::GetInstance()->PutBoolean("Shooter::BottomTalon::EnablePID",true);
	Preferences::GetInstance()->PutDouble("Shooter::BottomTalon::Profile::0::PID::P",1.0);
	Preferences::GetInstance()->PutDouble("Shooter::BottomTalon::Profile::0::PID::I",0.01);
	Preferences::GetInstance()->PutDouble("Shooter::BottomTalon::Profile::0::PID::D",0.0);
	Preferences::GetInstance()->PutDouble("Shooter::BottomTalon::Profile::0::PID::F",0.01);
	Preferences::GetInstance()->PutInt("Shooter::BottomTalon::Profile::0::IZone",256);
	Preferences::GetInstance()->PutBoolean("Shooter::BottomTalon::Profile::0::EnableCLRampRate",false);
	Preferences::GetInstance()->PutDouble("Shooter::BottomTalon::Profile::0::CLRampRate",2500);
	Preferences::GetInstance()->PutBoolean("Shooter::BottomTalon::EnableVoltRampRate",true);
	Preferences::GetInstance()->PutDouble("Shooter::BottomTalon::VoltRampRate",4.0);
	Preferences::GetInstance()->PutInt("Shooter::BottomTalon::PID::CL::PM::Error",10);
    Preferences::GetInstance()->PutBoolean("Shooter::BottomTalon::Slaved",false);
    Preferences::GetInstance()->PutInt("Shooter::BottomTalon::MasterCANID",0);
}

void Shooter::Fire(float value)
{
	BottomTalon->SetControlMode(CANSpeedController::kSpeed);
    BottomTalon->EnableControl();
	BottomTalon->Set(value);
	tgtRPM = value;
	SmartDashboard::PutNumber("Shooter Firing RPM",tgtRPM);
	isShooting = true;
}

int Shooter::Fire1()
{
	BottomTalon->SetControlMode(CANSpeedController::kSpeed);
	BottomTalon->EnableControl();
	BottomTalon->Set(myConfig->Shooter_Speed1);
	tgtRPM = myConfig->Shooter_Speed1;
	isShooting = true;
	return tgtRPM;
}

int Shooter::Fire2()
{
	BottomTalon->SetControlMode(CANSpeedController::kSpeed);
    BottomTalon->EnableControl();
	BottomTalon->Set(myConfig->Shooter_Speed2);
	tgtRPM = myConfig->Shooter_Speed2;
	isShooting = true;
	return tgtRPM;
}


bool Shooter::AtRPM()
{
	SmartDashboard::PutNumber("Shooter RPM",BottomTalon->GetSpeed());
	if (tgtRPM < 0)
	{
		if (BottomTalon->GetSpeed() <= tgtRPM)
		{
			return true;
		}
	} else
	{
		if (BottomTalon->GetSpeed() >= tgtRPM)
		{
			return true;
		}
	}
	return false;
}

bool Shooter::IsShooting()
{
	return isShooting;
}

void Shooter::Stop()
{
	BottomTalon->Set(0);
	BottomTalon->Disable();
	tgtRPM = 0;
	isShooting = false;
}
