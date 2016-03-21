#ifndef IMU_H
#define IMU_H

#include "WPILib.h"
#include "AHRS.h"
#include "Configurable.h"
#include "Robot_Config.h"

class IMU: public Configurable {
private:
    double last_world_linear_accel_x;
    double last_world_linear_accel_y;
    double last_world_linear_accel_z;

   /* bool   flipYaw;
    float COLLISION_THRESHOLD_DELTA_G;
    float MOVE_THRESHOLD_DELTA_MAG;
    float ROT_THRESHOLD_DELTA;*/

    IMUCfg myCfg;

public:
    std::shared_ptr<AHRS> _myIMU;

	IMU(IMUCfg &cfg);
	virtual ~IMU();
	virtual void RetrieveConfig();
	virtual void Configure();
	virtual void SaveConfig();
	virtual void LiveConfigure();

    bool   GetRPY(float &roll, float &pitch, float &yaw);
    float  GetCompassHeading();
    void   ZeroYaw();
    float  GetYaw();
    bool   IsCalibrating();
    bool   IsYawFlipped();

    bool   GetAccels(float &x, float &y, float &z);
    float  GetAccelMag();
    float  GetVelocMag();
    bool   IsMoving();
    bool   IsRotating();
    bool   GetAltitude(float &alt);
    float  GetFusedHeading();
    bool   IsMagneticDisturbance();
    bool   IsMagnetometerCalibrated();

    void   ResetDisplacement();
    bool   GetDisplacement(float &x, float &y, float &z);
    bool   GetVelocity(float &x, float &y, float &z);
    double GetAngle();
    double GetRate();
    float  GetTempC();
    bool   IsColliding();

};

#endif
