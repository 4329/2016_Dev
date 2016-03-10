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
#include "Commands/Cal_Front_In.h"
#include "Commands/Cal_Front_Out.h"
#include "Commands/Cal_Shooter_In.h"
#include "Commands/Cal_Shooter_Out.h"
#include "Commands/Cal_Save.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::shared_ptr<DriveTrain> Robot::driveTrain;
std::shared_ptr<Pneumatics> Robot::pneumatics;
std::shared_ptr<Intake> Robot::intake;
std::shared_ptr<Pivot> Robot::pivot;
std::shared_ptr<Scaler> Robot::scaler;
std::shared_ptr<PDP> Robot::pDP;
std::shared_ptr<TargettingAssist> Robot::targettingAssist;
std::shared_ptr<Shooter> Robot::shooter;
std::unique_ptr<OI> Robot::oi;
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::shared_ptr<Brake> Robot::brake;
std::shared_ptr<Video> Robot::video;
std::shared_ptr<Stabilizer> Robot::stabilizer;
std::shared_ptr<Sensors> Robot::sensorPkg;

std::shared_ptr<SendableChooser> Robot::autoChooser;
//std::shared_ptr<Sensor_Output> Robot::sensorOut;

void Robot::RobotInit() {
	RobotMap::init();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	sensorPkg.reset(new Sensors());
	driveTrain.reset(new DriveTrain());
    printf("Robot driveTrain Complete\n");
    pneumatics.reset(new Pneumatics());

    intake.reset(new Intake());
    printf("Robot intake Complete\n");
    pivot.reset(new Pivot());
    printf("Robot Pivot Complete\n");
    scaler.reset(new Scaler());
    pDP.reset(new PDP());
    targettingAssist.reset(new TargettingAssist());
    shooter.reset(new Shooter());

	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi.reset(new OI());
	printf("Robot OI Complete\n");
	brake.reset(new Brake());
    stabilizer.reset(new Stabilizer());

    video.reset(new Video());
    printf("Robot video Complete\n");
	// instantiate the command used for the autonomous period
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	autonomousCommand.reset(new AutonomousCommand());
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
/*
	driveTrain->RetrieveConfig();
    driveTrain->SaveConfig();

    intake->RetrieveConfig();
    intake->SaveConfig();

    pivot->RetrieveConfig();
    pivot->SaveConfig();

    shooter->RetrieveConfig();
    shooter->SaveConfig();

    printf("Robot shooter Complete\n");

    brake->RetrieveConfig();
    brake->SaveConfig();

    printf("Robot brake Complete\n");


    stabilizer->RetrieveConfig();
    stabilizer->SaveConfig();

    printf("Robot stabilizer Complete\n");

    sensorPkg->RetrieveConfig();
    sensorPkg->SaveConfig();

    printf("Robot sensor Complete\n");

    video->RetrieveConfig();
    video->SaveConfig();

    printf("Robot video Complete\n");

    oi->getDriverInterface()->RetrieveConfig();
    oi->getOperatorInterface()->RetrieveConfig();
    oi->getDriverInterface()->SaveConfig();
*/
    autoChooser.reset(new SendableChooser());
    autoChooser->AddDefault("Default Auto",autonomousCommand.get());
    SmartDashboard::PutData("Auto Mode Select:",autoChooser.get());

    sensorOut.reset(new Sensor_Output());

  }

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	autonomousCommand.reset((Command*) autoChooser->GetSelected());
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Cancel();
	sensorOut->Start();

}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
    SmartDashboard::PutData("Set Front In", new Cal_Front_In());
    SmartDashboard::PutData("Set Front Out", new Cal_Front_Out());
    SmartDashboard::PutData("Set Shooter In", new Cal_Shooter_In());
    SmartDashboard::PutData("Set Shooter Out", new Cal_Shooter_Out());
    SmartDashboard::PutData("Calibration Save", new Cal_Save());
	lw->Run();
}

START_ROBOT_CLASS(Robot);

