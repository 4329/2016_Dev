#ifndef ROBOTCONFIG_H
#define ROBOTCONFIG_H
#include "WPILib.h"

#include "Configurable.h"


typedef struct {
	int   AutonomousMode_Type;
	float Simple_MaxThrottle;
	float Simple_ThrottleRamp;
	double Simple_TimeToRunSecs;
	double Simple_Distance;
	double Simple_AllowedError;
} AutonomousCfg;

typedef struct {
	int    DriveType;
	float  HighSpeed;
	float  LowSpeed;
	int    QuadEncoder_CodesPerRev;
	float  InchesPerRotation;

	bool   EnableVoltRampRate;
	double VoltRampRate;
	int    PID_CL_Allowable_Error;

	bool   Right_Reversed;
	bool   Right_SensorReversed;
	double Right_Profile_0_PID_P;
	double Right_Profile_0_PID_I;
	double Right_Profile_0_PID_D;
	double Right_Profile_0_PID_F;
	int    Right_Profile_0_IZone;
	bool   Right_Profile_0_EnableCLRampRate;
	double Right_Profile_0_CLRampRate;
	double Right_Profile_1_PID_P;
	double Right_Profile_1_PID_I;
	double Right_Profile_1_PID_D;
	double Right_Profile_1_PID_F;
	int    Right_Profile_1_IZone;
	bool   Right_Profile_1_EnableCLRampRate;
	double Right_Profile_1_CLRampRate;

	bool   RightTalon1_Enabled;
	int    RightTalon1_CANID;
	bool   RightTalon1_HasSensor;
	bool   RightTalon1_EnablePID;
	bool   RightTalon1_Slaved;
	int    RightTalon1_MasterCANID;

	bool   RightTalon2_Enabled;
	int    RightTalon2_CANID;
	bool   RightTalon2_HasSensor;
	bool   RightTalon2_EnablePID;
	bool   RightTalon2_Slaved;
	int    RightTalon2_MasterCANID;

	bool   Left_Reversed;
	bool   Left_SensorReversed;
	double Left_Profile_0_PID_P;
	double Left_Profile_0_PID_I;
	double Left_Profile_0_PID_D;
	double Left_Profile_0_PID_F;
	int    Left_Profile_0_IZone;
	bool   Left_Profile_0_EnableCLRampRate;
	double Left_Profile_0_CLRampRate;
	double Left_Profile_1_PID_P;
	double Left_Profile_1_PID_I;
	double Left_Profile_1_PID_D;
	double Left_Profile_1_PID_F;
	int    Left_Profile_1_IZone;
	bool   Left_Profile_1_EnableCLRampRate;
	double Left_Profile_1_CLRampRate;

	bool   LeftTalon1_Enabled;
	int    LeftTalon1_CANID;
	bool   LeftTalon1_HasSensor;
	bool   LeftTalon1_EnablePID;
	bool   LeftTalon1_Slaved;
	int    LeftTalon1_MasterCANID;

	bool   LeftTalon2_Enabled;
	int    LeftTalon2_CANID;
	bool   LeftTalon2_HasSensor;
	bool   LeftTalon2_EnablePID;
	bool   LeftTalon2_Slaved;
	int    LeftTalon2_MasterCANID;

} DriveTrainCfg;

typedef struct {
	float  InSpeed;
	float  OutSpeed;
	float  PreFireOut;
	bool   Talon_Enabled;
	int    Talon_CANID;
	bool   Talon_Reversed;
	bool   Talon_EnableVoltRampRate;
	double Talon_VoltRampRate;
} IntakeCfg;

typedef struct {
	int    PCMID;
	int    Stage1_Channel;
	bool   Stage1_ActiveIsExtended;
	int    Stage2_Channel;
	bool   Stage2_ActiveIsExtended;
} PivotCfg;

typedef struct {
	int  PCMID;
	int  Channel;
	bool ActiveIsExtended;
} ScalarCfg;

typedef struct {
    bool  flipYaw;
    float COLLISION_THRESHOLD_DELTA_G;
    float MOVE_THRESHOLD_DELTA_MAG;
    float ROT_THRESHOLD_DELTA;
} IMUCfg;

typedef struct {
	int    PDP_CANID;
	int    Tower_AnalogChannel;
	float  Tower_distThreshold;
	int    Front_AnalogChannel;
	float  Front_distThreshold;
	int    Shooter_AnalogChannel;
	float  Shooter_distThreshold;
	float  TowerInRangeRumble;
	int    Pressure_AnalogChannel;
    IMUCfg _IMUcfg;

} SensorCfg;

typedef struct {
	float  Speed1;
	float  Speed2;
	float  PercentVoltage1;
	float  PercentVoltage2;
	bool   UseSpeed;
	double Fire_Timeout;
	float  StallRPM_Threshold;
	bool   TopTalon_Enabled;
	int    TopTalon_CANID;
	bool   TopTalon_Reversed;
	bool   TopTalon_HasSensor;
	bool   TopTalon_SensorReversed;
	bool   TopTalon_EnablePID;
	bool   TopTalon_EnableVoltRampRate;
	double TopTalon_VoltRampRate;
	int    TopTalon_PID_CL_PM_Error;
	bool   TopTalon_Slaved;
	int    TopTalon_MasterCANID;

	bool   BottomTalon_Enabled;
	int    BottomTalon_CANID;
	bool   BottomTalon_Reversed;
	bool   BottomTalon_HasSensor;
	bool   BottomTalon_SensorReversed;
	bool   BottomTalon_EnablePID;
	double BottomTalon_Profile_0_PID_P;
	double BottomTalon_Profile_0_PID_I;
	double BottomTalon_Profile_0_PID_D;
	double BottomTalon_Profile_0_PID_F1;
	double BottomTalon_Profile_0_PID_F2;
	int    BottomTalon_Profile_0_IZone;
	bool   BottomTalon_Profile_0_EnableCLRampRate;
	double BottomTalon_Profile_0_CLRampRate;
	bool   BottomTalon_EnableVoltRampRate;
	double BottomTalon_VoltRampRate;
	int    BottomTalon_PID_CL_PM_Error;
	bool   BottomTalon_Slaved;
	int    BottomTalon_MasterCANID;
} ShooterCfg;

typedef struct {
	int    PCMID;
	int    FwdChannel;
	int    RevChannel;
	bool   ForwardIsDeployed;
} StabilizerCfg;

typedef struct {
	float			LSxDZ, LSyDZ, RSxDZ, RSyDZ, LtrigDZ, RtrigDZ;
	int 			axisDelay;
	bool			flipRSx,flipRSy,flipLSx,flipLSy;
} XboxCfg;

typedef struct {
	bool   FrontEnable;
	bool   RearEnable;
	float  FrontQuality;
	float  RearQuality;
    float  FrontFPS;
    float  RearFPS;
    unsigned int FrontHeight, FrontWidth;
    unsigned int RearHeight, RearWidth;
    float FrontBrightness;
    float RearBrightness;
    bool FrontWBAuto;
    bool RearWBAuto;
    unsigned int FrontWB;
    unsigned int RearWB;
    bool FrontExpAuto;
    bool RearExpAuto;
    float FrontExp;
    float RearExp;
	std::string FrontName;
	std::string RearName;
	bool StopCapture;
	int configUpdateCount;
} VideoCfg;

class Robot_Config
{
public:
    int           _override; // 0: Use networktable values. 1: generate default PID values.
	AutonomousCfg _AutoCfg;
	DriveTrainCfg _DriveCfg;
	IntakeCfg     _IntakeCfg;
	PivotCfg      _PivotCfg;
	ScalarCfg     _ScalarCfg;
	SensorCfg     _SensorCfg;
	ShooterCfg    _ShooterCfg;
	StabilizerCfg _StabilizerCfg;
	XboxCfg       _DriverXboxCfg;
	XboxCfg       _OperatorXboxCfg;
	VideoCfg      _VideoCfg;

	Robot_Config();
	~Robot_Config();

	void Read_Config();
	void Save_Config();
    void Print_Config();
    void Update_Config();

    void Read_AutonomousCfg();
    void Read_DriveTrainCfg();
    void Read_IntakeCfg();
    void Read_PivotCfg();
    void Read_ScalarCfg();
    void Read_SensorCfg();
    void Read_ShooterCfg();
    void Read_StabilizerCfg();
    void Read_XboxCfg();
    void Read_VideoCfg();

    void Save_AutonomousCfg();
    void Save_DriveTrainCfg();
    void Save_IntakeCfg();
    void Save_PivotCfg();
    void Save_ScalarCfg();
    void Save_SensorCfg();
    void Save_ShooterCfg();
    void Save_StabilizerCfg();
    void Save_XboxCfg();
    void Save_VideoCfg();

    void Print_AutonomousCfg();
    void Print_DriveTrainCfg();
    void Print_IntakeCfg();
    void Print_PivotCfg();
    void Print_ScalarCfg();
    void Print_SensorCfg();
    void Print_ShooterCfg();
    void Print_StabilizerCfg();
    void Print_XboxCfg();
    void Print_VideoCfg();

    bool Exists(std::string theKey);
};

#endif
