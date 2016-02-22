// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef SCALE_H
#define SCALE_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class Scale: public Command {
public:
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR
	Scale(bool override = false);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=VARIABLES

	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=VARIABLES
	bool _override;
};

#endif