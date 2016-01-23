#ifndef CONFIGURABLE_H
#define CONFIGURABLE_H
class Configurable
{
public:
	virtual void RetrieveConfig() = 0;
	virtual void Configure() = 0;
	virtual void SaveConfig() = 0;
};
#endif
