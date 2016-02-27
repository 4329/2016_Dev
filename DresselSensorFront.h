// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

// By Kurtis Dressel


#ifndef DRESSELSENSORFRONT_H
#define DRESSELSENSORFRONT_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "math.h"
#include "../Configurable.h"
/**
 *
 *
 * @author ExampleAuthor
 */
class DresselSensorFront: public Subsystem, public Configurable {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<AnalogInput> iRdSensorFront;
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	float distThreshold;
public:
	DresselSensorFront();
	virtual ~DresselSensorFront();

	virtual void RetrieveConfig();
	virtual void Configure();
	virtual void SaveConfig();
	virtual void CreateConfig();

	void InitDefaultCommand();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
	float VoltageOutput();
	float DistanceCalc(long double constE, long double vp1, long double vp2);
	bool IsInRange();

};

#endif
