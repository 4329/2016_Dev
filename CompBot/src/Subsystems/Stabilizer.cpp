// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "Stabilizer.h"
#include "../RobotMap.h"
#include "../Robot_Config.h"
#include "../Robot.h"


Stabilizer::Stabilizer() : Subsystem("Stabilizer"), Configurable("Stabilizer") {

	StabilizerSolenoid = RobotMap::stabilizerSolenoid;
    myCfg.reset(&(Robot::theConfig->_StabilizerCfg));

	Configure();
}
    
Stabilizer::~Stabilizer()
{

}

void Stabilizer::RetrieveConfig()
{

}

void Stabilizer::SaveConfig()
{

}

void Stabilizer::Configure()
{
	// Do Nothing.
}

void Stabilizer::LiveConfigure()
{
	RetrieveConfig();
	Configure();
}


void Stabilizer::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());

}


// Put methods for controlling this subsystem
// here. Call these from Commands.
void Stabilizer::Deploy()
{
	if (myCfg->ForwardIsDeployed)
	{
		StabilizerSolenoid->Set(DoubleSolenoid::kForward);
	} else
	{
		StabilizerSolenoid->Set(DoubleSolenoid::kReverse);
	}
}

void Stabilizer::Retract()
{
	if (myCfg->ForwardIsDeployed)
	{
		StabilizerSolenoid->Set(DoubleSolenoid::kReverse);
	} else
	{
		StabilizerSolenoid->Set(DoubleSolenoid::kForward);
	}
}

bool Stabilizer::IsDeployed()
{
	if (myCfg->ForwardIsDeployed)
	{
		if (StabilizerSolenoid->Get() == DoubleSolenoid::kForward) return true;
		return false;
	} else
	{
		if (StabilizerSolenoid->Get() == DoubleSolenoid::kReverse) return true;
		return false;
	}
	return false;
}
