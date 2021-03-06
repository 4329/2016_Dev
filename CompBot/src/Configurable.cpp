/*
 * Configurable.cpp
 *
 *  Created on: Jan 24, 2016
 *      Author: matt
 */
#include "Configurable.h"
#include "wpilib.h"

Configurable::Configurable(std::string prefix)
{
	_prefix = prefix;
}

Configurable::~Configurable()
{
	// Do nothing
}

bool Configurable::ConfigExists(std::string theKey)
{
	return Preferences::GetInstance()->ContainsKey(_prefix + prefSep + theKey);
}

void Configurable::CheckConfig(std::string theKey)
{
	this->RetrieveConfig();
	if (!ConfigExists(theKey)) this->SaveConfig();
}
