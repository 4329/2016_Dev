// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef PIVOT_H
#define PIVOT_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Configurable.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class Pivot: public Subsystem , public Configurable {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities

	std::shared_ptr<Solenoid> pivotStage1;
	std::shared_ptr<Solenoid> pivotStage2;

	int    Pivot_PCMID;
	int    Pivot_Stage1_Channel;
	bool   Pivot_Stage1_ActiveIsExtended;
	int    Pivot_Stage2_Channel;
	bool   Pivot_Stage2_ActiveIsExtended;


public:
	Pivot();
	virtual ~Pivot();
	void InitDefaultCommand();

	virtual void RetrieveConfig();
	virtual void Configure();
	virtual void SaveConfig();
	virtual void CreateConfig();

	void SetPivotHome();
	void SetPivotToHome();
	bool IsPivotAtHome();
	void SetPivotIntake();
	bool IsPivotAtIntake();
	void SetPivotLow();
	bool IsPivotAtLow();

	void UpPivot();
	void DownPivot();

    void ExtendPivotStage1();
    void ExtendPivotStage2();
    void RetractPivotStage1();
    void RetractPivotStage2();

    bool IsPivotStage1Extended();
    bool IsPivotStage2Extended();

};

#endif