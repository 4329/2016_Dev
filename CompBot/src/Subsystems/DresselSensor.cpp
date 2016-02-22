// By Kurtis Dressel

#include "DresselSensor.h"
#include "../RobotMap.h"
#include "math.h"

DresselSensor::DresselSensor() : Configurable("DresselSensor")  {
    iRdSensorShooter = RobotMap::sensorIRdSensor;
    iRdSensorFront   = RobotMap::sensorIRdSensorFront;

    if (!ConfigExists()) CreateConfig();

    RetrieveConfig();
	Configure();
}


DresselSensor::~DresselSensor()
{

}


float DresselSensor::VoltageOutputShooter() {
	return iRdSensorShooter->GetVoltage(); //gets the ouput of the IR sensor, which is between 0 and 3.5
}

float DresselSensor::VoltageOutputFront() {
	return iRdSensorFront->GetVoltage(); //gets the ouput of the IR sensor, which is between 0 and 3.5
}


float DresselSensor::DistanceCalcShooter(long double constE, long double vp1, long double vp2) {
	constE = 1/-0.8469356909;				//exponent version of the root of -0.8...
	vp1 = iRdSensorShooter->GetVoltage();
	vp2 = vp1/16.43475905;					//first half of equation
	return pow(vp2, constE);				//second half of equation
}

float DresselSensor::DistanceCalcFront(long double constE, long double vp1, long double vp2) {
	constE = 1/-0.8469356909;				//exponent version of the root of -0.8...
	vp1 = iRdSensorFront->GetVoltage();
	vp2 = vp1/16.43475905;					//first half of equation
	return pow(vp2, constE);				//second half of equation
}


bool DresselSensor::IsInRangeShooter() {
	float limit = iRdSensorShooter->GetVoltage();
	if (limit < distThresholdShooter) {		//doesn't accept objects less than 1 cm away or
		SmartDashboard::PutBoolean("Ball at Shooter", false);
		return false;						//greater than 80 cm away
	}
	SmartDashboard::PutBoolean("Ball at Shooter", true);
	return true;
}

bool DresselSensor::IsInRangeFront() {
	float limit = iRdSensorFront->GetVoltage();
	if (limit < distThresholdFront) {    	//doesn't accept objects less than 1 cm away or
		SmartDashboard::PutBoolean("Ball Acquired", false);
		return false;						//greater than 80 cm away
	}
	SmartDashboard::PutBoolean("Ball Acquired", true);
	return true;
}



void DresselSensor::RetrieveConfig()
{
	distThresholdShooter = Preferences::GetInstance()->GetFloat("DresselSensor::Shooter::DistThreshold",1.5);
	distThresholdFront   = Preferences::GetInstance()->GetFloat("DresselSensor::Front::DistThreshold",1.5);
}

void DresselSensor::Configure()
{

}

void DresselSensor::SaveConfig()
{
	Preferences::GetInstance()->PutFloat("DresselSensor::Shooter::DistThreshold",distThresholdShooter);
	Preferences::GetInstance()->PutFloat("DresselSensor::Front::DistThreshold",distThresholdFront);
}

void DresselSensor::CreateConfig()
{
	Preferences::GetInstance()->GetFloat("DresselSensor::Shooter::DistThreshold",1.5);
	Preferences::GetInstance()->GetFloat("DresselSensor::Front::DistThreshold",1.5);
}

void  DresselSensor::SetFrontIn()
{
	frontIn = iRdSensorFront->GetVoltage();
	SmartDashboard::PutNumber("Ball Acquire Voltage",frontIn);
	SmartDashboard::PutBoolean("Ball Acquired", true);
}

void  DresselSensor::SetFrontOut()
{
	frontOut = iRdSensorFront->GetVoltage();
	SmartDashboard::PutNumber("Without Ball Voltage",frontOut);
	SmartDashboard::PutBoolean("Ball Acquired", false);
}

void  DresselSensor::SetShooterIn()
{
	shooterIn = iRdSensorShooter->GetVoltage();
	SmartDashboard::PutNumber("Shooter With Ball",shooterIn);
	SmartDashboard::PutBoolean("Ball at Shooter", true);
}

void  DresselSensor::SetShooterOut()
{
	shooterOut = iRdSensorShooter->GetVoltage();
	SmartDashboard::PutNumber("Shooter Without Ball",shooterOut);
	SmartDashboard::PutBoolean("Ball at Shooter", false);
}

void  DresselSensor::StoreCalibration()
{
	float temp = (frontIn - frontOut)/2;
	distThresholdFront = frontIn - temp;
	Preferences::GetInstance()->PutFloat("DresselSensor::Front::DistThreshold",distThresholdFront);

	temp = (shooterIn - shooterOut)/2;
	distThresholdShooter = shooterIn - temp;
	Preferences::GetInstance()->PutFloat("DresselSensor::Shooter::DistThreshold",distThresholdShooter);
}


