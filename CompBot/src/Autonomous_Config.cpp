
#include "Autonomous_Config.h"


Autonomous_Config::Autonomous_Config() : Configurable("Auto")
{
	CheckConfig("Type");
	Configure();
}

Autonomous_Config::~Autonomous_Config()
{

}

void Autonomous_Config::RetrieveConfig()
{
	AutonomousMode_Type = Preferences::GetInstance()->GetInt("Auto::Type",1);
	Simple_MaxThrottle = Preferences::GetInstance()->GetFloat("Auto::Simple::MaxThrottle",0.5);
	Simple_ThrottleRamp = Preferences::GetInstance()->GetFloat("Auto::Simple::ThrottleRamp",0.1);
	Simple_TimeToRunSecs = Preferences::GetInstance()->GetDouble("Auto::Simple::TimeToRunSecs",8.0);
	Simple_Distance = Preferences::GetInstance()->GetDouble("Auto::Simple::Distance",60.0);
	Simple_AllowedError = Preferences::GetInstance()->GetDouble("Auto::Simple::AllowedError",6.0);
}

void Autonomous_Config::SaveConfig()
{
	Preferences::GetInstance()->PutInt("Auto::Type",AutonomousMode_Type);
	Preferences::GetInstance()->PutFloat("Auto::Simple::MaxThrottle",Simple_MaxThrottle);
    Preferences::GetInstance()->PutFloat("Auto::Simple::ThrottleRamp",Simple_ThrottleRamp);
	Preferences::GetInstance()->PutDouble("Auto::Simple::TimeToRunSecs",Simple_TimeToRunSecs);
	Preferences::GetInstance()->PutDouble("Auto::Simple::Distance",Simple_Distance);
	Preferences::GetInstance()->PutDouble("Auto::Simple::AllowedError",Simple_AllowedError);
}

void Autonomous_Config::Configure()
{
	RetrieveConfig();
}

void Autonomous_Config::LiveConfigure()
{
	Configure();
}


void Autonomous_Config::SetAuto(int mode)
{
	Preferences::GetInstance()->PutInt("Auto::Type",mode);
	AutonomousMode_Type = mode;
}

int Autonomous_Config::GetAuto()
{
	return AutonomousMode_Type;
}

void Autonomous_Config::Print_Config()
{
	printf("Auto_Config::Mode Type = %d\n",AutonomousMode_Type);
	printf("Auto_Config::MaxThrottle = %f\n",Simple_MaxThrottle);
	printf("Auto_Config::TimeToRunSecs = %f\n",Simple_TimeToRunSecs);
	printf("Auto_Config::Distance = %f\n",Simple_Distance);
}
