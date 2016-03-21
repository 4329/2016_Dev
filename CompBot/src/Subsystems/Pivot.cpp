// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "Pivot.h"
#include "../RobotMap.h"
#include "../Robot.h"


Pivot::Pivot() : Subsystem("Pivot") , Configurable("Pivot") {
    pivotStage1 = RobotMap::pivotStage1Solenoid;
    pivotStage2 = RobotMap::pivotStage2Solenoid;

    myCfg.reset(&(Robot::theConfig->_PivotCfg));
	Configure();
}

void Pivot::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
	//SetDefaultCommand(new Pivot_Stick());

}


// Put methods for controlling this subsystem
// here. Call these from Commands.

Pivot::~Pivot()
{

}

void Pivot::RetrieveConfig()
{

}

void Pivot::Configure()
{

}

void Pivot::SaveConfig()
{

}

void Pivot::LiveConfigure()
{
	RetrieveConfig();
	Configure();
}


void Pivot::SetPivotHome()
{

}

void Pivot::SetPivotToHome()
{
	printf("Moving Pivot to Home Position\n");
    RetractPivotStage2();
    RetractPivotStage1();
}

bool Pivot::IsPivotAtHome()
{
	if (!(myCfg->Stage1_ActiveIsExtended == pivotStage1->Get()) && !(myCfg->Stage2_ActiveIsExtended && pivotStage2->Get()) )
	{
	    return true;
	}
	return false;
}

void Pivot::SetPivotIntake()
{
	printf("Setting Pivot to Pivot\n");
	ExtendPivotStage1();
	RetractPivotStage2();
}

bool Pivot::IsPivotAtIntake()
{
	if ( (myCfg->Stage1_ActiveIsExtended == pivotStage1->Get()) && !(myCfg->Stage2_ActiveIsExtended && pivotStage2->Get()) )
	{
	    return true;
	}
	return false;
}


void Pivot::SetPivotLow()
{
	printf("Setting Pivot to Low\n");
	ExtendPivotStage1();
	ExtendPivotStage2();
}

bool Pivot::IsPivotAtLow()
{
	if ( (myCfg->Stage1_ActiveIsExtended == pivotStage1->Get()) && (myCfg->Stage2_ActiveIsExtended && pivotStage2->Get()) )
	{
	    return true;
	}
	return false;
}

void Pivot::UpPivot()
{
	if (IsPivotAtLow())
	{
		printf("Setting Pivot Up to Intake\n");
		RetractPivotStage2();
	} else
	{
		printf("Setting Pivot Up to Home\n");
		RetractPivotStage1();
	}
}
void Pivot::DownPivot()
{
	if (IsPivotAtHome())
	{
		printf("Setting Pivot Down to Intake\n");
		ExtendPivotStage1();
	} else
	{
		printf("Setting Pivot Down to Low\n");
		ExtendPivotStage2();
	}
}

void Pivot::ExtendPivotStage1()
{
	pivotStage1->Set(myCfg->Stage1_ActiveIsExtended);
}

void Pivot::ExtendPivotStage2()
{
	pivotStage2->Set(myCfg->Stage2_ActiveIsExtended);
}

void Pivot::RetractPivotStage1()
{
	pivotStage1->Set(!myCfg->Stage1_ActiveIsExtended);
}

void Pivot::RetractPivotStage2()
{
	pivotStage2->Set(!myCfg->Stage2_ActiveIsExtended);
}

bool Pivot::IsPivotStage1Extended()
{
	bool retval = pivotStage1->Get();

	if ((myCfg->Stage1_ActiveIsExtended && retval) || (!myCfg->Stage1_ActiveIsExtended && !retval))
	{
		return true;
	}
	return false;
}

bool Pivot::IsPivotStage2Extended()
{
	bool retval = pivotStage2->Get();

	if ((myCfg->Stage2_ActiveIsExtended && retval) || (!myCfg->Stage2_ActiveIsExtended && !retval))
	{
		return true;
	}
	return false;
}
