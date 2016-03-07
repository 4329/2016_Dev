/*
 * PID_Controlled_Variable.h
 *
 *  Created on: Jan 24, 2016
 *      Author: matt
 */

#ifndef PID_CONTROLLED_VARIABLE_H_
#define PID_CONTROLLED_VARIABLE_H_

#include "WPILib.h"
#include "Configurable.h"
#include "PIDController.h"

class PID_C_V_Config;

class PID_Controlled_Variable : public PIDOutput, public Configurable
{
private:
    PID_C_V_Config *myConfig;

	float _variable;
	float _target;
	std::shared_ptr<PIDSource> _source;
	std::shared_ptr<PIDController> _controller;
	void PIDWrite(float output);

public:
	PID_Controlled_Variable(std::string name, std::shared_ptr<PIDSource> source);
    virtual ~PID_Controlled_Variable();

	virtual void RetrieveConfig();
	virtual void Configure();
	virtual void SaveConfig();
    virtual void LiveConfigure();


	void Enable();
	void Disable();
	bool IsEnabled();
	void SetPoint(float target);
	float GetVariable();

	void Reset();

	std::shared_ptr<PIDController> GetController();

};



#endif /* PID_CONTROLLED_VARIABLE_H_ */
