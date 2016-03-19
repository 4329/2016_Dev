#ifndef AUTONOMOUSCONFIG_H
#define AUTONOMOUSCONFIG_H
#include "WPILib.h"

#include "Configurable.h"

class Autonomous_Config: public Configurable
{
public:

	int   AutonomousMode_Type;
	float Simple_MaxThrottle;
	float Simple_ThrottleRamp;
	double Simple_TimeToRunSecs;
	double Simple_Distance;
	double Simple_AllowedError;


	Autonomous_Config();
	~Autonomous_Config();
	virtual void RetrieveConfig(); // Obtain Configuration.
	virtual void Configure();      // Configure when disabled at first start.
	virtual void LiveConfigure();  // Configure while running robot.  Might be limited parameters.
	virtual void SaveConfig();
	void SetAuto(int mode);
	int GetAuto();
    void Print_Config();

};

#endif
