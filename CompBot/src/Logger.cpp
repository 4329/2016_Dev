
#include "Logger.h"
#include "wpilib.h"
#include "Robot.h"
#include "RobotMap.h"

Logger::Logger()
{
	_timer.reset(new Timer());
	_timer->Start();
	isLogging = false;
	currentIndent = 0;
	fpgaTime = 0;
	logLevel = 0;
}

void Logger::Set_LoggingLevel(int level)
{
	logLevel = level;
}

void Logger::StartLog()
{
	isLogging = true;
}

void Logger::StopLog()
{
	isLogging = false;
}

void Logger::Info(std::string component, std::string sub, std::string message)
{
	if ((isLogging) && (logLevel >= 100))
	{
		fpgaTime = _timer->GetFPGATimestamp();
		printf("INFO: %f : %s : %s : %s\n",fpgaTime, component.c_str(), sub.c_str(), message.c_str());
	}
}

void Logger::Warn(std::string component, std::string sub, std::string message)
{
	if ((isLogging) && (logLevel >= 25))
	{
		fpgaTime = _timer->GetFPGATimestamp();
		printf("WARN: %f : %s : %s : %s\n",fpgaTime, component.c_str(), sub.c_str(), message.c_str());
	}

}

void Logger::Error(std::string component, std::string sub, std::string message)
{
	if ((isLogging)  && (logLevel > 0))
	{
		fpgaTime = _timer->GetFPGATimestamp();
		printf("ERROR: %f : %s : %s : %s\n",fpgaTime, component.c_str(), sub.c_str(), message.c_str());
	}

}

void Logger::Sensor(std::string sensor, float value)
{
	if ((isLogging) && (logLevel >= 50))
	{
		fpgaTime = _timer->GetFPGATimestamp();
		printf("SENSOR: %f : %s : %f \n",fpgaTime, sensor.c_str(), value);
	}

}

void Logger::Sensor(std::string sensor, int value)
{
	if ((isLogging) && (logLevel >= 50))
	{
		fpgaTime = _timer->GetFPGATimestamp();
		printf("SENSOR: %f : %s : %d \n",fpgaTime, sensor.c_str(), value);
	}

}

void Logger::Sensor(std::string sensor, bool value)
{
	if ((isLogging) && (logLevel >= 50))
	{
		fpgaTime = _timer->GetFPGATimestamp();
		printf("SENSOR: %f : %s : %d \n",fpgaTime, sensor.c_str(), value);
	}

}

void Logger::StartFrame(std::string tag)
{
	if (isLogging)
	{
		fpgaTime = _timer->GetFPGATimestamp();
		printf("FRAME: %f : %s \n{\n",fpgaTime, tag.c_str());
		currentIndent++;
	}

}

void Logger::EndFrame(std::string tag)
{
	if (isLogging)
	{
		fpgaTime = _timer->GetFPGATimestamp();
		printf("} %f : %s \n",fpgaTime, tag.c_str() );
		currentIndent--;
	}
}

