#ifndef SHOOTERCONFIG_H
#define SHOOTERCONFIG_H

class Shooter_Config
{
public:
	float  Shooter_Speed1;
	float  Shooter_Speed2;
	bool   Shooter_TopTalon_Enabled;
	int    Shooter_TopTalon_CANID;
	bool   Shooter_TopTalon_Reversed;
	bool   Shooter_TopTalon_HasSensor;
	bool   Shooter_TopTalon_SensorReversed;
	bool   Shooter_TopTalon_EnablePID;
	bool   Shooter_TopTalon_EnableVoltRampRate;
	double Shooter_TopTalon_VoltRampRate;
	int    Shooter_TopTalon_PID_CL_PM_Error;
	bool   Shooter_TopTalon_Slaved;
	int    Shooter_TopTalon_MasterCANID;

	bool   Shooter_BottomTalon_Enabled;
	int    Shooter_BottomTalon_CANID;
	bool   Shooter_BottomTalon_Reversed;
	bool   Shooter_BottomTalon_HasSensor;
	bool   Shooter_BottomTalon_SensorReversed;
	bool   Shooter_BottomTalon_EnablePID;
	double Shooter_BottomTalon_Profile_0_PID_P;
	double Shooter_BottomTalon_Profile_0_PID_I;
	double Shooter_BottomTalon_Profile_0_PID_D;
	double Shooter_BottomTalon_Profile_0_PID_F;
	int    Shooter_BottomTalon_Profile_0_IZone;
	bool   Shooter_BottomTalon_Profile_0_EnableCLRampRate;
	double Shooter_BottomTalon_Profile_0_CLRampRate;
	bool   Shooter_BottomTalon_EnableVoltRampRate;
	double Shooter_BottomTalon_VoltRampRate;
	int    Shooter_BottomTalon_PID_CL_PM_Error;
	bool   Shooter_BottomTalon_Slaved;
	int    Shooter_BottomTalon_MasterCANID;
};

#endif
