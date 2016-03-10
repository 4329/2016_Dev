#ifndef DRIVETRAINCONFIG_H
#define DRIVETRAINCONFIG_H

class DriveTrain_Config
{
public:
	float  DriveTrain_HighSpeed;
	float  DriveTrain_LowSpeed;
	int    DriveTrain_QuadEncoder_CodesPerRev;
	float  DriveTrain_InchesPerRotation;

	bool   DriveTrain_EnableVoltRampRate;
	double DriveTrain_VoltRampRate;
	int    DriveTrain_PID_CL_Allowable_Error;


	bool   DriveTrain_Right_Reversed;
	bool   DriveTrain_Right_SensorReversed;
	double DriveTrain_Right_Profile_0_PID_P;
	double DriveTrain_Right_Profile_0_PID_I;
	double DriveTrain_Right_Profile_0_PID_D;
	double DriveTrain_Right_Profile_0_PID_F;
	int    DriveTrain_Right_Profile_0_IZone;
	bool   DriveTrain_Right_Profile_0_EnableCLRampRate;
	double DriveTrain_Right_Profile_0_CLRampRate;
	double DriveTrain_Right_Profile_1_PID_P;
	double DriveTrain_Right_Profile_1_PID_I;
	double DriveTrain_Right_Profile_1_PID_D;
	double DriveTrain_Right_Profile_1_PID_F;
	int    DriveTrain_Right_Profile_1_IZone;
	bool   DriveTrain_Right_Profile_1_EnableCLRampRate;
	double DriveTrain_Right_Profile_1_CLRampRate;

	bool   DriveTrain_RightTalon1_Enabled;
	int    DriveTrain_RightTalon1_CANID;

	bool   DriveTrain_RightTalon1_HasSensor;
	bool   DriveTrain_RightTalon1_EnablePID;
	bool   DriveTrain_RightTalon1_Slaved;
	int    DriveTrain_RightTalon1_MasterCANID;

	bool   DriveTrain_RightTalon2_Enabled;
	int    DriveTrain_RightTalon2_CANID;
	bool   DriveTrain_RightTalon2_HasSensor;
	bool   DriveTrain_RightTalon2_EnablePID;
	bool   DriveTrain_RightTalon2_Slaved;
	int    DriveTrain_RightTalon2_MasterCANID;

	bool   DriveTrain_Left_Reversed;
	bool   DriveTrain_Left_SensorReversed;
	double DriveTrain_Left_Profile_0_PID_P;
	double DriveTrain_Left_Profile_0_PID_I;
	double DriveTrain_Left_Profile_0_PID_D;
	double DriveTrain_Left_Profile_0_PID_F;
	int    DriveTrain_Left_Profile_0_IZone;
	bool   DriveTrain_Left_Profile_0_EnableCLRampRate;
	double DriveTrain_Left_Profile_0_CLRampRate;
	double DriveTrain_Left_Profile_1_PID_P;
	double DriveTrain_Left_Profile_1_PID_I;
	double DriveTrain_Left_Profile_1_PID_D;
	double DriveTrain_Left_Profile_1_PID_F;
	int    DriveTrain_Left_Profile_1_IZone;
	bool   DriveTrain_Left_Profile_1_EnableCLRampRate;
	double DriveTrain_Left_Profile_1_CLRampRate;

	bool   DriveTrain_LeftTalon1_Enabled;
	int    DriveTrain_LeftTalon1_CANID;
	bool   DriveTrain_LeftTalon1_HasSensor;
	bool   DriveTrain_LeftTalon1_EnablePID;
	bool   DriveTrain_LeftTalon1_Slaved;
	int    DriveTrain_LeftTalon1_MasterCANID;

	bool   DriveTrain_LeftTalon2_Enabled;
	int    DriveTrain_LeftTalon2_CANID;
	bool   DriveTrain_LeftTalon2_HasSensor;
	bool   DriveTrain_LeftTalon2_EnablePID;
	bool   DriveTrain_LeftTalon2_Slaved;
	int    DriveTrain_LeftTalon2_MasterCANID;

};

#endif
