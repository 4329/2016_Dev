// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef INTAKE_H
#define INTAKE_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Configurable.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class Intake: public Subsystem , public Configurable {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities

	std::shared_ptr<CANTalon> intakeTalon;

	float  Intake_InSpeed;
	float  Intake_OutSpeed;
	float  Intake_PreFireOut;
	bool   Intake_Talon_Enabled;
	int    Intake_Talon_CANID;
	bool   Intake_Talon_Reversed;
	bool   Intake_Talon_EnableVoltRampRate;
	double Intake_Talon_VoltRampRate;

public:
	Intake();
	virtual ~Intake();
	void InitDefaultCommand();

	virtual void RetrieveConfig();
	virtual void Configure();
	virtual void SaveConfig();
	virtual void LiveConfigure();

	void SetIntake(bool in, float percent_speed = 1.0);
	void StopIntake();

	float Get_PreFireOut();

	bool RobotHasBall();
	bool IsBallAtShooter();
    float Limit(float num);

};

#endif
