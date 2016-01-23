/*
 * Xbox360_Controller.cpp
 *
 *  Created on: Feb 26, 2015
 *      Author: Matthew
 */

#include "Xbox360_Controller.h"


XBOX360_Controller::XBOX360_Controller(const char *name, uint32_t port) :
		Joystick(port,8,10)
{
	m_Name = name;
	m_Port = port;

	m_RightStick 	= new JoystickButton(this, XBOX360_RIGHT_STICK);
	buttonMap[XBOX360_RIGHT_STICK] = m_RightStick;

	m_LeftStick	 	= new JoystickButton(this, XBOX360_LEFT_STICK);
	buttonMap[XBOX360_LEFT_STICK] = m_LeftStick;

	m_Back	 		= new JoystickButton(this, XBOX360_BACK);
	buttonMap[XBOX360_BACK] = m_Back;

	m_Start	 		= new JoystickButton(this, XBOX360_START);
	buttonMap[XBOX360_START] = m_Start;

	m_LeftBumper	= new JoystickButton(this, XBOX360_LEFT_BUMPER);
	buttonMap[XBOX360_LEFT_BUMPER] = m_LeftBumper;

	m_RightBumper	= new JoystickButton(this, XBOX360_RIGHT_BUMPER);
	buttonMap[XBOX360_RIGHT_BUMPER] = m_RightBumper;

	m_A				= new JoystickButton(this, XBOX360_A);
	buttonMap[XBOX360_A] = m_A;

	m_B				= new JoystickButton(this, XBOX360_B);
	buttonMap[XBOX360_B] = 	m_B;

	m_X				= new JoystickButton(this, XBOX360_X);
	buttonMap[XBOX360_X] = m_X;

	m_Y				= new JoystickButton(this, XBOX360_Y);
	buttonMap[XBOX360_Y] = m_Y;

	Assign_Move_SideToSide(XBOX360_LEFT_X);
	Assign_Move_FrontToBack(XBOX360_LEFT_Y);
	Assign_Yaw(XBOX360_RIGHT_X);

	RetrieveConfig();

}


XBOX360_Controller::~XBOX360_Controller()
{
	buttonMap.clear();
	delete m_RightStick;
	delete m_LeftStick;
	delete m_Back;
	delete m_Start;
	delete m_LeftBumper;
	delete m_RightBumper;
	delete m_A;
	delete m_X;
	delete m_B;
	delete m_Y;
}

void XBOX360_Controller::RetrieveConfig()
{
	LSxDZ = Preferences::GetInstance()->GetFloat("XBox::DeadZone::LeftStick::X",0.05);
	LSyDZ = Preferences::GetInstance()->GetFloat("XBox::DeadZone::LeftStick::Y",0.05);
	RSxDZ = Preferences::GetInstance()->GetFloat("XBox::DeadZone::RightStick::X",0.05);
	RSyDZ = Preferences::GetInstance()->GetFloat("XBox::DeadZone::RightStick::Y",0.05);
	LtrigDZ = Preferences::GetInstance()->GetFloat("XBox::DeadZone::LeftTrigger",0.05);
	RtrigDZ = Preferences::GetInstance()->GetFloat("XBox::DeadZone::RightTrigger",0.05);
}

void XBOX360_Controller::SaveConfig()
{
	Preferences::GetInstance()->PutFloat("XBox::DeadZone::LeftStick::X",LSxDZ);
	Preferences::GetInstance()->PutFloat("XBox::DeadZone::LeftStick::Y",LSyDZ);
	Preferences::GetInstance()->PutFloat("XBox::DeadZone::RightStick::X",RSxDZ);
	Preferences::GetInstance()->PutFloat("XBox::DeadZone::RightStick::Y",RSyDZ);
	Preferences::GetInstance()->PutFloat("XBox::DeadZone::LeftTrigger",LtrigDZ);
	Preferences::GetInstance()->PutFloat("XBox::DeadZone::RightTrigger",RtrigDZ);
}

void XBOX360_Controller::Configure()
{
	// Do Nothing.
}

void XBOX360_Controller::Set_DeadZones(float lxmin, float lymin, float rxmin, float rymin, float ltriggermin, float rtriggermin)
{
	LSxDZ = lxmin;
	LSyDZ = lymin;
	RSxDZ = rxmin;
	RSyDZ = rymin;
	LtrigDZ = ltriggermin;
	RtrigDZ = rtriggermin;
}

void XBOX360_Controller::Rumble_Left(float intensity)
{
	SetRumble(kLeftRumble, intensity);
}

void XBOX360_Controller::Rumble_Right(float intensity)
{
	SetRumble(kRightRumble, intensity);
}

void XBOX360_Controller::Assign_Move_FrontToBack(XBOX360_AXIS axis)
{
	SetAxisChannel(kYAxis,axis);
}

void XBOX360_Controller::Assign_Move_SideToSide(XBOX360_AXIS axis)
{
	SetAxisChannel(kXAxis,axis);
}

void XBOX360_Controller::Assign_Yaw(XBOX360_AXIS axis)
{
	SetAxisChannel(kTwistAxis,axis);
}

void XBOX360_Controller::Assign_ButtonCommand(XBOX360_BUTTON button, Command *command, ButtonAction action)
{
	switch (action)
	{
	case ButtonAction_Pressed:
		buttonMap[button]->WhenPressed(command);
		break;
	case ButtonAction_Held:
		buttonMap[button]->WhileHeld(command);
		break;
	case ButtonAction_Released:
		buttonMap[button]->WhenReleased(command);
		break;
	default:
		buttonMap[button]->WhenPressed(command);
		break;
	}
}

XBOX_AxisState XBOX360_Controller::Get_AxisState()
{
	XBOX_AxisState retval;
	retval.Raw_LX = ((GetRawAxis(XBOX360_LEFT_X)*GetRawAxis(XBOX360_LEFT_X)) > LSxDZ ) ? GetRawAxis(XBOX360_LEFT_X) : 0.0;
	retval.Raw_LY = ((GetRawAxis(XBOX360_LEFT_Y)*GetRawAxis(XBOX360_LEFT_Y)) > LSyDZ ) ? GetRawAxis(XBOX360_LEFT_Y) : 0.0;
	retval.Raw_RX = ((GetRawAxis(XBOX360_RIGHT_X)*GetRawAxis(XBOX360_RIGHT_X))> RSxDZ) ? GetRawAxis(XBOX360_RIGHT_X) : 0.0;
	retval.Raw_RY = ((GetRawAxis(XBOX360_RIGHT_Y)*GetRawAxis(XBOX360_RIGHT_Y))> RSyDZ) ? GetRawAxis(XBOX360_RIGHT_Y) : 0.0;
	retval.RTrigger = (GetRawAxis(XBOX360_RTRIGGER) > RtrigDZ) ? GetRawAxis(XBOX360_RTRIGGER) : 0.0;
	retval.LTrigger = (GetRawAxis(XBOX360_LTRIGGER) > LtrigDZ) ? GetRawAxis(XBOX360_LTRIGGER) : 0.0;
	retval.Magnitude = GetMagnitude();
	retval.RelativeHeading = GetDirectionDegrees();
	return retval;
}

XBOX_ButtonState XBOX360_Controller::Get_ButtonState()
{
	XBOX_ButtonState retval;
	retval.A = GetRawButton(XBOX360_A);
	retval.B = GetRawButton(XBOX360_B);
	retval.X = GetRawButton(XBOX360_X);
	retval.Y = GetRawButton(XBOX360_Y);
	retval.LeftBumper = GetRawButton(XBOX360_LEFT_BUMPER);
	retval.RightBumper = GetRawButton(XBOX360_RIGHT_BUMPER);
	retval.Back = GetRawButton(XBOX360_BACK);
	retval.Start = GetRawButton(XBOX360_START);
	retval.LeftStick = GetRawButton(XBOX360_LEFT_STICK);
	retval.RightStick = GetRawButton(XBOX360_RIGHT_STICK);
	return retval;
}

