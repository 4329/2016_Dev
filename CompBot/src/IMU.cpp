#include "IMU.h"
#include "RobotMap.h"



IMU::IMU() : Configurable("IMU") {
	_myIMU = RobotMap::imu;
    last_world_linear_accel_x = 0.0f;
    last_world_linear_accel_y = 0.0f;
    last_world_linear_accel_z = 0.0f;

	if (!ConfigExists()) CreateConfig();

    RetrieveConfig();
	Configure();
}

IMU::~IMU()
{

}

void IMU::RetrieveConfig()
{
	COLLISION_THRESHOLD_DELTA_G = Preferences::GetInstance()->GetFloat("IMU::COLLISION_THRESHOLD_DELTA_G",0.5);
	MOVE_THRESHOLD_DELTA_MAG    = Preferences::GetInstance()->GetFloat("IMU::MOVE_THRESHOLD_DELTA_MAG",0.25);
	ROT_THRESHOLD_DELTA         = Preferences::GetInstance()->GetFloat("IMU::ROT_THRESHOLD_DELTA",1.5);
}

void IMU::Configure()
{

}

void IMU::SaveConfig()
{
    Preferences::GetInstance()->PutFloat("IMU::COLLISION_THRESHOLD_DELTA_G",COLLISION_THRESHOLD_DELTA_G);
    Preferences::GetInstance()->PutFloat("IMU::MOVE_THRESHOLD_DELTA_MAG",MOVE_THRESHOLD_DELTA_MAG);
    Preferences::GetInstance()->PutFloat("IMU::ROT_THRESHOLD_DELTA",ROT_THRESHOLD_DELTA);
}

void IMU::CreateConfig()
{
	Preferences::GetInstance()->GetFloat("IMU::COLLISION_THRESHOLD_DELTA_G",0.5);
	Preferences::GetInstance()->GetFloat("IMU::MOVE_THRESHOLD_DELTA_MAG",0.25);
	Preferences::GetInstance()->GetFloat("IMU::ROT_THRESHOLD_DELTA",1.5);
}




bool   IMU::GetRPY(float &roll, float &pitch, float &yaw)
{
		if (_myIMU->IsConnected())
		{
			roll = _myIMU->GetRoll();
			pitch = _myIMU->GetPitch();
			yaw = _myIMU->GetYaw();
			return true;
		}
		return false;
}

float  IMU::GetCompassHeading()
{
	return _myIMU->GetCompassHeading();
}

void   IMU::ZeroYaw()
{
	_myIMU->ZeroYaw();
}

bool   IMU::IsCalibrating()
{
	return _myIMU->IsCalibrating();
}

bool   IMU::GetAccels(float &x, float &y, float &z)
{
	if (_myIMU->IsConnected())
	{
		x = _myIMU->GetWorldLinearAccelX();
		y = _myIMU->GetWorldLinearAccelY();
		z = _myIMU->GetWorldLinearAccelZ();
		return true;
	}
	return false;
}

bool   IMU::IsMoving()
{
	if (_myIMU->IsMoving())
	{
	    double x = _myIMU->GetWorldLinearAccelX();
	    double y = _myIMU->GetWorldLinearAccelY();
	    double z = _myIMU->GetWorldLinearAccelZ();

	    if ((x >= MOVE_THRESHOLD_DELTA_MAG) || (y >= MOVE_THRESHOLD_DELTA_MAG) || (z >= MOVE_THRESHOLD_DELTA_MAG)) return true;
	}
	return false;
}

bool   IMU::IsRotating()
{
	if (_myIMU->IsRotating())
	{
		float x  = _myIMU->GetRawGyroX();
		float y  = _myIMU->GetRawGyroY();
		float z  = _myIMU->GetRawGyroZ();

		if ((x >= ROT_THRESHOLD_DELTA) || (y >= ROT_THRESHOLD_DELTA) || (z >=ROT_THRESHOLD_DELTA)) return true;
	}
	return false;
}

bool   IMU::GetAltitude(float &alt)
{
	if (_myIMU->IsConnected()&&_myIMU->IsAltitudeValid())
	{
	    alt = _myIMU->GetAltitude();
	    return true;
	}
	return false;
}


float  IMU::GetFusedHeading()
{
	return _myIMU->GetFusedHeading();
}

bool   IMU::IsMagneticDisturbance()
{
	return _myIMU->IsMagneticDisturbance();
}

bool   IMU::IsMagnetometerCalibrated()
{
	return _myIMU->IsMagnetometerCalibrated();
}

void   IMU::ResetDisplacement()
{
	_myIMU->ResetDisplacement();
}

bool   IMU::GetDisplacement(float &x, float &y, float &z)
{
	if (_myIMU->IsConnected())
	{
		x = _myIMU->GetDisplacementX();
		y = _myIMU->GetDisplacementY();
		z = _myIMU->GetDisplacementZ();
		return true;
	}
	return false;
}

bool   IMU::GetVelocity(float &x, float &y, float &z)
{
	if (_myIMU->IsConnected())
	{
		x = _myIMU->GetVelocityX();
		y = _myIMU->GetVelocityY();
		z = _myIMU->GetVelocityZ();
		return true;
	}
	return false;
}


double IMU::GetAngle()
{
	return _myIMU->GetAngle();
}

double IMU::GetRate()
{
	return _myIMU->GetRate();
}

float  IMU::GetTempC()
{
	return _myIMU->GetTempC();
}

bool   IMU::IsColliding()
{
    double curr_world_linear_accel_x = _myIMU->GetWorldLinearAccelX();
    double curr_world_linear_accel_y = _myIMU->GetWorldLinearAccelY();
    double curr_world_linear_accel_z = _myIMU->GetWorldLinearAccelZ();

    double currentJerkX = curr_world_linear_accel_x - last_world_linear_accel_x;
    double currentJerkY = curr_world_linear_accel_y - last_world_linear_accel_y;
    double currentJerkZ = curr_world_linear_accel_z - last_world_linear_accel_z;

    last_world_linear_accel_x = curr_world_linear_accel_x;
    last_world_linear_accel_y = curr_world_linear_accel_y;
    last_world_linear_accel_z = curr_world_linear_accel_z;

    if ( ( fabs(currentJerkX) > COLLISION_THRESHOLD_DELTA_G)  ||
         ( fabs(currentJerkY) > COLLISION_THRESHOLD_DELTA_G)  ||
         ( fabs(currentJerkZ) > COLLISION_THRESHOLD_DELTA_G))
    {
        return true;
    }
    return false;
}


