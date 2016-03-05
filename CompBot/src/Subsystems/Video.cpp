// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "Video.h"
#include "../RobotMap.h"


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES


Video::Video() : Subsystem("Video"), Configurable("Video") {
	FrontQuality = 50;
	RearQuality = 50;

	FrontActive = false;
	FrontEnable = false;
	RearEnable = false;

	FrontName = "cam0";
	RearName  = "cam1";


	if (!ConfigExists()) CreateConfig();

    RetrieveConfig();
	Configure();
}
    
Video::~Video()
{

}

void Video::RetrieveConfig()
{
	FrontQuality = Preferences::GetInstance()->GetFloat(_prefix + prefSep + "Front::Quality",50);
	RearQuality = Preferences::GetInstance()->GetFloat(_prefix + prefSep + "Rear::Quality",50);

	FrontEnable = Preferences::GetInstance()->GetBoolean(_prefix + prefSep + "Front::Enable",true);
	RearEnable = Preferences::GetInstance()->GetBoolean(_prefix + prefSep + "Rear::Enable",true);

	FrontName = Preferences::GetInstance()->GetString(_prefix + prefSep + "Front::Name","cam0");
	RearName = Preferences::GetInstance()->GetString(_prefix + prefSep + "Rear::Name","cam1");
}


void Video::SaveConfig()
{
	Preferences::GetInstance()->PutFloat(_prefix + prefSep + "Front::Quality",FrontQuality);
	Preferences::GetInstance()->PutFloat(_prefix + prefSep + "Rear::Quality",RearQuality);

	Preferences::GetInstance()->PutBoolean(_prefix + prefSep + "Front::Enable",FrontEnable);
	Preferences::GetInstance()->PutBoolean(_prefix + prefSep + "Rear::Enable",RearEnable);

	Preferences::GetInstance()->PutString(_prefix + prefSep + "Front::Name",FrontName);
	Preferences::GetInstance()->PutString(_prefix + prefSep + "Rear::Name",RearName);
}

void Video::Configure()
{
	if (FrontEnable)
	{
		SelectFront();
	} else if (RearEnable)
	{
		SelectRear();
	}
}

void Video::CreateConfig()
{
	Preferences::GetInstance()->GetFloat(_prefix + prefSep + "Front::Quality",50);
	Preferences::GetInstance()->GetFloat(_prefix + prefSep + "Rear::Quality",50);

	Preferences::GetInstance()->GetBoolean(_prefix + prefSep + "Front::Enable",true);
	Preferences::GetInstance()->GetBoolean(_prefix + prefSep + "Rear::Enable",true);

	Preferences::GetInstance()->GetString(_prefix + prefSep + "Front::Name","cam0");
	Preferences::GetInstance()->GetString(_prefix + prefSep + "Rear::Name","cam1");
}


void Video::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Video::ToggleView()
{
	if (FrontActive)
	{
		SelectRear();
	} else
	{
		SelectFront();
	}
}

void Video::SelectFront()
{
	if (FrontEnable)
	{
		CameraServer::GetInstance()->SetQuality(FrontQuality);
		CameraServer::GetInstance()->StartAutomaticCapture(FrontName.c_str());
		FrontActive = true;
	}
}

bool Video::IsFrontSelected()
{
	return FrontActive;
}

void Video::SelectRear()
{
	if (RearEnable)
	{
		CameraServer::GetInstance()->SetQuality(RearQuality);
		CameraServer::GetInstance()->StartAutomaticCapture(RearName.c_str());
		FrontActive = false;
	}
}

bool Video::IsRearSelected()
{
	return !FrontActive;
}

