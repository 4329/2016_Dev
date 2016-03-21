// By Kurtis Dressel


#ifndef IR_SENSOR_H
#define IR_SENSOR_H
#include "WPILib.h"
#include "math.h"
#include "../Configurable.h"

class IR_Sensor: public Configurable {
private:
    std::shared_ptr<AnalogInput> theSensor;
	std::string myName;
	float distThreshold;
	float err;
	float In;
	float Out;
	float cnt;
    void  Signature();

public:
	IR_Sensor(std::shared_ptr<AnalogInput> sensor, float &threshold, std::string name);
	virtual ~IR_Sensor();

	virtual void RetrieveConfig();
	virtual void Configure();
	virtual void SaveConfig();
	virtual void LiveConfigure();

	float VoltageOutput();
	float DistanceCalc();
	bool  IsInRange();
	void  SetIn();
	void  SetOut();
    void  StoreCalibration();
};

#endif
