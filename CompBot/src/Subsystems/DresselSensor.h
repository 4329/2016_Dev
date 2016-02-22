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


#ifndef DRESSELSENSOR_H
#define DRESSELSENSOR_H
#include "WPILib.h"
#include "math.h"
#include "../Configurable.h"
/**
 *
 *
 * @author ExampleAuthor
 */
class DresselSensor: public Configurable {
private:
	std::shared_ptr<AnalogInput> iRdSensorShooter;
	std::shared_ptr<AnalogInput> iRdSensorFront;
	float distThresholdShooter;
	float distThresholdFront;
	float shooterIn;
	float shooterOut;
	float frontIn;
	float frontOut;

public:
	DresselSensor();
	virtual ~DresselSensor();

	virtual void RetrieveConfig();
	virtual void Configure();
	virtual void SaveConfig();
	virtual void CreateConfig();

	float VoltageOutputShooter();
	float VoltageOutputFront();
	float DistanceCalcShooter(long double constE, long double vp1, long double vp2);
	float DistanceCalcFront(long double constE, long double vp1, long double vp2);
	bool  IsInRangeShooter();
	bool  IsInRangeFront();
	void  SetFrontIn();
	void  SetFrontOut();
	void  SetShooterIn();
	void  SetShooterOut();
    void  StoreCalibration();
};

#endif