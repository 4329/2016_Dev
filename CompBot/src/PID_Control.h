/*
 * PID_Control.h
 *
 *  Created on: Jan 24, 2016
 *      Author: matt
 */

#ifndef PID_CONTROL_H_
#define PID_CONTROL_H_

#include "WPILib.h"
#include "Configurable.h"
#include "PIDController.h"


class Multi_PID : public PIDOutput
{
private:
	bool enabled;
	bool reverse;
	float _output;
public:
	Multi_PID();
	float Get_Output();
	virtual void PIDWrite(float output);
	void Enable();
	void Disable();
	bool IsEnabled();
	void SetReversed(bool value);
};


class PID_Control : public Configurable
{
private:

	float _p,_i,_d,_f;
	float _minInput, _maxInput, _minOutput, _maxOutput;
	bool  _useAbs;
	float _absTolerance;
	float _percentTolerance;
	float _period;
	bool  _continuous;

	std::shared_ptr<PIDController> _controller;
	PIDSource* _source;
	PIDOutput* _output;

public:
	PID_Control(std::string name, PIDSource *source, PIDOutput *output);
    virtual ~PID_Control();

	virtual void RetrieveConfig();
	virtual void Configure();
	virtual void SaveConfig();
    virtual void LiveConfigure();

    // Pass through methods.
    float Get();
    void SetContinuous(bool continuous = true);
    void SetInputRange(float minimumInput, float maximumInput);
    void SetOutputRange(float minimumOutput, float maximumOutput);
    void SetPID(double p, double i, double d);
    void SetPID(double p, double i, double d, double f);
    double GetP();
    double GetI();
    double GetD();
    double GetF();
    void SetSetpoint(float setpoint);
    double GetSetpoint();
    double GetDeltaSetpoint();
    float GetError();
    float GetAvgError();
    void SetPIDSourceType(PIDSourceType pidSource);
    PIDSourceType GetPIDSourceType();
    void SetTolerance(float percent);
    void SetAbsoluteTolerance(float absValue);
    void SetPercentTolerance(float percentValue);
    void SetToleranceBuffer(unsigned buf = 1);
    bool OnTarget();
    void Enable();
    void Disable();
    bool IsEnabled();
    void Reset();
    void InitTable(std::shared_ptr<ITable> table);
};



#endif /* PID_CONTROL_H_ */
