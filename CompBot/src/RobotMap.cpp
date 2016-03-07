// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "Robot.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"



std::shared_ptr<CANTalon> RobotMap::driveTrainRightTalon2;
std::shared_ptr<CANTalon> RobotMap::driveTrainRightTalon1;
std::shared_ptr<CANTalon> RobotMap::driveTrainLeftTalon2;
std::shared_ptr<CANTalon> RobotMap::driveTrainLeftTalon1;
std::shared_ptr<RobotDrive> RobotMap::driveTrainRobotDrive;
std::shared_ptr<CANTalon> RobotMap::intakeTalon;
std::shared_ptr<CANTalon> RobotMap::shooterTopTalon;
std::shared_ptr<CANTalon> RobotMap::shooterBottomTalon;

std::shared_ptr<Compressor> RobotMap::theCompressor;
std::shared_ptr<Solenoid> RobotMap::brakeSolenoid;
std::shared_ptr<DoubleSolenoid> RobotMap::stabilizerSolenoid;
std::shared_ptr<Solenoid> RobotMap::pivotStage1Solenoid;
std::shared_ptr<Solenoid> RobotMap::pivotStage2Solenoid;
std::shared_ptr<Solenoid> RobotMap::scalerStage1Solenoid;
std::shared_ptr<Solenoid> RobotMap::scalerStage2Solenoid;

std::shared_ptr<PowerDistributionPanel> RobotMap::pDPPowerDistributionPanel;
std::shared_ptr<Encoder> RobotMap::pivotEncoder;
std::shared_ptr<AnalogInput> RobotMap::sensorIRdSensor;
std::shared_ptr<AnalogInput> RobotMap::sensorIRdSensorFront;
std::shared_ptr<AnalogInput> RobotMap::sensorIRdSensorTower;
std::shared_ptr<AnalogInput> RobotMap::pressureSensor;
std::shared_ptr<AHRS> RobotMap::imu;


void RobotMap::init() {
    LiveWindow *lw = LiveWindow::GetInstance();

    driveTrainLeftTalon1.reset(new CANTalon(Preferences::GetInstance()->GetInt("DriveTrain::LeftTalon1::CANID",1)));
     lw->AddActuator("DriveTrain", "LeftTalon1", driveTrainLeftTalon1);

    driveTrainLeftTalon2.reset(new CANTalon(Preferences::GetInstance()->GetInt("DriveTrain::LeftTalon2::CANID",2)));
    lw->AddActuator("DriveTrain", "LeftTalon2", driveTrainLeftTalon2);

    driveTrainRightTalon1.reset(new CANTalon(Preferences::GetInstance()->GetInt("DriveTrain::RightTalon1::CANID",3)));
    lw->AddActuator("DriveTrain", "RightTalon1", driveTrainRightTalon1);
    
    driveTrainRightTalon2.reset(new CANTalon(Preferences::GetInstance()->GetInt("DriveTrain::RightTalon2::CANID",4)));
    lw->AddActuator("DriveTrain", "RightTalon2", driveTrainRightTalon2);

    driveTrainRobotDrive.reset(new RobotDrive(driveTrainLeftTalon1, driveTrainLeftTalon2,
              driveTrainRightTalon1, driveTrainRightTalon2));
    
    driveTrainRobotDrive->SetSafetyEnabled(false);
    driveTrainRobotDrive->SetExpiration(0.1);
    driveTrainRobotDrive->SetSensitivity(0.5);
    driveTrainRobotDrive->SetMaxOutput(1.0);
    driveTrainRobotDrive->SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
    driveTrainRobotDrive->SetInvertedMotor(RobotDrive::kRearLeftMotor, true);

    intakeTalon.reset(new CANTalon(Preferences::GetInstance()->GetInt("Intake::Talon::CANID",5)));
    lw->AddActuator("Intake", "IntakeTalon", intakeTalon);
    
    // Top and bottom in the shooter code are swapped.  Will address later when time permits.
    shooterTopTalon.reset(new CANTalon(Preferences::GetInstance()->GetInt("Shooter::TopTalon::CANID",8))); // Top Shooter
    lw->AddActuator("Shooter", "ShooterTop", shooterTopTalon);

    shooterBottomTalon.reset(new CANTalon(Preferences::GetInstance()->GetInt("Shooter::BottomTalon::CANID",9))); //Bottom Shooter
    lw->AddActuator("Shooter", "ShooterBottom", shooterBottomTalon);


    theCompressor.reset(new Compressor(Preferences::GetInstance()->GetInt("Compressor::PCMID",0)));

    scalerStage1Solenoid.reset(new Solenoid(Preferences::GetInstance()->GetInt("Scaler::PCMID",0),
    		Preferences::GetInstance()->GetInt("Scaler::Stage1::Channel",0)));
    lw->AddActuator("Scaler1", "scalerStage1", scalerStage1Solenoid);

    scalerStage2Solenoid.reset(new Solenoid(Preferences::GetInstance()->GetInt("Scaler::PCMID",0),
    		Preferences::GetInstance()->GetInt("Scaler::Stage2::ForwardChannel",1)));
    lw->AddActuator("Scaler2", "scalerStage2", scalerStage2Solenoid);

    stabilizerSolenoid.reset(new DoubleSolenoid(Preferences::GetInstance()->GetInt("Stabilizer::PCMID",0),
    		Preferences::GetInstance()->GetInt("Stabilizer::ForwardChannel",2),
			Preferences::GetInstance()->GetInt("Stabilizer::ReverseChannel",3)));
    lw->AddActuator("Stabilizer", "Stabilizer", stabilizerSolenoid);
    
    brakeSolenoid.reset(new Solenoid(Preferences::GetInstance()->GetInt("Brake::PCMID",0),
    		Preferences::GetInstance()->GetInt("Brake::Channel",4)));
    lw->AddActuator("Brake", "Brake", brakeSolenoid);

    pivotStage1Solenoid.reset(new Solenoid(Preferences::GetInstance()->GetInt("Pivot::PCMID",0),
    		Preferences::GetInstance()->GetInt("Pivot::Stage1::Channel",5)));
    lw->AddActuator("Pivot1", "PivotStage1", pivotStage1Solenoid);

    pivotStage2Solenoid.reset(new Solenoid(Preferences::GetInstance()->GetInt("Pivot::PCMID",0),
			Preferences::GetInstance()->GetInt("Pivot::Stage2::Channel",6)));
    lw->AddActuator("Pivot2", "PivotStage2", pivotStage2Solenoid);

    printf("RobotMap Pivot Complete\n");

    pivotEncoder.reset(new Encoder(Preferences::GetInstance()->GetInt("Pivot::Enc::ChannelA",8),
    		Preferences::GetInstance()->GetInt("Pivot::Enc::ChannelB",9),
			Preferences::GetInstance()->GetBoolean("Pivot::Enc::IsReversed",true),Encoder::EncodingType::k4X));
    lw->AddSensor("Intake", "PivotSensor", pivotEncoder);

    sensorIRdSensorTower.reset(new AnalogInput(1));
    lw->AddSensor("IR", "Tower", sensorIRdSensorTower);

    sensorIRdSensorFront.reset(new AnalogInput(2));
    lw->AddSensor("IR", "SensorFront", sensorIRdSensorFront);

    sensorIRdSensor.reset(new AnalogInput(3));
    lw->AddSensor("IR", "Sensor", sensorIRdSensor);

    pressureSensor.reset(new AnalogInput(0));
    lw->AddSensor("Air","Pressure", pressureSensor);

    pDPPowerDistributionPanel.reset(new PowerDistributionPanel(Preferences::GetInstance()->GetInt("PDP::CANID",0)));
    lw->AddSensor("PDP", "PowerDistributionPanel", pDPPowerDistributionPanel);
    
    imu.reset(new AHRS(SPI::Port::kMXP));
    lw->AddSensor("Sensor","IMU",imu);
}
