#ifndef CONFIGURABLE_H
#define CONFIGURABLE_H
#include <string>



class Configurable
{
public:
	Configurable(std::string prefix);
	virtual ~Configurable();
	virtual void RetrieveConfig() = 0;
	virtual void Configure() = 0;
	virtual void SaveConfig() = 0;
	virtual void CreateConfig() = 0;
	bool ConfigExists();
	const std::string prefSep = "::";
protected:
	std::string _prefix;
};
#endif
