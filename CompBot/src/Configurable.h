#ifndef CONFIGURABLE_H
#define CONFIGURABLE_H
#include <string>



class Configurable
{
public:
	Configurable(std::string prefix);
	virtual ~Configurable();
	virtual void RetrieveConfig() = 0; // Obtain Configuration.
	virtual void Configure() = 0;      // Configure when disabled at first start.
	virtual void LiveConfigure() = 0;  // Configure while running robot.  Might be limited parameters.
	virtual void SaveConfig() = 0;     // Save configuration parameters to networktable.ini
	void CheckConfig(std::string theKey); // Use the specified key to determine if any configuration exists.  Create if not.
	bool ConfigExists(std::string theKey);  // Determines if key, with prefix appended, exists.
	const std::string prefSep = "::";
protected:
	std::string _prefix;
};
#endif
