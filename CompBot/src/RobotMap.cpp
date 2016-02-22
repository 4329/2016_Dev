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


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
std::shared_ptr<CANTalon> RobotMap::driveTrainRightTalon2;
std::shared_ptr<CANTalon> RobotMap::driveTrainRightTalon1;
std::shared_ptr<CANTalon> RobotMap::driveTrainLeftTalon2;
std::shared_ptr<CANTalon> RobotMap::driveTrainLeftTalon1;
std::shared_ptr<RobotDrive> RobotMap::driveTrainRobotDrive;
std::shared_ptr<Compressor> RobotMap::pneumaticsCompressor;
std::shared_ptr<CANTalon> RobotMap::intakeIntakeTalon1;

std::shared_ptr<CANTalon> RobotMap::shooterTalon1;
std::shared_ptr<CANTalon> RobotMap::shooterTalon2;

std::shared_ptr<CANTalon> RobotMap::intakePivotTalon;

std::shared_ptr<DoubleSolenoid> RobotMap::scalerScalerDblSolenoid;
std::shared_ptr<PowerDistributionPanel> RobotMap::pDPPowerDistributionPanel;
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

std::shared_ptr<AnalogInput> RobotMap::sensorIRdSensor;
std::shared_ptr<AnalogInput> RobotMap::sensorIRdSensorFront;
std::shared_ptr<Solenoid> RobotMap::brakeSolenoid;
std::shared_ptr<DoubleSolenoid> RobotMap::scalerLiftDblSolenoid;

void RobotMap::init() {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    LiveWindow *lw = LiveWindow::GetInstance();
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

    sensorIRdSensor.reset(new AnalogInput(3));
    lw->AddSensor("IR", "Sensor", sensorIRdSensor);

    sensorIRdSensorFront.reset(new AnalogInput(0));
    lw->AddSensor("IR", "SensorFront", sensorIRdSensorFront);

    driveTrainRightTalon2.reset(new CANTalon(Preferences::GetInstance()->GetInt("DriveTrain::RightTalon2::CANID",4)));
    lw->AddActuator("DriveTrain", "RightTalon2", driveTrainRightTalon2);
    
    driveTrainRightTalon1.reset(new CANTalon(Preferences::GetInstance()->GetInt("DriveTrain::RightTalon1::CANID",3)));
    lw->AddActuator("DriveTrain", "RightTalon1", driveTrainRightTalon1);
    
    driveTrainLeftTalon2.reset(new CANTalon(Preferences::GetInstance()->GetInt("DriveTrain::LeftTalon2::CANID",2)));
    lw->AddActuator("DriveTrain", "LeftTalon2", driveTrainLeftTalon2);
    
    driveTrainLeftTalon1.reset(new CANTalon(Preferences::GetInstance()->GetInt("DriveTrain::LeftTalon1::CANID",1)));
    lw->AddActuator("DriveTrain", "LeftTalon1", driveTrainLeftTalon1);
    
    driveTrainRobotDrive.reset(new RobotDrive(driveTrainLeftTalon1, driveTrainLeftTalon2,
              driveTrainRightTalon1, driveTrainRightTalon2));
    
    driveTrainRobotDrive->SetSafetyEnabled(false);
    driveTrainRobotDrive->SetExpiration(0.1);
    driveTrainRobotDrive->SetSensitivity(0.5);
    driveTrainRobotDrive->SetMaxOutput(1.0);
    driveTrainRobotDrive->SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
    driveTrainRobotDrive->SetInvertedMotor(RobotDrive::kRearLeftMotor, true);


    pneumaticsCompressor.reset(new Compressor(Preferences::GetInstance()->GetInt("Pneumatics::Compressor::PCMID",0)));
    
    
    intakeIntakeTalon1.reset(new CANTalon(Preferences::GetInstance()->GetInt("Intake::intakeTalon1::CANID",5)));
    lw->AddActuator("Intake", "IntakeTalon1", intakeIntakeTalon1);
    
    intakePivotTalon.reset(new CANTalon(Preferences::GetInstance()->GetInt("Intake::pivotTalon::CANID",6)));
    lw->AddActuator("Intake", "PivotTalon", intakePivotTalon);
    //intakePivotTalon->StopLiveWindowMode();


    shooterTalon1.reset(new CANTalon(Preferences::GetInstance()->GetInt("Shooter::shooterTalon1::CANID",8))); // Top Shooter
    lw->AddActuator("Shooter", "shooterTalon1", shooterTalon1);


    shooterTalon2.reset(new CANTalon(Preferences::GetInstance()->GetInt("Shooter::shooterTalon2::CANID",9))); //Bottom Shooter
    lw->AddActuator("Shooter", "shooterTalon2", shooterTalon2);
    
    
    scalerScalerDblSolenoid.reset(new DoubleSolenoid(Preferences::GetInstance()->GetInt("Scaler::Scaler::PCMID",0),
    		Preferences::GetInstance()->GetInt("Scaler::Scaler::ForwardChannel",0),
			Preferences::GetInstance()->GetInt("Scaler::Scaler::BackwardChannel",1)));

    scalerLiftDblSolenoid.reset(new DoubleSolenoid(Preferences::GetInstance()->GetInt("Scaler::Lift::PCMID",0),
    		Preferences::GetInstance()->GetInt("Scaler::Lift::ForwardChannel",2),
			Preferences::GetInstance()->GetInt("Scaler::Lift::BackwardChannel",3)));


    lw->AddActuator("Scaler", "ScalerDblSolenoid", scalerScalerDblSolenoid);
    
    brakeSolenoid.reset(new Solenoid(Preferences::GetInstance()->GetInt("Brake::PCMID",0),
    		Preferences::GetInstance()->GetInt("Brake::Channel",4)));

    lw->AddActuator("Brake", "brakeSolenoid", brakeSolenoid);


    pDPPowerDistributionPanel.reset(new PowerDistributionPanel(Preferences::GetInstance()->GetInt("PDP::CANID",0)));
    lw->AddSensor("PDP", "PowerDistributionPanel", pDPPowerDistributionPanel);
    

}
