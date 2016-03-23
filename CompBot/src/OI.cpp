// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include <Commands/Pivot_Home.h>
#include <Commands/Scaler_Toggle.h>
#include "OI.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/Autonomous_Simple.h"
#include "Commands/Teleop_Drive.h"
#include "Commands/Toggle_Compressor.h"

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

#include "Commands/Drive_Turn.h"
#include "Commands/Drive_Straight.h"

#include "Commands/FireSequence.h"
#include "Commands/Intake_In.h"
#include "Commands/Intake_Out.h"
#include "Commands/Intake_Stop.h"
#include "Commands/Stabilizer_Toggle.h"

#include "Commands/Pivot_Home.h"
#include "Commands/Pivot_Intake.h"
#include "Commands/Pivot_Low.h"

#include "Commands/ConfigUpdate.h"
#include "Commands/Fire.h"

#include "Commands/Cal_Front_In.h"
#include "Commands/Cal_Front_Out.h"
#include "Commands/Cal_Shooter_In.h"
#include "Commands/Cal_Shooter_Out.h"
#include "Commands/Cal_Save.h"

#include "Commands/Select_Arcade.h"
#include "Commands/Select_Tank.h"
#include "Commands/Select_Split.h"

OI::OI() : Configurable("OI") {
    // Process operator interface input here.

	driverInterface.reset(new XBOX360_Controller("Driver",0));
	operatorInterface.reset(new XBOX360_Controller("Operator",1));

	CheckConfig("Dummy");
	Configure();

    SmartDashboard::PutData("Toggle_Compressor", new Toggle_Compressor());
    SmartDashboard::PutData("Select Arcade", new Select_Arcade());
    SmartDashboard::PutData("Select_Tank", new Select_Tank());
    SmartDashboard::PutData("Select_Split", new Select_Split());
    SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());
    SmartDashboard::PutData("Autonomous Simple", new Autonomous_Simple());
    SmartDashboard::PutData("Update Config", new ConfigUpdate());

    SmartDashboard::PutData("Drive Turn", new Drive_Turn(45.0));
    SmartDashboard::PutData("Drive Straight", new Drive_Straight(12.0));
    SmartDashboard::PutData("Fire", new Fire(true));

    operatorInterface->Assign_ButtonCommand(XBOX360_BUTTON::XBOX360_RIGHT_BUMPER, new Intake_In(),ButtonAction::ButtonAction_Pressed);
    operatorInterface->Assign_ButtonCommand(XBOX360_BUTTON::XBOX360_RIGHT_BUMPER, new Intake_Stop(),ButtonAction::ButtonAction_Released);

    operatorInterface->Assign_ButtonCommand(XBOX360_BUTTON::XBOX360_LEFT_BUMPER, new Intake_Out(),ButtonAction::ButtonAction_Pressed);
    operatorInterface->Assign_ButtonCommand(XBOX360_BUTTON::XBOX360_LEFT_BUMPER, new Intake_Stop(),ButtonAction::ButtonAction_Released);

    operatorInterface->Assign_ButtonCommand(XBOX360_BUTTON::XBOX360_Y, new Pivot_Home(),ButtonAction::ButtonAction_Pressed);
    operatorInterface->Assign_ButtonCommand(XBOX360_BUTTON::XBOX360_B, new Pivot_Intake(),ButtonAction::ButtonAction_Pressed);
    operatorInterface->Assign_ButtonCommand(XBOX360_BUTTON::XBOX360_A, new Pivot_Low(),ButtonAction::ButtonAction_Pressed);
    operatorInterface->Assign_ButtonCommand(XBOX360_BUTTON::XBOX360_X, new Scalar_Toggle(),ButtonAction::ButtonAction_Pressed);


    driverInterface->Assign_ButtonCommand(XBOX360_BUTTON::XBOX360_A, new Stabilizer_Toggle(),ButtonAction::ButtonAction_Pressed);

}

OI::~OI()
{

}

std::shared_ptr<XBOX360_Controller> OI::getDriverInterface(){
   return driverInterface;
}

std::shared_ptr<XBOX360_Controller> OI::getOperatorInterface(){
   return operatorInterface;
}

void OI::RetrieveConfig()
{
	Preferences::GetInstance()->GetFloat("OI::Dummy",0.5);
	driverInterface->RetrieveConfig();
	operatorInterface->RetrieveConfig();
}

void OI::Configure()
{
	driverInterface->Configure();
	operatorInterface->Configure();
}

void OI::SaveConfig()
{
	Preferences::GetInstance()->PutFloat("OI::Dummy",0.5);
	driverInterface->SaveConfig();
	operatorInterface->SaveConfig();
}

void OI::LiveConfigure()
{
	driverInterface->LiveConfigure();
	operatorInterface->LiveConfigure();
}
