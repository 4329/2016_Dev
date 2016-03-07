// By Kurtis Dressel

#include "IR_Sensor.h"
#include "../RobotMap.h"
#include "math.h"

IR_Sensor::IR_Sensor(std::shared_ptr<AnalogInput> sensor, std::string name) : Configurable(name)  {
	theSensor = sensor;
	myName = name;

    CheckConfig("DistThreshold");
	Configure();
}

IR_Sensor::~IR_Sensor()
{

}


float IR_Sensor::VoltageOutput() {
	return theSensor->GetVoltage(); //gets the output of the IR sensor, which is between 0 and 3.5
}

float IR_Sensor::DistanceCalc() {
	float constE = 1/-0.8469356909;			//exponent version of the root of -0.8...
	float vp1 = theSensor->GetVoltage();
	float vp2 = vp1/16.43475905;			//first half of equation
	return pow(vp2, constE);				//second half of equation
}

bool IR_Sensor::IsInRange() {
	Signature();
	float limit = theSensor->GetVoltage();
	if (limit < distThreshold) {		//doesn't accept objects less than 1 cm away or
		return false;					//greater than 80 cm away
	}
	return true;
}


void IR_Sensor::RetrieveConfig()
{
	distThreshold = Preferences::GetInstance()->GetFloat(myName + prefSep + "DistThreshold",1.5);
}

void IR_Sensor::Configure()
{

}

void IR_Sensor::LiveConfigure()
{
	RetrieveConfig();
	Configure();
}

void IR_Sensor::SaveConfig()
{
	Preferences::GetInstance()->PutFloat(myName + prefSep + "DistThreshold",distThreshold);
}


void  IR_Sensor::SetIn()
{
	In = theSensor->GetVoltage();
	SmartDashboard::PutNumber(myName + " In Voltage",In);
}

void  IR_Sensor::SetOut()
{
	Out = theSensor->GetVoltage();
	SmartDashboard::PutNumber(myName + " Out Voltage",Out);
}

void  IR_Sensor::StoreCalibration()
{
	float temp = (In - Out)/2;
	distThreshold = In - temp;
	Preferences::GetInstance()->PutFloat(myName + prefSep + "DistThreshold",distThreshold);
}

void  IR_Sensor::Signature()
{
	char t1[] = {0x44,0x72,0x65,0x73,0x73,0x65,0x6c,0x53,0x65,0x6e,0x73,0x6f,0x72,0x20,0x42,0x61,0x62,0x79,0x21,0x0};
	char t2[] = {0x44,0x72,0x65,0x73,0x73,0x65,0x6c,0x53,0x65,0x6e,0x73,0x6f,0x72,0x20,0x42,0x61,0x62,0x79,0x20,0x54,0x6f,0x6f,0x20,0x43,0x6f,0x6c,0x64,0x21,0x0};
	char t3[] = {0x57,0x6f,0x72,0x64,0x20,0x74,0x6f,0x20,0x79,0x6f,0x75,0x72,0x20,0x4d,0x6f,0x74,0x68,0x65,0x72,0x21,0x0};

	if (cnt == 30)
	{
		SmartDashboard::PutString("DS Sensor",std::string(t3));
		cnt = 1;
	}

	if (cnt == 20)
	{
		SmartDashboard::PutString("DS Sensor",std::string(t2));
	}

	if (cnt == 10)
	{
		SmartDashboard::PutString("DS Sensor",std::string(t1));
	}
	cnt++;
}
