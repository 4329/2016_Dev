/*
 * Xbox360_Controller.h
 *
 *  Created on: Feb 26, 2015
 *      Author: Matthew
 */

#ifndef XBOX360_CONTROLLER_H_
#define XBOX360_CONTROLLER_H_
#include "WPILib.h"
#include "Joystick.h"
#include <map>
#include "Configurable.h"

enum ButtonAction
{
	ButtonAction_Pressed,
	ButtonAction_Held,
    ButtonAction_Released,
	ButtonAction_end
};

/*
 * Driver Controller 0
 * y = 4
 * x = 3
 * a = 1
 * b = 2
 * rb = 6
 * lb = 5
 * start = 8
 * back = 7
 * rstick press = 10
 * lstick press = 9
 * rtrig = axis 3
 * ltrigger = axis 2
 * lstick front/back = axis 1
 * lstick side/side = axis 0
 * rstick front/back = axis 5
 * rstick side/side = axis 4
 *
 */



enum XBOX360_BUTTON
{
	XBOX360_A 				= 1,
	XBOX360_B 				= 2,
	XBOX360_X 				= 3,
	XBOX360_Y 				= 4,
	XBOX360_LEFT_BUMPER 	= 5,
	XBOX360_RIGHT_BUMPER 	= 6,
	XBOX360_BACK 			= 7,
	XBOX360_START 			= 8,
	XBOX360_LEFT_STICK 		= 9,
	XBOX360_RIGHT_STICK 	= 10,
	XBOX360_BUTTON_END 		= 11
};

enum XBOX360_AXIS
{
	XBOX360_LEFT_X 		= 0,
	XBOX360_LEFT_Y 		= 1,
	XBOX360_LTRIGGER 	= 2,
	XBOX360_RTRIGGER	= 3,
	XBOX360_RIGHT_X 	= 4,
	XBOX360_RIGHT_Y 	= 5,
	XBOX360_DPAD_X 		= 6,
	XBOX360_DPAD_Y 		= 7,
	XBOX360_AXIS_END 	= 8
};

typedef struct XBOX_AxisState
{
	float Raw_LX;
	float Raw_LY;
	float Raw_RX;
	float Raw_RY;
	float LTrigger;
	float RTrigger;
	int   DPAD_X;  // Not Implemented Yet
	int   DPAD_Y;  // Not Implemented Yet
	float RelativeHeading;
	float Magnitude;
} XBOX_AxisState;

typedef struct XBOX_ButtonState
{
	bool A;
	bool B;
	bool X;
	bool Y;
	bool LeftBumper;
	bool RightBumper;
	bool Back;
	bool Start;
	bool LeftStick;
	bool RightStick;
} XBOX_ButtonState;


class XBOX360_Controller : public Joystick, public Configurable
{
public:
	XBOX360_Controller(const char *name, uint32_t port);
	virtual ~XBOX360_Controller();
	virtual void RetrieveConfig();
	virtual void Configure();
	virtual void SaveConfig();

	void Set_DeadZones(float lxmin, float lymin, float rxmin, float rymin, float ltriggermin, float rtriggermin);

	void Rumble_Left(float intensity);
	void Rumble_Right(float intensity);

	void Assign_Move_FrontToBack(XBOX360_AXIS axis);
	void Assign_Move_SideToSide(XBOX360_AXIS axis);
	void Assign_Yaw(XBOX360_AXIS axis);
	void Assign_ButtonCommand(XBOX360_BUTTON button, Command *command, ButtonAction action = ButtonAction_Pressed);

	XBOX_AxisState Get_AxisState();
	XBOX_ButtonState Get_ButtonState();

private:
	std::string 	m_Name;
	uint32_t		m_Port;

	JoystickButton* m_RightStick;
	JoystickButton* m_LeftStick;
	JoystickButton* m_Back;
	JoystickButton* m_Start;
	JoystickButton* m_LeftBumper;
	JoystickButton* m_RightBumper;
	JoystickButton* m_A;
	JoystickButton* m_X;
	JoystickButton* m_B;
	JoystickButton* m_Y;
	float			LSxDZ, LSyDZ, RSxDZ, RSyDZ, LtrigDZ, RtrigDZ;

    std::map<int,JoystickButton*> buttonMap;
};

#endif /* XBOX360_CONTROLLER_H_ */
