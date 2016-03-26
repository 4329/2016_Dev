#ifndef LOGGER_H
#define LOGGER_H
#include <string>
#include "WPILib.h"

class Logger
{
public:
	Logger();
	void StartLog();
	void StopLog();

	void Set_LoggingLevel(int level);

	void Info(std::string component, std::string sub, std::string message);
	void Warn(std::string component, std::string sub, std::string message);
	void Error(std::string component, std::string sub, std::string message);

	void Sensor(std::string sensor, float value);
	void Sensor(std::string sensor, int value);
	void Sensor(std::string sensor, bool value);

	void StartFrame(std::string tag);
	void EndFrame(std::string tag);

	const char s = ':';
protected:
	std::shared_ptr<Timer> _timer;
	int currentIndent;
	bool isLogging;
	double fpgaTime;
	int logLevel;

private:

};
#endif
