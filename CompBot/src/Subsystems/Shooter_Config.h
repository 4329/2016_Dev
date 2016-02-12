#ifndef SHOOTERCONFIG_H
#define SHOOTERCONFIG_H

class Shooter_Config
{
public:
	float  Shooter_Speed1;
	float  Shooter_Speed2;
	float  Shooter_Speed3;
	float  Shooter_Speed4;
	float  Shooter_QuadEncoder_PulsesPerDegree;
	bool   Shooter_shooterTalon1_Enabled;
	int    Shooter_shooterTalon1_CANID;
	bool   Shooter_shooterTalon1_Reversed;
	bool   Shooter_shooterTalon1_HasSensor;
	bool   Shooter_shooterTalon1_SensorReversed;
	bool   Shooter_shooterTalon1_EnablePID;
	double Shooter_shooterTalon1_Profile_0_PID_P;
	double Shooter_shooterTalon1_Profile_0_PID_I;
	double Shooter_shooterTalon1_Profile_0_PID_D;
	double Shooter_shooterTalon1_Profile_0_PID_F;
	int    Shooter_shooterTalon1_Profile_0_IZone;
	bool   Shooter_shooterTalon1_Profile_0_EnableCLRampRate;
	double Shooter_shooterTalon1_Profile_0_CLRampRate;
	double Shooter_shooterTalon1_Profile_1_PID_P;
	double Shooter_shooterTalon1_Profile_1_PID_I;
	double Shooter_shooterTalon1_Profile_1_PID_D;
	double Shooter_shooterTalon1_Profile_1_PID_F;
	int    Shooter_shooterTalon1_Profile_1_IZone;
	bool   Shooter_shooterTalon1_Profile_1_EnableCLRampRate;
	double Shooter_shooterTalon1_Profile_1_CLRampRate;
	bool   Shooter_shooterTalon1_EnableVoltRampRate;
	double Shooter_shooterTalon1_VoltRampRate;
	float  Shooter_shooterTalon1_QuadEncoder_PulsesPerInch;
	int    Shooter_shooterTalon1_PID_CL_PM_Error;
	bool   Shooter_shooterTalon1_Slaved;
	int    Shooter_shooterTalon1_MasterCANID;

	bool   Shooter_shooterTalon2_Enabled;
	int    Shooter_shooterTalon2_CANID;
	bool   Shooter_shooterTalon2_Reversed;
	bool   Shooter_shooterTalon2_HasSensor;
	bool   Shooter_shooterTalon2_SensorReversed;
	bool   Shooter_shooterTalon2_EnablePID;
	double Shooter_shooterTalon2_Profile_0_PID_P;
	double Shooter_shooterTalon2_Profile_0_PID_I;
	double Shooter_shooterTalon2_Profile_0_PID_D;
	double Shooter_shooterTalon2_Profile_0_PID_F;
	int    Shooter_shooterTalon2_Profile_0_IZone;
	bool   Shooter_shooterTalon2_Profile_0_EnableCLRampRate;
	double Shooter_shooterTalon2_Profile_0_CLRampRate;
	double Shooter_shooterTalon2_Profile_1_PID_P;
	double Shooter_shooterTalon2_Profile_1_PID_I;
	double Shooter_shooterTalon2_Profile_1_PID_D;
	double Shooter_shooterTalon2_Profile_1_PID_F;
	int    Shooter_shooterTalon2_Profile_1_IZone;
	bool   Shooter_shooterTalon2_Profile_1_EnableCLRampRate;
	double Shooter_shooterTalon2_Profile_1_CLRampRate;
	bool   Shooter_shooterTalon2_EnableVoltRampRate;
	double Shooter_shooterTalon2_VoltRampRate;
	float  Shooter_shooterTalon2_QuadEncoder_PulsesPerInch;
	int    Shooter_shooterTalon2_PID_CL_PM_Error;
	bool   Shooter_shooterTalon2_Slaved;
	int    Shooter_shooterTalon2_MasterCANID;
};

#endif
