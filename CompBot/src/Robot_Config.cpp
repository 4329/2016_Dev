
#include "Robot_Config.h"
#include "Robot.h"

#define Competition_4329



/*enum DriveType
{
	DriveType_Arcade,
	DriveType_Tank,
	DriveType_Split,
	DriveType_end
};
*/

Robot_Config::Robot_Config()
{
	Read_Config();
	Save_Config();
	Print_Config();
	_VideoCfg.StopCapture = false;
}

Robot_Config::~Robot_Config()
{

}

void Robot_Config::Read_Config()
{
	_LogLevel = Preferences::GetInstance()->GetInt("LogLevel",0);
	_CompressorPCMID = 0;
    Read_AutonomousCfg();
    Read_DriveTrainCfg();
    Read_IntakeCfg();
    Read_PivotCfg();
    Read_ScalarCfg();
    Read_SensorCfg();
    Read_ShooterCfg();
    Read_StabilizerCfg();
    Read_XboxCfg();
    Read_VideoCfg();
}

void Robot_Config::Save_Config()
{
	Preferences::GetInstance()->PutInt("LogLevel",_LogLevel);
    Save_AutonomousCfg();
    Save_DriveTrainCfg();
    Save_IntakeCfg();
    Save_PivotCfg();
    Save_ScalarCfg();
    Save_SensorCfg();
    Save_ShooterCfg();
    Save_StabilizerCfg();
    Save_XboxCfg();
    Save_VideoCfg();
}

void Robot_Config::Print_Config()
{
	printf("LogLevel %d\n",_LogLevel);
    Print_AutonomousCfg();
    Print_DriveTrainCfg();
    Print_IntakeCfg();
    Print_PivotCfg();
    Print_ScalarCfg();
    Print_SensorCfg();
    Print_ShooterCfg();
    Print_StabilizerCfg();
    Print_XboxCfg();
    Print_VideoCfg();
}

void Robot_Config::Update_Config(){
	Read_Config();
	Robot::theLogger->Set_LoggingLevel(_LogLevel);
	Save_Config();
	Print_Config();
}

bool Robot_Config::Exists(std::string theKey)
{
	return Preferences::GetInstance()->ContainsKey(theKey);
}

#ifdef Competition_4329
void Robot_Config::Read_AutonomousCfg()
{
	_AutoCfg.AutonomousMode_Type  = Preferences::GetInstance()->GetInt("Auto::Type",1);
	_AutoCfg.Simple_MaxThrottle   = 0.5;
	_AutoCfg.Simple_ThrottleRamp  = 0.1;
	_AutoCfg.Simple_TimeToRunSecs = 8.0;
	_AutoCfg.Simple_Distance      = 60.0;
	_AutoCfg.Simple_AllowedError  = 6.0;
}

void Robot_Config::Save_AutonomousCfg()
{
	Preferences::GetInstance()->PutInt("Auto::Type",_AutoCfg.AutonomousMode_Type);
}
#else
void Robot_Config::Read_AutonomousCfg()
{
	_AutoCfg.AutonomousMode_Type = Preferences::GetInstance()->GetInt("Auto::Type",1);
	_AutoCfg.Simple_MaxThrottle = Preferences::GetInstance()->GetFloat("Auto::Simple::MaxThrottle",0.5);
	_AutoCfg.Simple_ThrottleRamp = Preferences::GetInstance()->GetFloat("Auto::Simple::ThrottleRamp",0.1);
	_AutoCfg.Simple_TimeToRunSecs = Preferences::GetInstance()->GetDouble("Auto::Simple::TimeToRunSecs",8.0);
	_AutoCfg.Simple_Distance = Preferences::GetInstance()->GetDouble("Auto::Simple::Distance",60.0);
	_AutoCfg.Simple_AllowedError = Preferences::GetInstance()->GetDouble("Auto::Simple::AllowedError",6.0);
}

void Robot_Config::Save_AutonomousCfg()
{
	Preferences::GetInstance()->PutInt("Auto::Type",_AutoCfg.AutonomousMode_Type);
	Preferences::GetInstance()->PutFloat("Auto::Simple::MaxThrottle",_AutoCfg.Simple_MaxThrottle);
    Preferences::GetInstance()->PutFloat("Auto::Simple::ThrottleRamp",_AutoCfg.Simple_ThrottleRamp);
	Preferences::GetInstance()->PutDouble("Auto::Simple::TimeToRunSecs",_AutoCfg.Simple_TimeToRunSecs);
	Preferences::GetInstance()->PutDouble("Auto::Simple::Distance",_AutoCfg.Simple_Distance);
	Preferences::GetInstance()->PutDouble("Auto::Simple::AllowedError",_AutoCfg.Simple_AllowedError);
}

#endif

void Robot_Config::Print_AutonomousCfg()
{
	printf("Printing Autonomous Config.\n");
	printf("Auto_Config::Mode Type = %d\n",_AutoCfg.AutonomousMode_Type);
	printf("Auto_Config::MaxThrottle = %f\n",_AutoCfg.Simple_MaxThrottle);
	printf("Auto_Config::TimeToRunSecs = %f\n",_AutoCfg.Simple_TimeToRunSecs);
	printf("Auto_Config::Distance = %f\n",_AutoCfg.Simple_Distance);
}

#ifdef Competition_4329
void Robot_Config::Read_DriveTrainCfg(){
	_DriveCfg.HighSpeed = Preferences::GetInstance()->GetFloat("DriveTrain::HighSpeed",1.0);
	_DriveCfg.LowSpeed  = Preferences::GetInstance()->GetFloat("DriveTrain::LowSpeed",0.75);
	_DriveCfg.QuadEncoder_CodesPerRev = 1024;
	_DriveCfg.InchesPerRotation       = 24;

	_DriveCfg.EnableVoltRampRate      = false;
	_DriveCfg.VoltRampRate            = 5.0;
	_DriveCfg.PID_CL_Allowable_Error  = 50;

	_DriveCfg.Right_Reversed          = false;
	_DriveCfg.Right_SensorReversed    = false;
	_DriveCfg.Right_Profile_0_PID_P   = 1.0;
	_DriveCfg.Right_Profile_0_PID_I   = 0.01;
	_DriveCfg.Right_Profile_0_PID_D   = 0.0;
	_DriveCfg.Right_Profile_0_PID_F   = 0.01;
	_DriveCfg.Right_Profile_0_IZone   = 256;
	_DriveCfg.Right_Profile_0_EnableCLRampRate = false;
	_DriveCfg.Right_Profile_0_CLRampRate       = 2500;
	_DriveCfg.Right_Profile_1_PID_P            = 1.0;
	_DriveCfg.Right_Profile_1_PID_I            = 0.01;
	_DriveCfg.Right_Profile_1_PID_D            = 0.0;
	_DriveCfg.Right_Profile_1_PID_F            = 0.01;
	_DriveCfg.Right_Profile_1_IZone            = 256;
	_DriveCfg.Right_Profile_1_EnableCLRampRate = false;
	_DriveCfg.Right_Profile_1_CLRampRate       = 2500;


	_DriveCfg.RightTalon1_Enabled     = true;
	_DriveCfg.RightTalon1_CANID       = 1;
	_DriveCfg.RightTalon1_HasSensor   = true;
	_DriveCfg.RightTalon1_EnablePID   = true;
    _DriveCfg.RightTalon1_Slaved      = false;
    _DriveCfg.RightTalon1_MasterCANID = 0;

	_DriveCfg.RightTalon2_Enabled     = true;
	_DriveCfg.RightTalon2_CANID       = 2;
	_DriveCfg.RightTalon2_HasSensor   = false;
	_DriveCfg.RightTalon2_EnablePID   = false;
    _DriveCfg.RightTalon2_Slaved      = true;
    _DriveCfg.RightTalon2_MasterCANID = 1;

	_DriveCfg.Left_Reversed        = true;
	_DriveCfg.Left_SensorReversed  = true;
	_DriveCfg.Left_Profile_0_PID_P = 1.0;
	_DriveCfg.Left_Profile_0_PID_I = 0.01;
	_DriveCfg.Left_Profile_0_PID_D = 0;
	_DriveCfg.Left_Profile_0_PID_F = 0.01;
	_DriveCfg.Left_Profile_0_IZone = 256;
	_DriveCfg.Left_Profile_0_EnableCLRampRate = false;
	_DriveCfg.Left_Profile_0_CLRampRate       = 2500;
	_DriveCfg.Left_Profile_1_PID_P = 1;
	_DriveCfg.Left_Profile_1_PID_I = 0.01;
	_DriveCfg.Left_Profile_1_PID_D = 0;
	_DriveCfg.Left_Profile_1_PID_F = 0.01;
	_DriveCfg.Left_Profile_1_IZone = 256;
	_DriveCfg.Left_Profile_1_EnableCLRampRate = false;
	_DriveCfg.Left_Profile_1_CLRampRate       = 2500;


	_DriveCfg.LeftTalon1_Enabled     = true;
	_DriveCfg.LeftTalon1_CANID       = 3;
	_DriveCfg.LeftTalon1_HasSensor   = true;
	_DriveCfg.LeftTalon1_EnablePID   = true;
    _DriveCfg.LeftTalon1_Slaved      = false;
    _DriveCfg.LeftTalon1_MasterCANID = 0;

	_DriveCfg.LeftTalon2_Enabled     = true;
	_DriveCfg.LeftTalon2_CANID       = 4;
	_DriveCfg.LeftTalon2_HasSensor   = false;
	_DriveCfg.LeftTalon2_EnablePID   = false;
    _DriveCfg.LeftTalon2_Slaved      = true;
    _DriveCfg.LeftTalon2_MasterCANID = 3;
    _DriveCfg.DriveType = Preferences::GetInstance()->GetInt("DriveTrain::DriveType",(int)DriveType::DriveType_Split);
}

void Robot_Config::Save_DriveTrainCfg()
{
	Preferences::GetInstance()->PutInt("DriveTrain::DriveType",_DriveCfg.DriveType);
	Preferences::GetInstance()->PutFloat("DriveTrain::HighSpeed",_DriveCfg.HighSpeed);
	Preferences::GetInstance()->PutFloat("DriveTrain::LowSpeed",_DriveCfg.LowSpeed);
}

#else

void Robot_Config::Read_DriveTrainCfg()
{
	_DriveCfg.HighSpeed = Preferences::GetInstance()->GetFloat("DriveTrain::HighSpeed",1.0);
	_DriveCfg.LowSpeed = Preferences::GetInstance()->GetFloat("DriveTrain::LowSpeed",0.75);
	_DriveCfg.QuadEncoder_CodesPerRev = Preferences::GetInstance()->GetInt("DriveTrain::QuadEncoder::CodesPerRev",1024);
	_DriveCfg.InchesPerRotation = Preferences::GetInstance()->GetFloat("DriveTrain::QuadEncoder::InchesPerRotation",24);

	_DriveCfg.EnableVoltRampRate = Preferences::GetInstance()->GetBoolean("DriveTrain::EnableVoltRampRate",false);
	_DriveCfg.VoltRampRate = Preferences::GetInstance()->GetDouble("DriveTrain::VoltRampRate",5.0);
	_DriveCfg.PID_CL_Allowable_Error = Preferences::GetInstance()->GetInt("DriveTrain::PID::CL::Allowable::Error",50);

	_DriveCfg.Right_Reversed = Preferences::GetInstance()->GetBoolean("DriveTrain::Right::Reversed",false);
	_DriveCfg.Right_SensorReversed = Preferences::GetInstance()->GetBoolean("DriveTrain::Right::SensorReversed",false);
	_DriveCfg.Right_Profile_0_PID_P = Preferences::GetInstance()->GetDouble("DriveTrain::Right::Profile::0::PID::P",1.0);
	_DriveCfg.Right_Profile_0_PID_I = Preferences::GetInstance()->GetDouble("DriveTrain::Right::Profile::0::PID::I",0.01);
	_DriveCfg.Right_Profile_0_PID_D = Preferences::GetInstance()->GetDouble("DriveTrain::Right::Profile::0::PID::D",0.0);
	_DriveCfg.Right_Profile_0_PID_F = Preferences::GetInstance()->GetDouble("DriveTrain::Right::Profile::0::PID::F",0.01);
	_DriveCfg.Right_Profile_0_IZone = Preferences::GetInstance()->GetInt("DriveTrain::Right::Profile::0::IZone",256);
	_DriveCfg.Right_Profile_0_EnableCLRampRate = Preferences::GetInstance()->GetBoolean("DriveTrain::Right::Profile::0::EnableCLRampRate",false);
	_DriveCfg.Right_Profile_0_CLRampRate = Preferences::GetInstance()->GetDouble("DriveTrain::Right::Profile::0::CLRampRate",2500);
	_DriveCfg.Right_Profile_1_PID_P = Preferences::GetInstance()->GetDouble("DriveTrain::Right::Profile::1::PID::P",1.0);
	_DriveCfg.Right_Profile_1_PID_I = Preferences::GetInstance()->GetDouble("DriveTrain::Right::Profile::1::PID::I",0.01);
	_DriveCfg.Right_Profile_1_PID_D = Preferences::GetInstance()->GetDouble("DriveTrain::Right::Profile::1::PID::D",0);
	_DriveCfg.Right_Profile_1_PID_F = Preferences::GetInstance()->GetDouble("DriveTrain::Right::Profile::1::PID::F",0.01);
	_DriveCfg.Right_Profile_1_IZone = Preferences::GetInstance()->GetInt("DriveTrain::Right::Profile::1::IZone",256);
	_DriveCfg.Right_Profile_1_EnableCLRampRate = Preferences::GetInstance()->GetBoolean("DriveTrain::Right::Profile::1::EnableCLRampRate",false);
	_DriveCfg.Right_Profile_1_CLRampRate = Preferences::GetInstance()->GetDouble("DriveTrain::Right::Profile::1::CLRampRate",2500);


	_DriveCfg.RightTalon1_Enabled = Preferences::GetInstance()->GetBoolean("DriveTrain::RightTalon1::Enabled",true);
	_DriveCfg.RightTalon1_CANID = Preferences::GetInstance()->GetInt("DriveTrain::RightTalon1::CANID",1);
	_DriveCfg.RightTalon1_HasSensor = Preferences::GetInstance()->GetBoolean("DriveTrain::RightTalon1::HasSensor",true);
	_DriveCfg.RightTalon1_EnablePID = Preferences::GetInstance()->GetBoolean("DriveTrain::RightTalon1::EnablePID",true);
    _DriveCfg.RightTalon1_Slaved = Preferences::GetInstance()->GetBoolean("DriveTrain::RightTalon1::Slaved",false);
    _DriveCfg.RightTalon1_MasterCANID = Preferences::GetInstance()->GetInt("DriveTrain::RightTalon1::MasterCANID",0);

	_DriveCfg.RightTalon2_Enabled = Preferences::GetInstance()->GetBoolean("DriveTrain::RightTalon2::Enabled",true);
	_DriveCfg.RightTalon2_CANID = Preferences::GetInstance()->GetInt("DriveTrain::RightTalon2::CANID",2);
	_DriveCfg.RightTalon2_HasSensor = Preferences::GetInstance()->GetBoolean("DriveTrain::RightTalon2::HasSensor",false);
	_DriveCfg.RightTalon2_EnablePID = Preferences::GetInstance()->GetBoolean("DriveTrain::RightTalon2::EnablePID",false);
    _DriveCfg.RightTalon2_Slaved = Preferences::GetInstance()->GetBoolean("DriveTrain::RightTalon2::Slaved",true);
    _DriveCfg.RightTalon2_MasterCANID = Preferences::GetInstance()->GetInt("DriveTrain::RightTalon2::MasterCANID",1);

	_DriveCfg.Left_Reversed = Preferences::GetInstance()->GetBoolean("DriveTrain::Left::Reversed",true);
	_DriveCfg.Left_SensorReversed = Preferences::GetInstance()->GetBoolean("DriveTrain::Left::SensorReversed",true);
	_DriveCfg.Left_Profile_0_PID_P = Preferences::GetInstance()->GetDouble("DriveTrain::Left::Profile::0::PID::P",1.0);
	_DriveCfg.Left_Profile_0_PID_I = Preferences::GetInstance()->GetDouble("DriveTrain::Left::Profile::0::PID::I",0.01);
	_DriveCfg.Left_Profile_0_PID_D = Preferences::GetInstance()->GetDouble("DriveTrain::Left::Profile::0::PID::D",0);
	_DriveCfg.Left_Profile_0_PID_F = Preferences::GetInstance()->GetDouble("DriveTrain::Left::Profile::0::PID::F",0.01);
	_DriveCfg.Left_Profile_0_IZone = Preferences::GetInstance()->GetInt("DriveTrain::Left::Profile::0::IZone",256);
	_DriveCfg.Left_Profile_0_EnableCLRampRate = Preferences::GetInstance()->GetBoolean("DriveTrain::Left::Profile::0::EnableCLRampRate",false);
	_DriveCfg.Left_Profile_0_CLRampRate = Preferences::GetInstance()->GetDouble("DriveTrain::Left::Profile::0::CLRampRate",2500);
	_DriveCfg.Left_Profile_1_PID_P = Preferences::GetInstance()->GetDouble("DriveTrain::Left::Profile::1::PID::P",1);
	_DriveCfg.Left_Profile_1_PID_I = Preferences::GetInstance()->GetDouble("DriveTrain::Left::Profile::1::PID::I",0.01);
	_DriveCfg.Left_Profile_1_PID_D = Preferences::GetInstance()->GetDouble("DriveTrain::Left::Profile::1::PID::D",0);
	_DriveCfg.Left_Profile_1_PID_F = Preferences::GetInstance()->GetDouble("DriveTrain::Left::Profile::1::PID::F",0.01);
	_DriveCfg.Left_Profile_1_IZone = Preferences::GetInstance()->GetInt("DriveTrain::Left::Profile::1::IZone",256);
	_DriveCfg.Left_Profile_1_EnableCLRampRate = Preferences::GetInstance()->GetBoolean("DriveTrain::Left::Profile::1::EnableCLRampRate",false);
	_DriveCfg.Left_Profile_1_CLRampRate = Preferences::GetInstance()->GetDouble("DriveTrain::Left::Profile::1::CLRampRate",2500);


	_DriveCfg.LeftTalon1_Enabled = Preferences::GetInstance()->GetBoolean("DriveTrain::LeftTalon1::Enabled",true);
	_DriveCfg.LeftTalon1_CANID = Preferences::GetInstance()->GetInt("DriveTrain::LeftTalon1::CANID",3);
	_DriveCfg.LeftTalon1_HasSensor = Preferences::GetInstance()->GetBoolean("DriveTrain::LeftTalon1::HasSensor",true);
	_DriveCfg.LeftTalon1_EnablePID = Preferences::GetInstance()->GetBoolean("DriveTrain::LeftTalon1::EnablePID",true);
    _DriveCfg.LeftTalon1_Slaved = Preferences::GetInstance()->GetBoolean("DriveTrain::LeftTalon1::Slaved",false);
    _DriveCfg.LeftTalon1_MasterCANID = Preferences::GetInstance()->GetInt("DriveTrain::LeftTalon1::MasterCANID",0);

	_DriveCfg.LeftTalon2_Enabled = Preferences::GetInstance()->GetBoolean("DriveTrain::LeftTalon2::Enabled",true);
	_DriveCfg.LeftTalon2_CANID = Preferences::GetInstance()->GetInt("DriveTrain::LeftTalon2::CANID",4);
	_DriveCfg.LeftTalon2_HasSensor = Preferences::GetInstance()->GetBoolean("DriveTrain::LeftTalon2::HasSensor",false);
	_DriveCfg.LeftTalon2_EnablePID = Preferences::GetInstance()->GetBoolean("DriveTrain::LeftTalon2::EnablePID",false);
    _DriveCfg.LeftTalon2_Slaved = Preferences::GetInstance()->GetBoolean("DriveTrain::LeftTalon2::Slaved",true);
    _DriveCfg.LeftTalon2_MasterCANID = Preferences::GetInstance()->GetInt("DriveTrain::LeftTalon2::MasterCANID",3);
    _DriveCfg.DriveType = Preferences::GetInstance()->GetInt("DriveTrain::DriveType",(int)DriveType::DriveType_Split);
};

void Robot_Config::Save_DriveTrainCfg(){
	Preferences::GetInstance()->PutInt("DriveTrain::DriveType",_DriveCfg.DriveType);
	Preferences::GetInstance()->PutFloat("DriveTrain::HighSpeed",_DriveCfg.HighSpeed);
	Preferences::GetInstance()->PutFloat("DriveTrain::LowSpeed",_DriveCfg.LowSpeed);
	Preferences::GetInstance()->PutInt("DriveTrain::QuadEncoder::CodesPerRev",_DriveCfg.QuadEncoder_CodesPerRev);
	Preferences::GetInstance()->PutFloat("DriveTrain::QuadEncoder::InchesPerRotation",_DriveCfg.InchesPerRotation);

	Preferences::GetInstance()->PutBoolean("DriveTrain::EnableVoltRampRate",_DriveCfg.EnableVoltRampRate);
	Preferences::GetInstance()->PutDouble("DriveTrain::VoltRampRate",_DriveCfg.VoltRampRate);
	Preferences::GetInstance()->PutInt("DriveTrain::PID::CL::Allowable::Error",_DriveCfg.PID_CL_Allowable_Error);
	Preferences::GetInstance()->PutBoolean("DriveTrain::Right::Reversed",_DriveCfg.Right_Reversed);
	Preferences::GetInstance()->PutBoolean("DriveTrain::Right::SensorReversed",_DriveCfg.Right_SensorReversed);
	Preferences::GetInstance()->PutDouble("DriveTrain::Right::Profile::0::PID::P",_DriveCfg.Right_Profile_0_PID_P);
	Preferences::GetInstance()->PutDouble("DriveTrain::Right::Profile::0::PID::I",_DriveCfg.Right_Profile_0_PID_I);
	Preferences::GetInstance()->PutDouble("DriveTrain::Right::Profile::0::PID::D",_DriveCfg.Right_Profile_0_PID_D);
	Preferences::GetInstance()->PutDouble("DriveTrain::Right::Profile::0::PID::F",_DriveCfg.Right_Profile_0_PID_F);
	Preferences::GetInstance()->PutInt("DriveTrain::Right::Profile::0::IZone",_DriveCfg.Right_Profile_0_IZone);
	Preferences::GetInstance()->PutBoolean("DriveTrain::Right::Profile::0::EnableCLRampRate",_DriveCfg.Right_Profile_0_EnableCLRampRate);
	Preferences::GetInstance()->PutDouble("DriveTrain::Right::Profile::0::CLRampRate",_DriveCfg.Right_Profile_0_CLRampRate);
	Preferences::GetInstance()->PutDouble("DriveTrain::Right::Profile::1::PID::P",_DriveCfg.Right_Profile_1_PID_P);
	Preferences::GetInstance()->PutDouble("DriveTrain::Right::Profile::1::PID::I",_DriveCfg.Right_Profile_1_PID_I);
	Preferences::GetInstance()->PutDouble("DriveTrain::Right::Profile::1::PID::D",_DriveCfg.Right_Profile_1_PID_D);
	Preferences::GetInstance()->PutDouble("DriveTrain::Right::Profile::1::PID::F",_DriveCfg.Right_Profile_1_PID_F);
	Preferences::GetInstance()->PutInt("DriveTrain::Right::Profile::1::IZone",_DriveCfg.Right_Profile_1_IZone);
	Preferences::GetInstance()->PutBoolean("DriveTrain::Right::Profile::1::EnableCLRampRate",_DriveCfg.Right_Profile_1_EnableCLRampRate);
	Preferences::GetInstance()->PutDouble("DriveTrain::Right::Profile::1::CLRampRate",_DriveCfg.Right_Profile_1_CLRampRate);

	Preferences::GetInstance()->PutBoolean("DriveTrain::RightTalon1::Enabled",_DriveCfg.RightTalon1_Enabled);
	Preferences::GetInstance()->PutInt("DriveTrain::RightTalon1::CANID",_DriveCfg.RightTalon1_CANID);
	Preferences::GetInstance()->PutBoolean("DriveTrain::RightTalon1::HasSensor",_DriveCfg.RightTalon1_HasSensor);
	Preferences::GetInstance()->PutBoolean("DriveTrain::RightTalon1::EnablePID",_DriveCfg.RightTalon1_EnablePID);
    Preferences::GetInstance()->PutBoolean("DriveTrain::RightTalon1::Slaved",_DriveCfg.RightTalon1_Slaved);
    Preferences::GetInstance()->PutInt("DriveTrain::RightTalon1::MasterCANID",_DriveCfg.RightTalon1_MasterCANID);

	Preferences::GetInstance()->PutBoolean("DriveTrain::RightTalon2::Enabled",_DriveCfg.RightTalon2_Enabled);
	Preferences::GetInstance()->PutInt("DriveTrain::RightTalon2::CANID",_DriveCfg.RightTalon2_CANID);
	Preferences::GetInstance()->PutBoolean("DriveTrain::RightTalon2::HasSensor",_DriveCfg.RightTalon2_HasSensor);
	Preferences::GetInstance()->PutBoolean("DriveTrain::RightTalon2::EnablePID",_DriveCfg.RightTalon2_EnablePID);
    Preferences::GetInstance()->PutBoolean("DriveTrain::RightTalon2::Slaved",_DriveCfg.RightTalon2_Slaved);
    Preferences::GetInstance()->PutInt("DriveTrain::RightTalon2::MasterCANID",_DriveCfg.RightTalon2_MasterCANID);

	Preferences::GetInstance()->PutBoolean("DriveTrain::Left::Reversed",_DriveCfg.Left_Reversed);
	Preferences::GetInstance()->PutBoolean("DriveTrain::Left::SensorReversed",_DriveCfg.Left_SensorReversed);
	Preferences::GetInstance()->PutDouble("DriveTrain::Left::Profile::0::PID::P",_DriveCfg.Left_Profile_0_PID_P);
	Preferences::GetInstance()->PutDouble("DriveTrain::Left::Profile::0::PID::I",_DriveCfg.Left_Profile_0_PID_I);
	Preferences::GetInstance()->PutDouble("DriveTrain::Left::Profile::0::PID::D",_DriveCfg.Left_Profile_0_PID_D);
	Preferences::GetInstance()->PutDouble("DriveTrain::Left::Profile::0::PID::F",_DriveCfg.Left_Profile_0_PID_F);
	Preferences::GetInstance()->PutInt("DriveTrain::Left::Profile::0::IZone",_DriveCfg.Left_Profile_0_IZone);
	Preferences::GetInstance()->PutBoolean("DriveTrain::Left::Profile::0::EnableCLRampRate",_DriveCfg.Left_Profile_0_EnableCLRampRate);
	Preferences::GetInstance()->PutDouble("DriveTrain::Left::Profile::0::CLRampRate",_DriveCfg.Left_Profile_0_CLRampRate);
	Preferences::GetInstance()->PutDouble("DriveTrain::Left::Profile::1::PID::P",_DriveCfg.Left_Profile_1_PID_P);
	Preferences::GetInstance()->PutDouble("DriveTrain::Left::Profile::1::PID::I",_DriveCfg.Left_Profile_1_PID_I);
	Preferences::GetInstance()->PutDouble("DriveTrain::Left::Profile::1::PID::D",_DriveCfg.Left_Profile_1_PID_D);
	Preferences::GetInstance()->PutDouble("DriveTrain::Left::Profile::1::PID::F",_DriveCfg.Left_Profile_1_PID_F);
	Preferences::GetInstance()->PutInt("DriveTrain::Left::Profile::1::IZone",_DriveCfg.Left_Profile_1_IZone);
	Preferences::GetInstance()->PutBoolean("DriveTrain::Left::Profile::1::EnableCLRampRate",_DriveCfg.Left_Profile_1_EnableCLRampRate);
	Preferences::GetInstance()->PutDouble("DriveTrain::Left::Profile::1::CLRampRate",_DriveCfg.Left_Profile_1_CLRampRate);

	Preferences::GetInstance()->PutBoolean("DriveTrain::LeftTalon1::Enabled",_DriveCfg.LeftTalon1_Enabled);
	Preferences::GetInstance()->PutInt("DriveTrain::LeftTalon1::CANID",_DriveCfg.LeftTalon1_CANID);
	Preferences::GetInstance()->PutBoolean("DriveTrain::LeftTalon1::HasSensor",_DriveCfg.LeftTalon1_HasSensor);
	Preferences::GetInstance()->PutBoolean("DriveTrain::LeftTalon1::EnablePID",_DriveCfg.LeftTalon1_EnablePID);
    Preferences::GetInstance()->PutBoolean("DriveTrain::LeftTalon1::Slaved",_DriveCfg.LeftTalon1_Slaved);
    Preferences::GetInstance()->PutInt("DriveTrain::LeftTalon1::MasterCANID",_DriveCfg.LeftTalon1_MasterCANID);

	Preferences::GetInstance()->PutBoolean("DriveTrain::LeftTalon2::Enabled",_DriveCfg.LeftTalon2_Enabled);
	Preferences::GetInstance()->PutInt("DriveTrain::LeftTalon2::CANID",_DriveCfg.LeftTalon2_CANID);
	Preferences::GetInstance()->PutBoolean("DriveTrain::LeftTalon2::HasSensor",_DriveCfg.LeftTalon2_HasSensor);
	Preferences::GetInstance()->PutBoolean("DriveTrain::LeftTalon2::EnablePID",_DriveCfg.LeftTalon2_EnablePID);
    Preferences::GetInstance()->PutBoolean("DriveTrain::LeftTalon2::Slaved",_DriveCfg.LeftTalon2_Slaved);
    Preferences::GetInstance()->PutInt("DriveTrain::LeftTalon2::MasterCANID",_DriveCfg.LeftTalon2_MasterCANID);
};

#endif

void Robot_Config::Print_DriveTrainCfg()
{
	printf("Printing DriveTrain Config.\n");
	printf("DriveTrain::DriveType %d\n",_DriveCfg.DriveType);
	printf("DriveTrain::HighSpeed %f\n",_DriveCfg.HighSpeed);
	printf("DriveTrain::LowSpeed %f\n",_DriveCfg.LowSpeed);
	printf("DriveTrain::QuadEncoder::CodesPerRev %d\n",_DriveCfg.QuadEncoder_CodesPerRev);
	printf("DriveTrain::QuadEncoder::InchesPerRotation %f\n",_DriveCfg.InchesPerRotation);

	printf("DriveTrain::EnableVoltRampRate %d\n",_DriveCfg.EnableVoltRampRate);
	printf("DriveTrain::VoltRampRate %f\n",_DriveCfg.VoltRampRate);
	printf("DriveTrain::PID::CL::Allowable::Error %d\n",_DriveCfg.PID_CL_Allowable_Error);
	printf("DriveTrain::Right::Reversed %d\n",_DriveCfg.Right_Reversed);
	printf("DriveTrain::Right::SensorReversed %d\n",_DriveCfg.Right_SensorReversed);
	printf("DriveTrain::Right::Profile::0::PID::P %f\n",_DriveCfg.Right_Profile_0_PID_P);
	printf("DriveTrain::Right::Profile::0::PID::I %f\n",_DriveCfg.Right_Profile_0_PID_I);
	printf("DriveTrain::Right::Profile::0::PID::D %f\n",_DriveCfg.Right_Profile_0_PID_D);
	printf("DriveTrain::Right::Profile::0::PID::F %f\n",_DriveCfg.Right_Profile_0_PID_F);
	printf("DriveTrain::Right::Profile::0::IZone %d\n",_DriveCfg.Right_Profile_0_IZone);
	printf("DriveTrain::Right::Profile::0::EnableCLRampRate %d\n",_DriveCfg.Right_Profile_0_EnableCLRampRate);
	printf("DriveTrain::Right::Profile::0::CLRampRate %f\n",_DriveCfg.Right_Profile_0_CLRampRate);
	printf("DriveTrain::Right::Profile::1::PID::P %f\n",_DriveCfg.Right_Profile_1_PID_P);
	printf("DriveTrain::Right::Profile::1::PID::I %f\n",_DriveCfg.Right_Profile_1_PID_I);
	printf("DriveTrain::Right::Profile::1::PID::D %f\n",_DriveCfg.Right_Profile_1_PID_D);
	printf("DriveTrain::Right::Profile::1::PID::F %f\n",_DriveCfg.Right_Profile_1_PID_F);
	printf("DriveTrain::Right::Profile::1::IZone %d\n",_DriveCfg.Right_Profile_1_IZone);
	printf("DriveTrain::Right::Profile::1::EnableCLRampRate %d\n",_DriveCfg.Right_Profile_1_EnableCLRampRate);
	printf("DriveTrain::Right::Profile::1::CLRampRate %f\n",_DriveCfg.Right_Profile_1_CLRampRate);

	printf("DriveTrain::RightTalon1::Enabled %d\n",_DriveCfg.RightTalon1_Enabled);
	printf("DriveTrain::RightTalon1::CANID %d\n",_DriveCfg.RightTalon1_CANID);
	printf("DriveTrain::RightTalon1::HasSensor %d\n",_DriveCfg.RightTalon1_HasSensor);
	printf("DriveTrain::RightTalon1::EnablePID %d\n",_DriveCfg.RightTalon1_EnablePID);
	printf("DriveTrain::RightTalon1::Slaved %d\n",_DriveCfg.RightTalon1_Slaved);
	printf("DriveTrain::RightTalon1::MasterCANID %d\n",_DriveCfg.RightTalon1_MasterCANID);

	printf("DriveTrain::RightTalon2::Enabled %d\n",_DriveCfg.RightTalon2_Enabled);
	printf("DriveTrain::RightTalon2::CANID %d\n",_DriveCfg.RightTalon2_CANID);
	printf("DriveTrain::RightTalon2::HasSensor %d\n",_DriveCfg.RightTalon2_HasSensor);
	printf("DriveTrain::RightTalon2::EnablePID %d\n",_DriveCfg.RightTalon2_EnablePID);
	printf("DriveTrain::RightTalon2::Slaved %d\n",_DriveCfg.RightTalon2_Slaved);
	printf("DriveTrain::RightTalon2::MasterCANID %d\n",_DriveCfg.RightTalon2_MasterCANID);

	printf("DriveTrain::Left::Reversed %d\n",_DriveCfg.Left_Reversed);
	printf("DriveTrain::Left::SensorReversed %d\n",_DriveCfg.Left_SensorReversed);
	printf("DriveTrain::Left::Profile::0::PID::P %f\n",_DriveCfg.Left_Profile_0_PID_P);
	printf("DriveTrain::Left::Profile::0::PID::I %f\n",_DriveCfg.Left_Profile_0_PID_I);
	printf("DriveTrain::Left::Profile::0::PID::D %f\n",_DriveCfg.Left_Profile_0_PID_D);
	printf("DriveTrain::Left::Profile::0::PID::F %f\n",_DriveCfg.Left_Profile_0_PID_F);
	printf("DriveTrain::Left::Profile::0::IZone %d\n",_DriveCfg.Left_Profile_0_IZone);
	printf("DriveTrain::Left::Profile::0::EnableCLRampRate %d\n",_DriveCfg.Left_Profile_0_EnableCLRampRate);
	printf("DriveTrain::Left::Profile::0::CLRampRate %f\n",_DriveCfg.Left_Profile_0_CLRampRate);
	printf("DriveTrain::Left::Profile::1::PID::P %f\n",_DriveCfg.Left_Profile_1_PID_P);
	printf("DriveTrain::Left::Profile::1::PID::I %f\n",_DriveCfg.Left_Profile_1_PID_I);
	printf("DriveTrain::Left::Profile::1::PID::D %f\n",_DriveCfg.Left_Profile_1_PID_D);
	printf("DriveTrain::Left::Profile::1::PID::F %f\n",_DriveCfg.Left_Profile_1_PID_F);
	printf("DriveTrain::Left::Profile::1::IZone %d\n",_DriveCfg.Left_Profile_1_IZone);
	printf("DriveTrain::Left::Profile::1::EnableCLRampRate %d\n",_DriveCfg.Left_Profile_1_EnableCLRampRate);
	printf("DriveTrain::Left::Profile::1::CLRampRate %f\n",_DriveCfg.Left_Profile_1_CLRampRate);

	printf("DriveTrain::LeftTalon1::Enabled %d\n",_DriveCfg.LeftTalon1_Enabled);
	printf("DriveTrain::LeftTalon1::CANID %d\n",_DriveCfg.LeftTalon1_CANID);
	printf("DriveTrain::LeftTalon1::HasSensor %d\n",_DriveCfg.LeftTalon1_HasSensor);
	printf("DriveTrain::LeftTalon1::EnablePID %d\n",_DriveCfg.LeftTalon1_EnablePID);
	printf("DriveTrain::LeftTalon1::Slaved %d\n",_DriveCfg.LeftTalon1_Slaved);
	printf("DriveTrain::LeftTalon1::MasterCANID %d\n",_DriveCfg.LeftTalon1_MasterCANID);

	printf("DriveTrain::LeftTalon2::Enabled %d\n",_DriveCfg.LeftTalon2_Enabled);
	printf("DriveTrain::LeftTalon2::CANID %d\n",_DriveCfg.LeftTalon2_CANID);
	printf("DriveTrain::LeftTalon2::HasSensor %d\n",_DriveCfg.LeftTalon2_HasSensor);
	printf("DriveTrain::LeftTalon2::EnablePID %d\n",_DriveCfg.LeftTalon2_EnablePID);
	printf("DriveTrain::LeftTalon2::Slaved %d\n",_DriveCfg.LeftTalon2_Slaved);
	printf("DriveTrain::LeftTalon2::MasterCANID %d\n",_DriveCfg.LeftTalon2_MasterCANID);
}

#ifdef Competition_4329
void Robot_Config::Read_IntakeCfg()
{
	_IntakeCfg.InSpeed                  = -1.0;
	_IntakeCfg.OutSpeed                 = 1.0;
	_IntakeCfg.SlowOutSpeed             = Preferences::GetInstance()->GetFloat("Intake::SlowOutSpeed",0.25);
	_IntakeCfg.PreFireOut               = Preferences::GetInstance()->GetFloat("Intake::PreFireOut",0.5);
	_IntakeCfg.Talon_Enabled            = true;
	_IntakeCfg.Talon_CANID              = 5;
	_IntakeCfg.Talon_Reversed           = false;
	_IntakeCfg.Talon_EnableVoltRampRate = false;
	_IntakeCfg.Talon_VoltRampRate       = 5.0;
};

void Robot_Config::Save_IntakeCfg()
{
	Preferences::GetInstance()->PutFloat("Intake::SlowOutSpeed",_IntakeCfg.SlowOutSpeed);
	Preferences::GetInstance()->PutFloat("Intake::PreFireOut",_IntakeCfg.PreFireOut);
}

#else

void Robot_Config::Read_IntakeCfg()
{
	_IntakeCfg.InSpeed                  = Preferences::GetInstance()->GetFloat("Intake::InSpeed",-1.0);
	_IntakeCfg.OutSpeed                 = Preferences::GetInstance()->GetFloat("Intake::OutSpeed",1.0);
	_IntakeCfg.SlowOutSpeed             = Preferences::GetInstance()->GetFloat("Intake::SlowOutSpeed",0.25);
	_IntakeCfg.PreFireOut               = Preferences::GetInstance()->GetFloat("Intake::PreFireOut",0.5);
	_IntakeCfg.Talon_Enabled            = Preferences::GetInstance()->GetBoolean("Intake::Talon::Enabled",true);
	_IntakeCfg.Talon_CANID              = Preferences::GetInstance()->GetInt("Intake::Talon::CANID",5);
	_IntakeCfg.Talon_Reversed           = Preferences::GetInstance()->GetBoolean("Intake::Talon::Reversed",false);
	_IntakeCfg.Talon_EnableVoltRampRate = Preferences::GetInstance()->GetBoolean("Intake::Talon::EnableVoltRampRate",false);
	_IntakeCfg.Talon_VoltRampRate       = Preferences::GetInstance()->GetDouble("Intake::Talon::VoltRampRate",5.0);
};

void Robot_Config::Save_IntakeCfg()
{
	Preferences::GetInstance()->PutFloat("Intake::InSpeed",_IntakeCfg.InSpeed);
	Preferences::GetInstance()->PutFloat("Intake::OutSpeed",_IntakeCfg.OutSpeed);
	Preferences::GetInstance()->PutFloat("Intake::SlowOutSpeed",_IntakeCfg.SlowOutSpeed);
	Preferences::GetInstance()->PutFloat("Intake::PreFireOut",_IntakeCfg.PreFireOut);
	Preferences::GetInstance()->PutBoolean("Intake::Talon::Enabled",_IntakeCfg.Talon_Enabled);
	Preferences::GetInstance()->PutInt("Intake::Talon::CANID",_IntakeCfg.Talon_CANID);
	Preferences::GetInstance()->PutBoolean("Intake::Talon::Reversed",_IntakeCfg.Talon_Reversed);
	Preferences::GetInstance()->PutBoolean("Intake::Talon::EnableVoltRampRate",_IntakeCfg.Talon_EnableVoltRampRate);
	Preferences::GetInstance()->PutDouble("Intake::Talon::VoltRampRate",_IntakeCfg.Talon_VoltRampRate);
}

#endif

void Robot_Config::Print_IntakeCfg()
{
	printf("Printing Intake Config.\n");
	printf("Intake::InSpeed %f\n",_IntakeCfg.InSpeed);
	printf("Intake::OutSpeed%f\n",_IntakeCfg.OutSpeed);
	printf("Intake::SlowOutSpeed%f\n",_IntakeCfg.SlowOutSpeed);
	printf("Intake::PreFireOut%f\n",_IntakeCfg.PreFireOut);
	printf("Intake::Talon::Enabled %d\n",_IntakeCfg.Talon_Enabled);
	printf("Intake::Talon::CANID %d\n",_IntakeCfg.Talon_CANID);
	printf("Intake::Talon::Reversed %d\n",_IntakeCfg.Talon_Reversed);
	printf("Intake::Talon::EnableVoltRampRate %d\n",_IntakeCfg.Talon_EnableVoltRampRate);
	printf("Intake::Talon::VoltRampRate %f\n",_IntakeCfg.Talon_VoltRampRate);
}

#ifdef Competition_4329
void Robot_Config::Read_PivotCfg()
{
	_PivotCfg.PCMID                     = 0;
	_PivotCfg.Stage1_Channel            = 5;
	_PivotCfg.Stage1_ActiveIsExtended   = true;
	_PivotCfg.Stage2_Channel            = 6;
	_PivotCfg.Stage2_ActiveIsExtended   = true;
}

void Robot_Config::Save_PivotCfg()
{

}

#else

void Robot_Config::Read_PivotCfg()
{
	_PivotCfg.PCMID                     = Preferences::GetInstance()->GetInt("Pivot::PCMID",0);
	_PivotCfg.Stage1_Channel            = Preferences::GetInstance()->GetInt("Pivot::Stage1::Channel",5);
	_PivotCfg.Stage1_ActiveIsExtended   = Preferences::GetInstance()->GetBoolean("Pivot::Stage1::ActiveIsExtended",true);
	_PivotCfg.Stage2_Channel            = Preferences::GetInstance()->GetInt("Pivot::Stage2::Channel",6);
	_PivotCfg.Stage2_ActiveIsExtended   = Preferences::GetInstance()->GetBoolean("Pivot::Stage2::ActiveIsExtended",true);
}

void Robot_Config::Save_PivotCfg()
{
	Preferences::GetInstance()->PutInt("Pivot::PCMID",_PivotCfg.PCMID);
	Preferences::GetInstance()->PutInt("Pivot::Stage1::Channel",_PivotCfg.Stage1_Channel);
	Preferences::GetInstance()->PutBoolean("Pivot::Stage1::ActiveIsExtended",_PivotCfg.Stage1_ActiveIsExtended);
	Preferences::GetInstance()->PutInt("Pivot::Stage2::Channel",_PivotCfg.Stage2_Channel);
	Preferences::GetInstance()->PutBoolean("Pivot::Stage2::ActiveIsExtended",_PivotCfg.Stage2_ActiveIsExtended);
}

#endif

void Robot_Config::Print_PivotCfg()
{
	printf("Printing Pivot Config.\n");
	printf("Pivot::PCMID %d\n",_PivotCfg.PCMID);
	printf("Pivot::Stage1::Channel %d\n",_PivotCfg.Stage1_Channel);
	printf("Pivot::Stage1::ActiveIsExtended %d\n",_PivotCfg.Stage1_ActiveIsExtended);
	printf("Pivot::Stage2::Channel %d\n",_PivotCfg.Stage2_Channel);
	printf("Pivot::Stage2::ActiveIsExtended %d\n",_PivotCfg.Stage2_ActiveIsExtended);
}

#ifdef Competition_4329
void Robot_Config::Read_ScalarCfg()
{
	_ScalarCfg.PCMID            = 0;
	_ScalarCfg.Channel          = 0;
	_ScalarCfg.ActiveIsExtended = true;
}

void Robot_Config::Save_ScalarCfg()
{

}

#else
void Robot_Config::Read_ScalarCfg()
{
	_ScalarCfg.PCMID = Preferences::GetInstance()->GetInt("Scalar::PCMID",0);
	_ScalarCfg.Channel = Preferences::GetInstance()->GetInt("Scalar::Channel",0);
	_ScalarCfg.ActiveIsExtended = Preferences::GetInstance()->GetBoolean("Scalar::ActiveIsExtended",true);
}

void Robot_Config::Save_ScalarCfg()
{
	Preferences::GetInstance()->PutInt("Scalar::PCMID",_ScalarCfg.PCMID);
	Preferences::GetInstance()->PutInt("Scalar::Channel",_ScalarCfg.Channel);
	Preferences::GetInstance()->PutBoolean("Scalar::ActiveIsExtended",_ScalarCfg.ActiveIsExtended);
}

#endif

void Robot_Config::Print_ScalarCfg()
{
	printf("Printing Scalar Config.\n");
	printf("Scalar::PCMID %d\n",_ScalarCfg.PCMID);
	printf("Scalar::Channel %d\n",_ScalarCfg.Channel);
	printf("Scalar::ActiveIsExtended  %d\n",_ScalarCfg.ActiveIsExtended);
}


#ifdef Competition_4329
void Robot_Config::Read_SensorCfg()
{
	_SensorCfg.PDP_CANID                           = 0;
	_SensorCfg.Tower_AnalogChannel                 = 1;
	_SensorCfg.Front_AnalogChannel                 = 2;
	_SensorCfg.Shooter_AnalogChannel               = 3;
	_SensorCfg.Pressure_AnalogChannel              = 0;
	_SensorCfg.Tower_distThreshold                 = Preferences::GetInstance()->GetFloat("Sensor::Tower::DistThreshold",0.9792);
	_SensorCfg.Front_distThreshold                 = Preferences::GetInstance()->GetFloat("Sensor::Front::DistThreshold",1.5);
	_SensorCfg.Shooter_distThreshold               = Preferences::GetInstance()->GetFloat("Sensor::Shooter::DistThreshold",1.5);
	_SensorCfg.TowerInRangeRumble                  = Preferences::GetInstance()->GetFloat("Sensor::Tower::InRangeRumble",0.0);
	_SensorCfg._IMUcfg.flipYaw                     = false;
	_SensorCfg._IMUcfg.COLLISION_THRESHOLD_DELTA_G = 1.5;
	_SensorCfg._IMUcfg.MOVE_THRESHOLD_DELTA_MAG    = 1.5;
	_SensorCfg._IMUcfg.ROT_THRESHOLD_DELTA         = 1.5;
}

void Robot_Config::Save_SensorCfg()
{
	Preferences::GetInstance()->PutFloat("Sensor::Tower::DistThreshold",_SensorCfg.Tower_distThreshold);
	Preferences::GetInstance()->PutFloat("Sensor::Front::DistThreshold",_SensorCfg.Front_distThreshold);
	Preferences::GetInstance()->PutFloat("Sensor::Shooter::DistThreshold",_SensorCfg.Shooter_distThreshold);
	Preferences::GetInstance()->PutFloat("Sensor::Tower::InRangeRumble",_SensorCfg.TowerInRangeRumble);
}
#else
void Robot_Config::Read_SensorCfg()
{
	_SensorCfg.PDP_CANID = Preferences::GetInstance()->GetInt("Sensor::PDP::CANID",0);
	_SensorCfg.Tower_AnalogChannel = Preferences::GetInstance()->GetInt("Sensor::Tower::Channel",1);
	_SensorCfg.Front_AnalogChannel = Preferences::GetInstance()->GetInt("Sensor::Front::Channel",2);
	_SensorCfg.Shooter_AnalogChannel = Preferences::GetInstance()->GetInt("Sensor::Shooter::Channel",3);
	_SensorCfg.Pressure_AnalogChannel = Preferences::GetInstance()->GetInt("Sensor::Pressure::Channel",0);
	_SensorCfg.Tower_distThreshold = Preferences::GetInstance()->GetFloat("Sensor::Tower::DistThreshold",0.9792);
	_SensorCfg.Front_distThreshold = Preferences::GetInstance()->GetFloat("Sensor::Front::DistThreshold",1.5);
	_SensorCfg.Shooter_distThreshold = Preferences::GetInstance()->GetFloat("Sensor::Shooter::DistThreshold",1.5);
	_SensorCfg.TowerInRangeRumble = Preferences::GetInstance()->GetFloat("Sensor::Tower::InRangeRumble",0.0);
	_SensorCfg._IMUcfg.flipYaw = Preferences::GetInstance()->GetBoolean("Sensor::IMU::FlipYaw",false);
	_SensorCfg._IMUcfg.COLLISION_THRESHOLD_DELTA_G = Preferences::GetInstance()->GetFloat("Sensor::IMU::ColThreshold_DeltaG",1.5);
	_SensorCfg._IMUcfg.MOVE_THRESHOLD_DELTA_MAG = Preferences::GetInstance()->GetFloat("Sensor::IMU::MoveThreshold_DeltaMag",1.5);
	_SensorCfg._IMUcfg.ROT_THRESHOLD_DELTA = Preferences::GetInstance()->GetFloat("Sensor::IMU::RotThreshold_Delta",1.5);
}

void Robot_Config::Save_SensorCfg()
{
	Preferences::GetInstance()->PutInt("Sensor::PDP::CANID",_SensorCfg.PDP_CANID);
	Preferences::GetInstance()->PutInt("Sensor::Tower::Channel",_SensorCfg.Tower_AnalogChannel);
	Preferences::GetInstance()->PutInt("Sensor::Front::Channel",_SensorCfg.Front_AnalogChannel);
	Preferences::GetInstance()->PutInt("Sensor::Shooter::Channel",_SensorCfg.Shooter_AnalogChannel);
	Preferences::GetInstance()->PutInt("Sensor::Pressure::Channel",_SensorCfg.Pressure_AnalogChannel);
	Preferences::GetInstance()->PutFloat("Sensor::Tower::DistThreshold",_SensorCfg.Tower_distThreshold);
	Preferences::GetInstance()->PutFloat("Sensor::Front::DistThreshold",_SensorCfg.Front_distThreshold);
	Preferences::GetInstance()->PutFloat("Sensor::Shooter::DistThreshold",_SensorCfg.Shooter_distThreshold);
	Preferences::GetInstance()->PutFloat("Sensor::Tower::InRangeRumble",_SensorCfg.TowerInRangeRumble);
    Preferences::GetInstance()->PutFloat("Sensor::IMU::COLLISION_THRESHOLD_DELTA_G",_SensorCfg._IMUcfg.COLLISION_THRESHOLD_DELTA_G);
    Preferences::GetInstance()->PutFloat("Sensor::IMU::MOVE_THRESHOLD_DELTA_MAG",_SensorCfg._IMUcfg.MOVE_THRESHOLD_DELTA_MAG);
    Preferences::GetInstance()->PutFloat("Sensor::IMU::ROT_THRESHOLD_DELTA",_SensorCfg._IMUcfg.ROT_THRESHOLD_DELTA);
    Preferences::GetInstance()->PutBoolean("Sensor::IMU::YawFlipped",_SensorCfg._IMUcfg.flipYaw);
}

#endif

void Robot_Config::Print_SensorCfg()
{
	printf("Printing Sensor Config.\n");
	printf("Sensor::PDP::CANID %d\n",_SensorCfg.PDP_CANID);
	printf("Sensor::Tower::Channel %d\n",_SensorCfg.Tower_AnalogChannel);
	printf("Sensor::Front::Channel %d\n",_SensorCfg.Front_AnalogChannel);
	printf("Sensor::Shooter::Channel %d\n",_SensorCfg.Shooter_AnalogChannel);
	printf("Sensor::Pressure::Channel %d\n",_SensorCfg.Pressure_AnalogChannel);
	printf("Sensor::Tower::DistThreshold %f\n",_SensorCfg.Tower_distThreshold);
	printf("Sensor::Front::DistThreshold %f\n",_SensorCfg.Front_distThreshold);
	printf("Sensor::Shooter::DistThreshold %f\n",_SensorCfg.Shooter_distThreshold);
	printf("Sensor::Tower::InRangeRumble %f\n",_SensorCfg.TowerInRangeRumble);
    printf("Sensor::IMU::COLLISION_THRESHOLD_DELTA_G %f\n",_SensorCfg._IMUcfg.COLLISION_THRESHOLD_DELTA_G);
    printf("Sensor::IMU::MOVE_THRESHOLD_DELTA_MAG %f\n",_SensorCfg._IMUcfg.MOVE_THRESHOLD_DELTA_MAG);
    printf("Sensor::IMU::ROT_THRESHOLD_DELTA %f\n",_SensorCfg._IMUcfg.ROT_THRESHOLD_DELTA);
    printf("Sensor::IMU::YawFlipped %d\n",_SensorCfg._IMUcfg.flipYaw);
}


#ifdef Competition_4329
void Robot_Config::Read_ShooterCfg()
{
	_ShooterCfg.PCMID                    = 0;
	_ShooterCfg.Deflector_Channel        = 1;
	_ShooterCfg.Deflector_ActiveIsFolded = Preferences::GetInstance()->GetBoolean("Shooter::Deflector::ActiveIsFolded",true);
	_ShooterCfg.Speed1                   = Preferences::GetInstance()->GetFloat("Shooter::Speed1",-6000);
	_ShooterCfg.Speed2                   = Preferences::GetInstance()->GetFloat("Shooter::Speed2",-4700);
	_ShooterCfg.PercentVoltage1          = -0.75;
	_ShooterCfg.PercentVoltage2          = -0.75;
	_ShooterCfg.UseSpeed                 = true;
	_ShooterCfg.Fire_Timeout             = Preferences::GetInstance()->GetDouble("Shooter::Fire::Timeout",7.0);
	_ShooterCfg.StallRPM_Threshold       = Preferences::GetInstance()->GetDouble("Shooter::StallRPMthreshold",100.0);

	_ShooterCfg.TopTalon_Enabled = true;
	_ShooterCfg.TopTalon_CANID = 8;
	_ShooterCfg.TopTalon_Reversed = false;
	_ShooterCfg.TopTalon_HasSensor = false;
	_ShooterCfg.TopTalon_SensorReversed = false;
	_ShooterCfg.TopTalon_EnablePID = false;
	_ShooterCfg.TopTalon_EnableVoltRampRate = true;
	_ShooterCfg.TopTalon_VoltRampRate = 8.0;
	_ShooterCfg.TopTalon_PID_CL_PM_Error = 10;
	_ShooterCfg.TopTalon_Slaved = true;
	_ShooterCfg.TopTalon_MasterCANID = 9;

	_ShooterCfg.BottomTalon_Enabled = true;
	_ShooterCfg.BottomTalon_CANID = 9;
	_ShooterCfg.BottomTalon_Reversed = false;
	_ShooterCfg.BottomTalon_HasSensor = true;
	_ShooterCfg.BottomTalon_SensorReversed = false;

	// Calculate Feed forward for the requested RPM to be the baseline motor output.  4096 units per rotation.
	float fgain1,fgain2;
	fgain1 = 1023 / ((fabs(_ShooterCfg.Speed1) / 600 ) * 4096);
	fgain2 = 1023 / ((fabs(_ShooterCfg.Speed2) / 600 ) * 4096);
	_ShooterCfg.BottomTalon_EnablePID = true;
	_ShooterCfg.BottomTalon_Profile_0_PID_P = 0;
	_ShooterCfg.BottomTalon_Profile_0_PID_I = 0;
	_ShooterCfg.BottomTalon_Profile_0_PID_D = 0;
	_ShooterCfg.BottomTalon_Profile_0_PID_F1 = fgain1;
	_ShooterCfg.BottomTalon_Profile_0_PID_F2 = fgain2;
	_ShooterCfg.BottomTalon_PID_CL_PM_Error = ((fabs(_ShooterCfg.Speed1) / 600 ) * 4096)*0.01;

	_ShooterCfg.BottomTalon_Profile_0_IZone = 0;
	_ShooterCfg.BottomTalon_Profile_0_EnableCLRampRate = false;
	_ShooterCfg.BottomTalon_Profile_0_CLRampRate = 2500;
	_ShooterCfg.BottomTalon_EnableVoltRampRate = true;
	_ShooterCfg.BottomTalon_VoltRampRate = 8.0;

	_ShooterCfg.BottomTalon_Slaved = false;
	_ShooterCfg.BottomTalon_MasterCANID = 0;
}

void Robot_Config::Save_ShooterCfg()
{
	Preferences::GetInstance()->PutBoolean("Shooter::Deflector::ActiveIsFolded",_ShooterCfg.Deflector_ActiveIsFolded);
	Preferences::GetInstance()->PutFloat("Shooter::Speed1",_ShooterCfg.Speed1);
	Preferences::GetInstance()->PutFloat("Shooter::Speed2",_ShooterCfg.Speed2);
	Preferences::GetInstance()->PutDouble("Shooter::Fire::Timeout",_ShooterCfg.Fire_Timeout);
	Preferences::GetInstance()->PutDouble("Shooter::StallRPMthreshold",_ShooterCfg.StallRPM_Threshold);
}

#else

void Robot_Config::Read_ShooterCfg()
{
	_ShooterCfg.PCMID                    = Preferences::GetInstance()->GetInt("Shooter::Deflector::PCMID",0);
	_ShooterCfg.Deflector_Channel        = Preferences::GetInstance()->GetInt("Shooter::Deflector::Channel",1);
	_ShooterCfg.Deflector_ActiveIsFolded = Preferences::GetInstance()->GetBoolean("Shooter::Deflector::ActiveIsFolded",true);
	_ShooterCfg.Speed1                   = Preferences::GetInstance()->GetFloat("Shooter::Speed1",-6000);
	_ShooterCfg.Speed2                   = Preferences::GetInstance()->GetFloat("Shooter::Speed2",-4700);
	_ShooterCfg.PercentVoltage1          = Preferences::GetInstance()->GetFloat("Shooter::PercentVoltage1",-0.75);
	_ShooterCfg.PercentVoltage2          = Preferences::GetInstance()->GetFloat("Shooter::PercentVoltage2",-0.75);
	_ShooterCfg.UseSpeed                 = Preferences::GetInstance()->GetBoolean("Shooter::UseSpeed",true);
	_ShooterCfg.Fire_Timeout             = Preferences::GetInstance()->GetDouble("Shooter::Fire::Timeout",7.0);
	_ShooterCfg.StallRPM_Threshold       = Preferences::GetInstance()->GetDouble("Shooter::StallRPMthreshold",100.0);

	_ShooterCfg.TopTalon_Enabled = Preferences::GetInstance()->GetBoolean("Shooter::TopTalon::Enabled",true);
	_ShooterCfg.TopTalon_CANID = Preferences::GetInstance()->GetInt("Shooter::TopTalon::CANID",8);
	_ShooterCfg.TopTalon_Reversed = Preferences::GetInstance()->GetBoolean("Shooter::TopTalon::Reversed",false);
	_ShooterCfg.TopTalon_HasSensor = Preferences::GetInstance()->GetBoolean("Shooter::TopTalon::HasSensor",false);
	_ShooterCfg.TopTalon_SensorReversed = Preferences::GetInstance()->GetBoolean("Shooter::TopTalon::SensorReversed",false);
	_ShooterCfg.TopTalon_EnablePID = Preferences::GetInstance()->GetBoolean("Shooter::TopTalon::EnablePID",false);
	_ShooterCfg.TopTalon_EnableVoltRampRate = Preferences::GetInstance()->GetBoolean("Shooter::TopTalon::EnableVoltRampRate",true);
	_ShooterCfg.TopTalon_VoltRampRate = Preferences::GetInstance()->GetDouble("Shooter::TopTalon::VoltRampRate",8.0);
	_ShooterCfg.TopTalon_PID_CL_PM_Error = Preferences::GetInstance()->GetInt("Shooter::TopTalon::PID::CL::PM::Error",10);
	_ShooterCfg.TopTalon_Slaved = Preferences::GetInstance()->GetBoolean("Shooter::TopTalon::Slaved",true);
	_ShooterCfg.TopTalon_MasterCANID = Preferences::GetInstance()->GetInt("Shooter::TopTalon::MasterCANID",9);

	_ShooterCfg.BottomTalon_Enabled = Preferences::GetInstance()->GetBoolean("Shooter::BottomTalon::Enabled",true);
	_ShooterCfg.BottomTalon_CANID = Preferences::GetInstance()->GetInt("Shooter::BottomTalon::CANID",9);
	_ShooterCfg.BottomTalon_Reversed = Preferences::GetInstance()->GetBoolean("Shooter::BottomTalon::Reversed",false);
	_ShooterCfg.BottomTalon_HasSensor = Preferences::GetInstance()->GetBoolean("Shooter::BottomTalon::HasSensor",true);
	_ShooterCfg.BottomTalon_SensorReversed = Preferences::GetInstance()->GetBoolean("Shooter::BottomTalon::SensorReversed",false);

	// Calculate Feed forward for the requested RPM to be the baseline motor output.  4096 units per rotation.
	float fgain1,fgain2;
	fgain1 = 1023 / ((fabs(_ShooterCfg.Speed1) / 600 ) * 4096);
	fgain2 = 1023 / ((fabs(_ShooterCfg.Speed2) / 600 ) * 4096);
	_ShooterCfg.BottomTalon_EnablePID = true;
	_ShooterCfg.BottomTalon_Profile_0_PID_P = 0;
	_ShooterCfg.BottomTalon_Profile_0_PID_I = 0;
	_ShooterCfg.BottomTalon_Profile_0_PID_D = 0;
	_ShooterCfg.BottomTalon_Profile_0_PID_F1 = fgain1;
	_ShooterCfg.BottomTalon_Profile_0_PID_F2 = fgain2;
	_ShooterCfg.BottomTalon_PID_CL_PM_Error = ((fabs(_ShooterCfg.Speed1) / 600 ) * 4096)*0.01;

	_ShooterCfg.BottomTalon_Profile_0_IZone = Preferences::GetInstance()->GetInt("Shooter::BottomTalon::Profile::0::IZone",0);
	_ShooterCfg.BottomTalon_Profile_0_EnableCLRampRate = Preferences::GetInstance()->GetBoolean("Shooter::BottomTalon::Profile::0::EnableCLRampRate",false);
	_ShooterCfg.BottomTalon_Profile_0_CLRampRate = Preferences::GetInstance()->GetDouble("Shooter::BottomTalon::Profile::0::CLRampRate",2500);
	_ShooterCfg.BottomTalon_EnableVoltRampRate = Preferences::GetInstance()->GetBoolean("Shooter::BottomTalon::EnableVoltRampRate",true);
	_ShooterCfg.BottomTalon_VoltRampRate = Preferences::GetInstance()->GetDouble("Shooter::BottomTalon::VoltRampRate",8.0);

	_ShooterCfg.BottomTalon_Slaved = Preferences::GetInstance()->GetBoolean("Shooter::BottomTalon::Slaved",false);
	_ShooterCfg.BottomTalon_MasterCANID = Preferences::GetInstance()->GetInt("Shooter::BottomTalon::MasterCANID",0);
}

void Robot_Config::Save_ShooterCfg()
{
	Preferences::GetInstance()->PutInt("Shooter::Deflector::PCMID",_ShooterCfg.PCMID);
	Preferences::GetInstance()->PutInt("Shooter::Deflector::Channel",_ShooterCfg.Deflector_Channel);
	Preferences::GetInstance()->PutBoolean("Shooter::Deflector::ActiveIsFolded",_ShooterCfg.Deflector_ActiveIsFolded);

	Preferences::GetInstance()->PutFloat("Shooter::Speed1",_ShooterCfg.Speed1);
	Preferences::GetInstance()->PutFloat("Shooter::Speed2",_ShooterCfg.Speed2);
	Preferences::GetInstance()->PutFloat("Shooter::PercentVoltage1",_ShooterCfg.PercentVoltage1);
	Preferences::GetInstance()->PutFloat("Shooter::PercentVoltage2",_ShooterCfg.PercentVoltage2);
	Preferences::GetInstance()->PutBoolean("Shooter::UseSpeed",_ShooterCfg.UseSpeed);
	Preferences::GetInstance()->PutDouble("Shooter::Fire::Timeout",_ShooterCfg.Fire_Timeout);
	Preferences::GetInstance()->PutDouble("Shooter::StallRPMthreshold",_ShooterCfg.StallRPM_Threshold);

	Preferences::GetInstance()->PutBoolean("Shooter::TopTalon::Enabled",_ShooterCfg.TopTalon_Enabled);
	Preferences::GetInstance()->PutInt("Shooter::TopTalon::CANID",_ShooterCfg.TopTalon_CANID);
	Preferences::GetInstance()->PutBoolean("Shooter::TopTalon::Reversed",_ShooterCfg.TopTalon_Reversed);
	Preferences::GetInstance()->PutBoolean("Shooter::TopTalon::HasSensor",_ShooterCfg.TopTalon_HasSensor);
	Preferences::GetInstance()->PutBoolean("Shooter::TopTalon::SensorReversed",_ShooterCfg.TopTalon_SensorReversed);
	Preferences::GetInstance()->PutBoolean("Shooter::TopTalon::EnablePID",_ShooterCfg.TopTalon_EnablePID);
	Preferences::GetInstance()->PutBoolean("Shooter::TopTalon::EnableVoltRampRate",_ShooterCfg.TopTalon_EnableVoltRampRate);
	Preferences::GetInstance()->PutDouble("Shooter::TopTalon::VoltRampRate",_ShooterCfg.TopTalon_VoltRampRate);
	Preferences::GetInstance()->PutInt("Shooter::TopTalon::PID::CL::PM::Error",_ShooterCfg.TopTalon_PID_CL_PM_Error);
	Preferences::GetInstance()->PutBoolean("Shooter::TopTalon::Slaved",_ShooterCfg.TopTalon_Slaved);
	Preferences::GetInstance()->PutInt("Shooter::TopTalon::MasterCANID",_ShooterCfg.TopTalon_MasterCANID);

	Preferences::GetInstance()->PutBoolean("Shooter::BottomTalon::Enabled",_ShooterCfg.BottomTalon_Enabled);
	Preferences::GetInstance()->PutInt("Shooter::BottomTalon::CANID",_ShooterCfg.BottomTalon_CANID);
	Preferences::GetInstance()->PutBoolean("Shooter::BottomTalon::Reversed",_ShooterCfg.BottomTalon_Reversed);
	Preferences::GetInstance()->PutBoolean("Shooter::BottomTalon::HasSensor",_ShooterCfg.BottomTalon_HasSensor);
	Preferences::GetInstance()->PutBoolean("Shooter::BottomTalon::SensorReversed",_ShooterCfg.BottomTalon_SensorReversed);
	Preferences::GetInstance()->PutBoolean("Shooter::BottomTalon::EnablePID",_ShooterCfg.BottomTalon_EnablePID);
	Preferences::GetInstance()->PutDouble("Shooter::BottomTalon::Profile::0::PID::P",_ShooterCfg.BottomTalon_Profile_0_PID_P);
	Preferences::GetInstance()->PutDouble("Shooter::BottomTalon::Profile::0::PID::I",_ShooterCfg.BottomTalon_Profile_0_PID_I);
	Preferences::GetInstance()->PutDouble("Shooter::BottomTalon::Profile::0::PID::D",_ShooterCfg.BottomTalon_Profile_0_PID_D);
	Preferences::GetInstance()->PutDouble("Shooter::BottomTalon::Profile::0::PID::F1",_ShooterCfg.BottomTalon_Profile_0_PID_F1);
	Preferences::GetInstance()->PutDouble("Shooter::BottomTalon::Profile::0::PID::F2",_ShooterCfg.BottomTalon_Profile_0_PID_F2);
	Preferences::GetInstance()->PutInt("Shooter::BottomTalon::Profile::0::IZone",_ShooterCfg.BottomTalon_Profile_0_IZone);
	Preferences::GetInstance()->PutBoolean("Shooter::BottomTalon::Profile::0::EnableCLRampRate",_ShooterCfg.BottomTalon_Profile_0_EnableCLRampRate);
	Preferences::GetInstance()->PutDouble("Shooter::BottomTalon::Profile::0::CLRampRate",_ShooterCfg.BottomTalon_Profile_0_CLRampRate);
	Preferences::GetInstance()->PutBoolean("Shooter::BottomTalon::EnableVoltRampRate",_ShooterCfg.BottomTalon_EnableVoltRampRate);
	Preferences::GetInstance()->PutDouble("Shooter::BottomTalon::VoltRampRate",_ShooterCfg.BottomTalon_VoltRampRate);
	Preferences::GetInstance()->PutInt("Shooter::BottomTalon::PID::CL::PM::Error",_ShooterCfg.BottomTalon_PID_CL_PM_Error);
	Preferences::GetInstance()->PutBoolean("Shooter::BottomTalon::Slaved",_ShooterCfg.BottomTalon_Slaved);
	Preferences::GetInstance()->PutInt("Shooter::BottomTalon::MasterCANID",_ShooterCfg.BottomTalon_MasterCANID);
}

#endif

void Robot_Config::Print_ShooterCfg()
{
	printf("Printing Shooter Config.\n");
	printf("Shooter::Deflector::PCMID %d\n",_ShooterCfg.PCMID);
	printf("Shooter::Deflector::Channel %d\n",_ShooterCfg.Deflector_Channel);
	printf("Shooter::Deflector::ActiveIsFolded %d\n",_ShooterCfg.Deflector_ActiveIsFolded);
	printf("Shooter::Speed1 %f\n",_ShooterCfg.Speed1);
	printf("Shooter::Speed2 %f\n",_ShooterCfg.Speed2);
	printf("Shooter::PercentVoltage1 %f\n",_ShooterCfg.PercentVoltage1);
	printf("Shooter::PercentVoltage2 %f\n",_ShooterCfg.PercentVoltage2);
	printf("Shooter::UseSpeed %d\n",_ShooterCfg.UseSpeed);
	printf("Shooter::Fire::Timeout %f\n",_ShooterCfg.Fire_Timeout);
	printf("Shooter::StallRPMthreshold %f\n",_ShooterCfg.StallRPM_Threshold);

	printf("Shooter::TopTalon::Enabled %d\n",_ShooterCfg.TopTalon_Enabled);
	printf("Shooter::TopTalon::CANID %d\n",_ShooterCfg.TopTalon_CANID);
	printf("Shooter::TopTalon::Reversed %d\n",_ShooterCfg.TopTalon_Reversed);
	printf("Shooter::TopTalon::HasSensor %d\n",_ShooterCfg.TopTalon_HasSensor);
	printf("Shooter::TopTalon::SensorReversed %d\n",_ShooterCfg.TopTalon_SensorReversed);
	printf("Shooter::TopTalon::EnablePID %d\n",_ShooterCfg.TopTalon_EnablePID);
	printf("Shooter::TopTalon::EnableVoltRampRate %d\n",_ShooterCfg.TopTalon_EnableVoltRampRate);
	printf("Shooter::TopTalon::VoltRampRate %f\n",_ShooterCfg.TopTalon_VoltRampRate);
	printf("Shooter::TopTalon::PID::CL::PM::Error  %d\n",_ShooterCfg.TopTalon_PID_CL_PM_Error);
	printf("Shooter::TopTalon::Slaved  %d\n",_ShooterCfg.TopTalon_Slaved);
	printf("Shooter::TopTalon::MasterCANID  %d\n",_ShooterCfg.TopTalon_MasterCANID);

	printf("Shooter::BottomTalon::Enabled %d\n",_ShooterCfg.BottomTalon_Enabled);
	printf("Shooter::BottomTalon::CANID %d\n",_ShooterCfg.BottomTalon_CANID);
	printf("Shooter::BottomTalon::Reversed %d\n",_ShooterCfg.BottomTalon_Reversed);
	printf("Shooter::BottomTalon::HasSensor %d\n",_ShooterCfg.BottomTalon_HasSensor);
	printf("Shooter::BottomTalon::SensorReversed %d\n",_ShooterCfg.BottomTalon_SensorReversed);
	printf("Shooter::BottomTalon::EnablePID %d\n",_ShooterCfg.BottomTalon_EnablePID);
	printf("Shooter::BottomTalon::Profile::0::PID::P %f\n",_ShooterCfg.BottomTalon_Profile_0_PID_P);
	printf("Shooter::BottomTalon::Profile::0::PID::I %f\n",_ShooterCfg.BottomTalon_Profile_0_PID_I);
	printf("Shooter::BottomTalon::Profile::0::PID::D %f\n",_ShooterCfg.BottomTalon_Profile_0_PID_D);
	printf("Shooter::BottomTalon::Profile::0::PID::F1 %f\n",_ShooterCfg.BottomTalon_Profile_0_PID_F1);
	printf("Shooter::BottomTalon::Profile::0::PID::F2 %f\n",_ShooterCfg.BottomTalon_Profile_0_PID_F2);
	printf("Shooter::BottomTalon::Profile::0::IZone %d\n",_ShooterCfg.BottomTalon_Profile_0_IZone);
	printf("Shooter::BottomTalon::Profile::0::EnableCLRampRate %d\n",_ShooterCfg.BottomTalon_Profile_0_EnableCLRampRate);
	printf("Shooter::BottomTalon::Profile::0::CLRampRate %f\n",_ShooterCfg.BottomTalon_Profile_0_CLRampRate);
	printf("Shooter::BottomTalon::EnableVoltRampRate %d\n",_ShooterCfg.BottomTalon_EnableVoltRampRate);
	printf("Shooter::BottomTalon::VoltRampRate %f\n",_ShooterCfg.BottomTalon_VoltRampRate);
	printf("Shooter::BottomTalon::PID::CL::PM::Error %d\n",_ShooterCfg.BottomTalon_PID_CL_PM_Error);
	printf("Shooter::BottomTalon::Slaved %d\n",_ShooterCfg.BottomTalon_Slaved);
	printf("Shooter::BottomTalon::MasterCANID  %d\n",_ShooterCfg.BottomTalon_MasterCANID);
}

#ifdef Competition_4329
void Robot_Config::Read_StabilizerCfg()
{
	_StabilizerCfg.PCMID             = 0;
	_StabilizerCfg.FwdChannel        = 2;
	_StabilizerCfg.RevChannel        = 3;
	_StabilizerCfg.ForwardIsDeployed = Preferences::GetInstance()->GetBoolean("Stabilizer::ForwardIsDeployed",true);
}

void Robot_Config::Save_StabilizerCfg()
{
	Preferences::GetInstance()->PutBoolean("Stabilizer::ForwardIsDeployed",_StabilizerCfg.ForwardIsDeployed);
}

#else

void Robot_Config::Read_StabilizerCfg()
{
	_StabilizerCfg.PCMID = Preferences::GetInstance()->GetInt("Stabilizer::PCMID",0);
	_StabilizerCfg.FwdChannel = Preferences::GetInstance()->GetInt("Stabilizer::ForwardChannel",2);
	_StabilizerCfg.RevChannel = Preferences::GetInstance()->GetInt("Stabilizer::ReverseChannel",3);
	_StabilizerCfg.ForwardIsDeployed = Preferences::GetInstance()->GetBoolean("Stabilizer::ForwardIsDeployed",true);
}

void Robot_Config::Save_StabilizerCfg()
{
	Preferences::GetInstance()->PutInt("Stabilizer::PCMID",_StabilizerCfg.PCMID);
	Preferences::GetInstance()->PutInt("Stabilizer::ForwardChannel",_StabilizerCfg.FwdChannel);
	Preferences::GetInstance()->PutInt("Stabilizer::ReverseChannel",_StabilizerCfg.RevChannel);
	Preferences::GetInstance()->PutBoolean("Stabilizer::ForwardIsDeployed",_StabilizerCfg.ForwardIsDeployed);
}

#endif

void Robot_Config::Print_StabilizerCfg()
{
	printf("Printing Stabilizer Config.\n");
	printf("Stabilizer::PCMID %d\n",_StabilizerCfg.PCMID);
	printf("Stabilizer::ForwardChannel %d\n",_StabilizerCfg.FwdChannel);
	printf("Stabilizer::ReverseChannel %d\n",_StabilizerCfg.RevChannel);
	printf("Stabilizer::ForwardIsDeployed %d\n",_StabilizerCfg.ForwardIsDeployed);
}

#ifdef Competition_4329
void Robot_Config::Read_XboxCfg()
{
	_DriverXboxCfg.LSxDZ     = 0.05;
	_DriverXboxCfg.LSyDZ     = 0.05;
	_DriverXboxCfg.RSxDZ     = 0.05;
	_DriverXboxCfg.RSyDZ     = 0.05;
	_DriverXboxCfg.LtrigDZ   = 0.05;
	_DriverXboxCfg.RtrigDZ   = 0.05;
	_DriverXboxCfg.axisDelay = 10;
	_DriverXboxCfg.flipRSy   = true;
	_DriverXboxCfg.flipLSy   = true;
	_DriverXboxCfg.flipRSx   = false;
	_DriverXboxCfg.flipLSx   = false;

	_OperatorXboxCfg.LSxDZ     = 0.05;
	_OperatorXboxCfg.LSyDZ     = 0.05;
	_OperatorXboxCfg.RSxDZ     = 0.05;
	_OperatorXboxCfg.RSyDZ     = 0.05;
	_OperatorXboxCfg.LtrigDZ   = 0.05;
	_OperatorXboxCfg.RtrigDZ   = 0.05;
	_OperatorXboxCfg.axisDelay = 10;
	_OperatorXboxCfg.flipRSy   = true;
	_OperatorXboxCfg.flipLSy   = true;
	_OperatorXboxCfg.flipRSx   = false;
	_OperatorXboxCfg.flipLSx   = false;
}

void Robot_Config::Save_XboxCfg()
{

}

#else
void Robot_Config::Read_XboxCfg()
{
	_DriverXboxCfg.LSxDZ = Preferences::GetInstance()->GetFloat("Driver::XBox::DeadZone::LeftStick::X",0.05);
	_DriverXboxCfg.LSyDZ = Preferences::GetInstance()->GetFloat("Driver::XBox::DeadZone::LeftStick::Y",0.05);
	_DriverXboxCfg.RSxDZ = Preferences::GetInstance()->GetFloat("Driver::XBox::DeadZone::RightStick::X",0.05);
	_DriverXboxCfg.RSyDZ = Preferences::GetInstance()->GetFloat("Driver::XBox::DeadZone::RightStick::Y",0.05);
	_DriverXboxCfg.LtrigDZ = Preferences::GetInstance()->GetFloat("Driver::XBox::DeadZone::LeftTrigger",0.05);
	_DriverXboxCfg.RtrigDZ = Preferences::GetInstance()->GetFloat("Driver::XBox::DeadZone::RightTrigger",0.05);
	_DriverXboxCfg.axisDelay = Preferences::GetInstance()->GetInt("Driver::XBox::AxisDelay",10);
	_DriverXboxCfg.flipRSy = Preferences::GetInstance()->GetBoolean("Driver::XBox::RightStick::YInverted",true);
	_DriverXboxCfg.flipLSy = Preferences::GetInstance()->GetBoolean("Driver::XBox::LeftStick::YInverted",true);
	_DriverXboxCfg.flipRSx = Preferences::GetInstance()->GetBoolean("Driver::XBox::RightStick::XInverted",false);
	_DriverXboxCfg.flipLSx = Preferences::GetInstance()->GetBoolean("Driver::XBox::LeftStick::XInverted",false);

	_OperatorXboxCfg.LSxDZ = Preferences::GetInstance()->GetFloat("Operator::XBox::DeadZone::LeftStick::X",0.05);
	_OperatorXboxCfg.LSyDZ = Preferences::GetInstance()->GetFloat("Operator::XBox::DeadZone::LeftStick::Y",0.05);
	_OperatorXboxCfg.RSxDZ = Preferences::GetInstance()->GetFloat("Operator::XBox::DeadZone::RightStick::X",0.05);
	_OperatorXboxCfg.RSyDZ = Preferences::GetInstance()->GetFloat("Operator::XBox::DeadZone::RightStick::Y",0.05);
	_OperatorXboxCfg.LtrigDZ = Preferences::GetInstance()->GetFloat("Operator::XBox::DeadZone::LeftTrigger",0.05);
	_OperatorXboxCfg.RtrigDZ = Preferences::GetInstance()->GetFloat("Operator::XBox::DeadZone::RightTrigger",0.05);
	_OperatorXboxCfg.axisDelay = Preferences::GetInstance()->GetInt("Operator::XBox::AxisDelay",10);
	_OperatorXboxCfg.flipRSy = Preferences::GetInstance()->GetBoolean("Operator::XBox::RightStick::YInverted",true);
	_OperatorXboxCfg.flipLSy = Preferences::GetInstance()->GetBoolean("Operator::XBox::LeftStick::YInverted",true);
	_OperatorXboxCfg.flipRSx = Preferences::GetInstance()->GetBoolean("Operator::XBox::RightStick::XInverted",false);
	_OperatorXboxCfg.flipLSx = Preferences::GetInstance()->GetBoolean("Operator::XBox::LeftStick::XInverted",false);
}

void Robot_Config::Save_XboxCfg()
{
	Preferences::GetInstance()->PutFloat("Driver::XBox::DeadZone::LeftStick::X",_DriverXboxCfg.LSxDZ);
	Preferences::GetInstance()->PutFloat("Driver::XBox::DeadZone::LeftStick::Y",_DriverXboxCfg.LSyDZ);
	Preferences::GetInstance()->PutFloat("Driver::XBox::DeadZone::RightStick::X",_DriverXboxCfg.RSxDZ);
	Preferences::GetInstance()->PutFloat("Driver::XBox::DeadZone::RightStick::Y",_DriverXboxCfg.RSyDZ);
	Preferences::GetInstance()->PutFloat("Driver::XBox::DeadZone::LeftTrigger",_DriverXboxCfg.LtrigDZ);
	Preferences::GetInstance()->PutFloat("Driver::XBox::DeadZone::RightTrigger",_DriverXboxCfg.RtrigDZ);
	Preferences::GetInstance()->PutInt("Driver::XBox::AxisDelay",_DriverXboxCfg.axisDelay);
	Preferences::GetInstance()->PutBoolean("Driver::XBox::RightStick::YInverted",_DriverXboxCfg.flipRSy);
	Preferences::GetInstance()->PutBoolean("Driver::XBox::LeftStick::YInverted",_DriverXboxCfg.flipLSy);
	Preferences::GetInstance()->PutBoolean("Driver::XBox::RightStick::XInverted",_DriverXboxCfg.flipRSx);
	Preferences::GetInstance()->PutBoolean("Driver::XBox::LeftStick::XInverted",_DriverXboxCfg.flipLSx);

	Preferences::GetInstance()->PutFloat("Operator::XBox::DeadZone::LeftStick::X",_OperatorXboxCfg.LSxDZ);
	Preferences::GetInstance()->PutFloat("Operator::XBox::DeadZone::LeftStick::Y",_OperatorXboxCfg.LSyDZ);
	Preferences::GetInstance()->PutFloat("Operator::XBox::DeadZone::RightStick::X",_OperatorXboxCfg.RSxDZ);
	Preferences::GetInstance()->PutFloat("Operator::XBox::DeadZone::RightStick::Y",_OperatorXboxCfg.RSyDZ);
	Preferences::GetInstance()->PutFloat("Operator::XBox::DeadZone::LeftTrigger",_OperatorXboxCfg.LtrigDZ);
	Preferences::GetInstance()->PutFloat("Operator::XBox::DeadZone::RightTrigger",_OperatorXboxCfg.RtrigDZ);
	Preferences::GetInstance()->PutInt("Operator::XBox::AxisDelay",_OperatorXboxCfg.axisDelay);
	Preferences::GetInstance()->PutBoolean("Operator::XBox::RightStick::YInverted",_OperatorXboxCfg.flipRSy);
	Preferences::GetInstance()->PutBoolean("Operator::XBox::LeftStick::YInverted",_OperatorXboxCfg.flipLSy);
	Preferences::GetInstance()->PutBoolean("Operator::XBox::RightStick::XInverted",_OperatorXboxCfg.flipRSx);
	Preferences::GetInstance()->PutBoolean("Operator::XBox::LeftStick::XInverted",_OperatorXboxCfg.flipLSx);
}

#endif

void Robot_Config::Print_XboxCfg()
{
	printf("Printing XBOX Controller Config.\n");
	printf("Driver::XBox::DeadZone::LeftStick::X %f\n",_DriverXboxCfg.LSxDZ);
	printf("Driver::XBox::DeadZone::LeftStick::Y %f\n",_DriverXboxCfg.LSyDZ);
	printf("Driver::XBox::DeadZone::RightStick::X %f\n",_DriverXboxCfg.RSxDZ);
	printf("Driver::XBox::DeadZone::RightStick::Y %f\n",_DriverXboxCfg.RSyDZ);
	printf("Driver::XBox::DeadZone::LeftTrigger %f\n",_DriverXboxCfg.LtrigDZ);
	printf("Driver::XBox::DeadZone::RightTrigger %f\n",_DriverXboxCfg.RtrigDZ);
	printf("Driver::XBox::AxisDelay %d\n",_DriverXboxCfg.axisDelay);
	printf("Driver::XBox::RightStick::YInverted %d\n",_DriverXboxCfg.flipRSy);
	printf("Driver::XBox::LeftStick::YInverted %d\n",_DriverXboxCfg.flipLSy);
	printf("Driver::XBox::RightStick::XInverted %d\n",_DriverXboxCfg.flipRSx);
	printf("Driver::XBox::LeftStick::XInverted %d\n",_DriverXboxCfg.flipLSx);

	printf("Operator::XBox::DeadZone::LeftStick::X %f\n",_OperatorXboxCfg.LSxDZ);
	printf("Operator::XBox::DeadZone::LeftStick::Y %f\n",_OperatorXboxCfg.LSyDZ);
	printf("Operator::XBox::DeadZone::RightStick::X %f\n",_OperatorXboxCfg.RSxDZ);
	printf("Operator::XBox::DeadZone::RightStick::Y %f\n",_OperatorXboxCfg.RSyDZ);
	printf("Operator::XBox::DeadZone::LeftTrigger %f\n",_OperatorXboxCfg.LtrigDZ);
	printf("Operator::XBox::DeadZone::RightTrigger %f\n",_OperatorXboxCfg.RtrigDZ);
	printf("Operator::XBox::AxisDelay %d\n",_OperatorXboxCfg.axisDelay);
	printf("Operator::XBox::RightStick::YInverted %d\n",_OperatorXboxCfg.flipRSy);
	printf("Operator::XBox::LeftStick::YInverted %d\n",_OperatorXboxCfg.flipLSy);
	printf("Operator::XBox::RightStick::XInverted %d\n",_OperatorXboxCfg.flipRSx);
	printf("Operator::XBox::LeftStick::XInverted %d\n",_OperatorXboxCfg.flipLSx);
}

#ifdef Competition_4329
void Robot_Config::Read_VideoCfg()
{
	_VideoCfg.FrontEnable     = true;
	_VideoCfg.RearEnable      = true;
	_VideoCfg.FrontQuality    = 0.3;
	_VideoCfg.RearQuality     = 0.3;
	_VideoCfg.FrontFPS        = 15;
	_VideoCfg.RearFPS         = 15;

	_VideoCfg.FrontHeight     = 320;
	_VideoCfg.FrontWidth      = 240;

	_VideoCfg.RearHeight      = 320;
	_VideoCfg.RearWidth       = 240;

	_VideoCfg.FrontBrightness = Preferences::GetInstance()->GetFloat("Video::Front::Brightness",0.8);
	_VideoCfg.RearBrightness  = Preferences::GetInstance()->GetFloat("Video::Rear::Brightness",0.8);

	_VideoCfg.FrontWBAuto     = true;
	_VideoCfg.RearWBAuto      = true;

	_VideoCfg.FrontWB         = 320;
	_VideoCfg.RearWB          = 480;

    _VideoCfg.FrontExpAuto    = Preferences::GetInstance()->GetBoolean("Video::Front::ExpAuto",false);
	_VideoCfg.RearExpAuto     = Preferences::GetInstance()->GetBoolean("Video::Rear::ExpAuto",false);

	_VideoCfg.FrontExp        = Preferences::GetInstance()->GetFloat("Video::Front::Exp",0.75);
	_VideoCfg.RearExp         = Preferences::GetInstance()->GetFloat("Video::Rear::Exp",0.75);

	_VideoCfg.FrontName = std::string("cam1");
	_VideoCfg.RearName  = std::string("cam2");
	_VideoCfg.configUpdateCount++;
}

void Robot_Config::Save_VideoCfg()
{
	Preferences::GetInstance()->PutFloat("Video::Front::Brightness",_VideoCfg.FrontBrightness);
	Preferences::GetInstance()->PutFloat("Video::Rear::Brightness",_VideoCfg.RearBrightness);
	Preferences::GetInstance()->PutBoolean("Video::Front::ExpAuto",_VideoCfg.FrontExpAuto);
	Preferences::GetInstance()->PutBoolean("Video::Rear::ExpAuto",_VideoCfg.RearExpAuto);
	Preferences::GetInstance()->PutFloat("Video::Front::Exp",_VideoCfg.FrontExp);
	Preferences::GetInstance()->PutFloat("Video::Rear::Exp",_VideoCfg.RearExp);
}

#else
void Robot_Config::Read_VideoCfg()
{
	_VideoCfg.FrontEnable = Preferences::GetInstance()->GetBoolean("Video::Front::Enable",true);
	_VideoCfg.RearEnable = Preferences::GetInstance()->GetBoolean("Video::Rear::Enable",true);
	_VideoCfg.FrontQuality = Preferences::GetInstance()->GetFloat("Video::Front::Quality",0.3);
	_VideoCfg.RearQuality = Preferences::GetInstance()->GetFloat("Video::Rear::Quality",0.3);
	_VideoCfg.FrontFPS = Preferences::GetInstance()->GetFloat("Video::Front::FPS",15);
	_VideoCfg.RearFPS = Preferences::GetInstance()->GetFloat("Video::Rear::FPS",15);

	_VideoCfg.FrontHeight = Preferences::GetInstance()->GetInt("Video::Front::Height",320);
	_VideoCfg.FrontWidth = Preferences::GetInstance()->GetInt("Video::Front::Width",240);

	_VideoCfg.RearHeight = Preferences::GetInstance()->GetInt("Video::Rear::Height",320);
	_VideoCfg.RearWidth = Preferences::GetInstance()->GetInt("Video::Rear::Width",240);

	_VideoCfg.FrontBrightness = Preferences::GetInstance()->GetFloat("Video::Front::Brightness",0.8);
	_VideoCfg.RearBrightness = Preferences::GetInstance()->GetFloat("Video::Rear::Brightness",0.8);

	_VideoCfg.FrontWBAuto = Preferences::GetInstance()->GetBoolean("Video::Front::WBAuto",true);
	_VideoCfg.RearWBAuto = Preferences::GetInstance()->GetBoolean("Video::Rear::WBAuto",true);

	_VideoCfg.FrontWB = Preferences::GetInstance()->GetInt("Video::Front::WB",320);
	_VideoCfg.RearWB = Preferences::GetInstance()->GetInt("Video::Rear::WB",480);

    _VideoCfg.FrontExpAuto = Preferences::GetInstance()->GetBoolean("Video::Front::ExpAuto",false);
	_VideoCfg.RearExpAuto = Preferences::GetInstance()->GetBoolean("Video::Rear::ExpAuto",false);

	_VideoCfg.FrontExp = Preferences::GetInstance()->GetFloat("Video::Front::Exp",0.75);
	_VideoCfg.RearExp = Preferences::GetInstance()->GetFloat("Video::Rear::Exp",0.75);

	_VideoCfg.FrontName = Preferences::GetInstance()->GetString("Video::Front","cam1");
	_VideoCfg.RearName = Preferences::GetInstance()->GetString("Video::Rear","cam2");
	_VideoCfg.configUpdateCount++;
}

void Robot_Config::Save_VideoCfg()
{
	Preferences::GetInstance()->PutBoolean("Video::Front::Enable",_VideoCfg.FrontEnable);
	Preferences::GetInstance()->PutBoolean("Video::Rear::Enable",_VideoCfg.RearEnable);
	Preferences::GetInstance()->PutFloat("Video::Front::Quality",_VideoCfg.FrontQuality);
	Preferences::GetInstance()->PutFloat("Video::Rear::Quality",_VideoCfg.RearQuality);
	Preferences::GetInstance()->PutFloat("Video::Front::FPS",_VideoCfg.FrontFPS);
	Preferences::GetInstance()->PutFloat("Video::Rear::FPS",_VideoCfg.RearFPS);

	Preferences::GetInstance()->PutInt("Video::Front::Height",_VideoCfg.FrontHeight);
	Preferences::GetInstance()->PutInt("Video::Front::Width",_VideoCfg.FrontWidth);

	Preferences::GetInstance()->PutInt("Video::Rear::Height",_VideoCfg.RearHeight);
	Preferences::GetInstance()->PutInt("Video::Rear::Width",_VideoCfg.RearWidth);

	Preferences::GetInstance()->PutFloat("Video::Front::Brightness",_VideoCfg.FrontBrightness);
	Preferences::GetInstance()->PutFloat("Video::Rear::Brightness",_VideoCfg.RearBrightness);

	Preferences::GetInstance()->PutBoolean("Video::Front::WBAuto",_VideoCfg.FrontWBAuto);
	Preferences::GetInstance()->PutBoolean("Video::Rear::WBAuto",_VideoCfg.RearWBAuto);

	Preferences::GetInstance()->PutInt("Video::Front::WB",_VideoCfg.FrontWB);
    Preferences::GetInstance()->PutInt("Video::Rear::WB",_VideoCfg.RearWB );

    Preferences::GetInstance()->PutBoolean("Video::Front::ExpAuto",_VideoCfg.FrontExpAuto);
	Preferences::GetInstance()->PutBoolean("Video::Rear::ExpAuto",_VideoCfg.RearExpAuto);

	Preferences::GetInstance()->PutFloat("Video::Front::Exp",_VideoCfg.FrontExp);
	Preferences::GetInstance()->PutFloat("Video::Rear::Exp",_VideoCfg.RearExp);

	Preferences::GetInstance()->PutString("Video::Front",_VideoCfg.FrontName);
	Preferences::GetInstance()->PutString("Video::Rear",_VideoCfg.RearName);
}


#endif
void Robot_Config::Print_VideoCfg()
{
	printf("Printing Video Config.\n");
	printf("Video::Front::Enable %d\n",_VideoCfg.FrontEnable);
	printf("Video::Rear::Enable %d\n",_VideoCfg.RearEnable);
	printf("Video::Front::Quality %f\n",_VideoCfg.FrontQuality);
	printf("Video::Rear::Quality %f\n",_VideoCfg.RearQuality);
	printf("Video::Front::FPS %f\n",_VideoCfg.FrontFPS);
	printf("Video::Rear::FPS %f\n",_VideoCfg.RearFPS);
	printf("Video::Front::Height %d\n",_VideoCfg.FrontHeight);
	printf("Video::Front::Width %d\n",_VideoCfg.FrontWidth);
	printf("Video::Rear::Height %d\n",_VideoCfg.RearHeight);
	printf("Video::Rear::Width %d\n",_VideoCfg.RearWidth);
	printf("Video::Front::Brightness %f\n",_VideoCfg.FrontBrightness);
	printf("Video::Rear::Brightness %f\n",_VideoCfg.RearBrightness);
	printf("Video::Front::WBAuto %d\n",_VideoCfg.FrontWBAuto);
	printf("Video::Rear::WBAuto %d\n",_VideoCfg.RearWBAuto);
	printf("Video::Front::WB %d\n",_VideoCfg.FrontWB);
	printf("Video::Rear::WB %d\n",_VideoCfg.RearWB );
	printf("Video::Front::ExpAuto %d\n",_VideoCfg.FrontExpAuto);
	printf("Video::Rear::ExpAuto %d\n",_VideoCfg.RearExpAuto);
	printf("Video::Front::Exp %f\n",_VideoCfg.FrontExp);
	printf("Video::Rear::Exp %f\n",_VideoCfg.RearExp);
	printf("Video::Front %s\n",_VideoCfg.FrontName.c_str());
	printf("Video::Rear %s\n",_VideoCfg.RearName.c_str());
}
