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
#include <Commands/ScalerStage1.h>
#include <Commands/ScalerStage2.h>
#include "OI.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/ScaleSequence.h"
#include "Commands/TargetAssist_Active.h"
#include "Commands/Teleop_Drive.h"
#include "Commands/Toggle_Compressor.h"
#include "Commands/Toggle_TargettingAssist.h"

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

#include "Commands/FireSequence.h"
#include "Commands/Intake_In.h"
#include "Commands/Intake_Out.h"
#include "Commands/Intake_Stop.h"
#include "Commands/Stabilizer_Toggle.h"

#include "Commands/Pivot_Home.h"
#include "Commands/Pivot_Intake.h"
#include "Commands/Pivot_Low.h"

#include "Commands/BrakeCmd.h"
#include "Commands/SwitchCam.h"
#include "Commands/ConfigUpdate.h"


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

	if (!ConfigExists()) CreateConfig();

    RetrieveConfig();
	Configure();

	driverInterface.reset(new XBOX360_Controller("Driver",0));
	operatorInterface.reset(new XBOX360_Controller("Operator",1));
    
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

    // SmartDashboard Buttons
    //SmartDashboard::PutData("ScaleSequence", new ScaleSequence());
    //SmartDashboard::PutData("Toggle_TargettingAssist", new Toggle_TargettingAssist());
    //SmartDashboard::PutData("TargetAssist_Active", new TargetAssist_Active());
    SmartDashboard::PutData("Toggle_Compressor", new Toggle_Compressor());
    SmartDashboard::PutData("Select Arcade", new Select_Arcade());
    SmartDashboard::PutData("Select_Tank", new Select_Tank());
    SmartDashboard::PutData("Select_Split", new Select_Split());
    SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());
    SmartDashboard::PutData("Switch Cam", new SwitchCam());
    SmartDashboard::PutData("Update Config", new ConfigUpdate());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

    operatorInterface->Assign_ButtonCommand(XBOX360_BUTTON::XBOX360_RIGHT_BUMPER, new Intake_In(),ButtonAction::ButtonAction_Pressed);
    operatorInterface->Assign_ButtonCommand(XBOX360_BUTTON::XBOX360_RIGHT_BUMPER, new Intake_Stop(),ButtonAction::ButtonAction_Released);

    operatorInterface->Assign_ButtonCommand(XBOX360_BUTTON::XBOX360_LEFT_BUMPER, new Intake_Out(),ButtonAction::ButtonAction_Pressed);
    operatorInterface->Assign_ButtonCommand(XBOX360_BUTTON::XBOX360_LEFT_BUMPER, new Intake_Stop(),ButtonAction::ButtonAction_Released);

    operatorInterface->Assign_ButtonCommand(XBOX360_BUTTON::XBOX360_Y, new Pivot_Home(),ButtonAction::ButtonAction_Pressed);
    operatorInterface->Assign_ButtonCommand(XBOX360_BUTTON::XBOX360_B, new Pivot_Intake(),ButtonAction::ButtonAction_Pressed);
    operatorInterface->Assign_ButtonCommand(XBOX360_BUTTON::XBOX360_A, new Pivot_Low(),ButtonAction::ButtonAction_Pressed);

    driverInterface->Assign_ButtonCommand(XBOX360_BUTTON::XBOX360_A, new Stabilizer_Toggle(),ButtonAction::ButtonAction_Pressed);
/*
    SmartDashboard::PutData("Set Front In", new Cal_Front_In());
    SmartDashboard::PutData("Set Front Out", new Cal_Front_Out());
    SmartDashboard::PutData("Set Shooter In", new Cal_Shooter_In());
    SmartDashboard::PutData("Set Shooter Out", new Cal_Shooter_Out());
    SmartDashboard::PutData("Calibration Save", new Cal_Save());
*/
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
}

void OI::Configure()
{
}

void OI::SaveConfig()
{
}

void OI::CreateConfig()
{
}
