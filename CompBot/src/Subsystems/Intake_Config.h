#ifndef INTAKECONFIG_H
#define INTAKECONFIG_H

class Intake_Config
{
public:
	float  Intake_InSpeed;
	float  Intake_OutSpeed;
	float  Intake_QuadEncoder_PulsesPerDegree;
	bool   Intake_intakeTalon1_Enabled;
	int    Intake_intakeTalon1_CANID;
	bool   Intake_intakeTalon1_Reversed;
	bool   Intake_intakeTalon1_HasSensor;
	bool   Intake_intakeTalon1_SensorReversed;
	bool   Intake_intakeTalon1_EnablePID;
	double Intake_intakeTalon1_Profile_0_PID_P;
	double Intake_intakeTalon1_Profile_0_PID_I;
	double Intake_intakeTalon1_Profile_0_PID_D;
	double Intake_intakeTalon1_Profile_0_PID_F;
	int    Intake_intakeTalon1_Profile_0_IZone;
	bool   Intake_intakeTalon1_Profile_0_EnableCLRampRate;
	double Intake_intakeTalon1_Profile_0_CLRampRate;
	double Intake_intakeTalon1_Profile_1_PID_P;
	double Intake_intakeTalon1_Profile_1_PID_I;
	double Intake_intakeTalon1_Profile_1_PID_D;
	double Intake_intakeTalon1_Profile_1_PID_F;
	int    Intake_intakeTalon1_Profile_1_IZone;
	bool   Intake_intakeTalon1_Profile_1_EnableCLRampRate;
	double Intake_intakeTalon1_Profile_1_CLRampRate;
	bool   Intake_intakeTalon1_EnableVoltRampRate;
	double Intake_intakeTalon1_VoltRampRate;
	float  Intake_intakeTalon1_QuadEncoder_PulsesPerInch;
	int    Intake_intakeTalon1_PID_CL_PM_Error;
	bool   Intake_intakeTalon1_Slaved;
	int    Intake_intakeTalon1_MasterCANID;


	float  Intake_UpAngleFromHome;
	float  Intake_IntakeAngleFromHome;
	bool   Intake_pivotTalon_Enabled;
	int    Intake_pivotTalon_CANID;
	bool   Intake_pivotTalon_Reversed;
	bool   Intake_pivotTalon_HasSensor;
	bool   Intake_pivotTalon_SensorReversed;
	bool   Intake_pivotTalon_EnablePID;
	double Intake_pivotTalon_Profile_0_PID_P;
	double Intake_pivotTalon_Profile_0_PID_I;
	double Intake_pivotTalon_Profile_0_PID_D;
	double Intake_pivotTalon_Profile_0_PID_F;
	int    Intake_pivotTalon_Profile_0_IZone;
	bool   Intake_pivotTalon_Profile_0_EnableCLRampRate;
	double Intake_pivotTalon_Profile_0_CLRampRate;
	double Intake_pivotTalon_Profile_1_PID_P;
	double Intake_pivotTalon_Profile_1_PID_I;
	double Intake_pivotTalon_Profile_1_PID_D;
	double Intake_pivotTalon_Profile_1_PID_F;
	int    Intake_pivotTalon_Profile_1_IZone;
	bool   Intake_pivotTalon_Profile_1_EnableCLRampRate;
	double Intake_pivotTalon_Profile_1_CLRampRate;
	bool   Intake_pivotTalon_EnableVoltRampRate;
	double Intake_pivotTalon_VoltRampRate;
	float  Intake_pivotTalon_QuadEncoder_PulsesPerInch;
	int    Intake_pivotTalon_PID_CL_PM_Error;
	bool   Intake_pivotTalon_Slaved;
	int    Intake_pivotTalon_MasterCANID;
};

#endif
