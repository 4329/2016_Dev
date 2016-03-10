/*
 * PID_Control.cpp
 *
 *  Created on: Jan 24, 2016
 *      Author: matt
 */

#include "PID_Control.h"
#include "WPILib.h"


using namespace std;


Multi_PID::Multi_PID()
{
	enabled = false;
	reverse = false;
	_output = 0;
}

float Multi_PID::Get_Output()
{
	return _output;
}

void Multi_PID::PIDWrite(float output)
{
	if (enabled)
	{
		_output = output;
		if (reverse)
		{
			_output = 0 - _output;
		}
	}
}

void Multi_PID::Enable()
{
	enabled = true;
}

void Multi_PID::Disable()
{
	enabled = false;
	_output = 0;
}

bool Multi_PID::IsEnabled()
{
	return enabled;
}

void Multi_PID::SetReversed(bool value)
{
	reverse = value;
}


PID_Control::PID_Control(string name, PIDSource *source, PIDOutput *output) : Configurable(name)
{
	_source = source;
	_output = output;

    CheckConfig("p");
	_controller.reset(new PIDController(_p,_i,_d,_f,_source,_output, _period));
    Configure();
}

PID_Control::~PID_Control()
{

}

void PID_Control::RetrieveConfig()
{
	_p = Preferences::GetInstance()->GetFloat(_prefix + prefSep + string("p"),0.02);
	_i = Preferences::GetInstance()->GetFloat(_prefix + prefSep + string("i"),0.0);
	_d = Preferences::GetInstance()->GetFloat(_prefix + prefSep + string("d"),0.0);
	_f = Preferences::GetInstance()->GetFloat(_prefix + prefSep + string("f"),0.0);

	_minInput = Preferences::GetInstance()->GetFloat(_prefix + prefSep + string("minInput"),-180.0);
	_maxInput = Preferences::GetInstance()->GetFloat(_prefix + prefSep + string("maxInput"),180.0);
	_minOutput = Preferences::GetInstance()->GetFloat(_prefix + prefSep + string("minOutput"),-0.2);
	_maxOutput = Preferences::GetInstance()->GetFloat(_prefix + prefSep + string("maxOutput"),0.2);

	_useAbs = Preferences::GetInstance()->GetBoolean(_prefix + prefSep + string("useAbs"),true);
	_absTolerance = Preferences::GetInstance()->GetFloat(_prefix + prefSep + string("absTolerance"),4.0);
	_percentTolerance = Preferences::GetInstance()->GetFloat(_prefix + prefSep + string("percentTolerance"),0.01);

	_period = Preferences::GetInstance()->GetFloat(_prefix + prefSep + string("period"),0.05);
	_continuous = Preferences::GetInstance()->GetBoolean(_prefix + prefSep + string("continuous"),true);

}

void PID_Control::SaveConfig()
{
	Preferences::GetInstance()->PutFloat(_prefix + prefSep + string("p"),_p);
	Preferences::GetInstance()->PutFloat(_prefix + prefSep + string("i"),_i);
	Preferences::GetInstance()->PutFloat(_prefix + prefSep + string("d"),_d);
	Preferences::GetInstance()->PutFloat(_prefix + prefSep + string("f"),_f);

	Preferences::GetInstance()->PutFloat(_prefix + prefSep + string("minInput"),_minInput);
	Preferences::GetInstance()->PutFloat(_prefix + prefSep + string("maxInput"),_maxInput);
	Preferences::GetInstance()->PutFloat(_prefix + prefSep + string("minOutput"),_minOutput);
	Preferences::GetInstance()->PutFloat(_prefix + prefSep + string("maxOutput"),_maxOutput);

	Preferences::GetInstance()->PutBoolean(_prefix + prefSep + string("useAbs"),_useAbs);
	Preferences::GetInstance()->PutFloat(_prefix + prefSep + string("absTolerance"),_absTolerance);
	Preferences::GetInstance()->PutFloat(_prefix + prefSep + string("percentTolerance"),_percentTolerance);
	Preferences::GetInstance()->PutFloat(_prefix + prefSep + string("period"),_period);
	Preferences::GetInstance()->PutBoolean(_prefix + prefSep + string("continuous"),_continuous);
}

void PID_Control::LiveConfigure()
{
	RetrieveConfig();
	Configure();
}


void PID_Control::Configure()
{
    _controller->SetPID(_p,_i,_d,_f);
    _controller->SetInputRange(_minInput,_maxInput);
    _controller->SetOutputRange(_minOutput,_maxOutput);
    if (_useAbs)
    {
    	_controller->SetAbsoluteTolerance(_absTolerance);
    } else
    {
    	_controller->SetPercentTolerance(_percentTolerance);
    }
   	_controller->SetContinuous(_continuous);
}

float PID_Control::Get()
{
	return _controller->Get();
}

void PID_Control::SetContinuous(bool continuous)
{
	_controller->SetContinuous(continuous);
}

void PID_Control::SetInputRange(float minimumInput, float maximumInput)
{
	_controller->SetInputRange(minimumInput, maximumInput);
}

void PID_Control::SetOutputRange(float minimumOutput, float maximumOutput)
{
	_controller->SetOutputRange(minimumOutput, maximumOutput);
}

void PID_Control::SetPID(double p, double i, double d)
{
	_controller->SetPID(p,i,d);
}

void PID_Control::SetPID(double p, double i, double d, double f)
{
	_controller->SetPID(p,i,d,f);
}

double PID_Control::GetP()
{
	return _controller->GetP();
}

double PID_Control::GetI()
{
	return _controller->GetI();
}

double PID_Control::GetD()
{
	return _controller->GetD();
}

double PID_Control::GetF()
{
	return _controller->GetF();
}

void PID_Control::SetSetpoint(float setpoint)
{
	_controller->SetSetpoint(setpoint);
}

double PID_Control::GetSetpoint()
{
	return _controller->GetSetpoint();
}

double PID_Control::GetDeltaSetpoint()
{
	return _controller->GetDeltaSetpoint();
}

float PID_Control::GetError()
{
	return _controller->GetError();
}

float PID_Control::GetAvgError()
{
	return _controller->GetAvgError();
}

void PID_Control::SetPIDSourceType(PIDSourceType pidSource)
{
	_controller->SetPIDSourceType(pidSource);
}

PIDSourceType PID_Control::GetPIDSourceType()
{
	return _controller->GetPIDSourceType();
}

void PID_Control::SetTolerance(float percent)
{
	_controller->SetTolerance(percent);
}

void PID_Control::SetAbsoluteTolerance(float absValue)
{
	_controller->SetAbsoluteTolerance(absValue);
}

void PID_Control::SetPercentTolerance(float percentValue)
{
	_controller->SetPercentTolerance(percentValue);
}

void PID_Control::SetToleranceBuffer(unsigned buf)
{
	_controller->SetToleranceBuffer(buf);
}

bool PID_Control::OnTarget()
{
	return _controller->OnTarget();
}

void PID_Control::Enable()
{
	_controller->Enable();
}

void PID_Control::Disable()
{
	_controller->Disable();
}

bool PID_Control::IsEnabled()
{
	return _controller->IsEnabled();
}

void PID_Control::Reset()
{
	_controller->Reset();
}


void PID_Control::InitTable(std::shared_ptr<ITable> table)
{
	_controller->InitTable(table);
}




