/*
 * PID_Controlled_Variable.cpp
 *
 *  Created on: Jan 24, 2016
 *      Author: matt
 */

#include "WPILib.h"
#include "PID_Controlled_Variable.h"

class PID_C_V_Config
{
public:
	float p,i,d,f;
	float minInput, maxInput, minOutput, maxOutput;
	float tolerance;
	float absTolerance;
	float percentTolerance;
	//PIDSourceType souceType;
};

using namespace std;

PID_Controlled_Variable::PID_Controlled_Variable(string name, std::shared_ptr<PIDSource> source) : Configurable(name)
{
	_source = source;
	myConfig = new PID_C_V_Config();

    CheckConfig("p");

    _controller.reset(new PIDController(1.0,0.01,0,0.01,source.get(),this));
    Configure();
}

PID_Controlled_Variable::~PID_Controlled_Variable()
{
	delete myConfig;
}


void PID_Controlled_Variable::PIDWrite(float output)
{
	_variable = output;
}

void PID_Controlled_Variable::RetrieveConfig()
{
	myConfig->p = Preferences::GetInstance()->GetFloat(_prefix + prefSep + string("p"),1.0);
	myConfig->i = Preferences::GetInstance()->GetFloat(_prefix + prefSep + string("i"),0.01);
	myConfig->d = Preferences::GetInstance()->GetFloat(_prefix + prefSep + string("d"),0.0);
	myConfig->f = Preferences::GetInstance()->GetFloat(_prefix + prefSep + string("f"),0.01);

	myConfig->minInput = Preferences::GetInstance()->GetFloat(_prefix + prefSep + string("minInput"),1);
	myConfig->maxInput = Preferences::GetInstance()->GetFloat(_prefix + prefSep + string("maxInput"),1000);
	myConfig->minOutput = Preferences::GetInstance()->GetFloat(_prefix + prefSep + string("minOutput"),1);
	myConfig->maxOutput = Preferences::GetInstance()->GetFloat(_prefix + prefSep + string("maxOutput"),1000);

	myConfig->tolerance = Preferences::GetInstance()->GetFloat(_prefix + prefSep + string("tolerance"),0.1);
	myConfig->absTolerance = Preferences::GetInstance()->GetFloat(_prefix + prefSep + string("absTolerance"),0.1);
	myConfig->percentTolerance = Preferences::GetInstance()->GetFloat(_prefix + prefSep + string("percentTolerance"),0.01);

	//PIDSourceType souceType;
}

void PID_Controlled_Variable::SaveConfig()
{
	Preferences::GetInstance()->PutFloat(_prefix + prefSep + string("p"),myConfig->p);
	Preferences::GetInstance()->PutFloat(_prefix + prefSep + string("i"),myConfig->i);
	Preferences::GetInstance()->PutFloat(_prefix + prefSep + string("d"),myConfig->d);
	Preferences::GetInstance()->PutFloat(_prefix + prefSep + string("f"),myConfig->f);

	Preferences::GetInstance()->PutFloat(_prefix + prefSep + string("minInput"),myConfig->minInput);
	Preferences::GetInstance()->PutFloat(_prefix + prefSep + string("maxInput"),myConfig->maxInput);
	Preferences::GetInstance()->PutFloat(_prefix + prefSep + string("minOutput"),myConfig->minOutput);
	Preferences::GetInstance()->PutFloat(_prefix + prefSep + string("maxOutput"),myConfig->maxOutput);

	Preferences::GetInstance()->PutFloat(_prefix + prefSep + string("tolerance"),myConfig->tolerance);
	Preferences::GetInstance()->PutFloat(_prefix + prefSep + string("absTolerance"),myConfig->absTolerance);
	Preferences::GetInstance()->PutFloat(_prefix + prefSep + string("percentTolerance"),myConfig->percentTolerance);
}

void PID_Controlled_Variable::LiveConfigure()
{
	RetrieveConfig();
	Configure();
}


void PID_Controlled_Variable::Configure()
{
    _controller->SetPID(myConfig->p,myConfig->i,myConfig->d,myConfig->f);
    _controller->SetInputRange(myConfig->minInput,myConfig->maxInput);
    _controller->SetOutputRange(myConfig->minOutput,myConfig->maxOutput);
    _controller->SetTolerance(myConfig->tolerance);
	_controller->SetAbsoluteTolerance(myConfig->tolerance);
	_controller->SetPercentTolerance(myConfig->percentTolerance);
}

void PID_Controlled_Variable::Enable()
{
	_controller->Enable();
}

void PID_Controlled_Variable::Disable()
{
	_controller->Disable();
}

bool PID_Controlled_Variable::IsEnabled()
{
	return _controller->IsEnabled();
}

void PID_Controlled_Variable::SetPoint(float target)
{
	_controller->SetSetpoint(target);
}

float PID_Controlled_Variable::GetVariable()
{
	return _variable;
}

void PID_Controlled_Variable::Reset()
{
	_controller->Reset();
}

std::shared_ptr<PIDController> PID_Controlled_Variable::GetController()
{
	return _controller;
}





