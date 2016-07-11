#pragma once
#include "PayOff3.h"
#include <map>
#include <string>

class PayOffFactory
{
public:
	// the typedef allows us to refer to pointers to functions
	// which take in a double and spit out a PayOff* as CreatePayOffFunction
	typedef PayOff* (*CreatePayOffFunction)(double);

	static PayOffFactory& Instance();
	void RegisterPayOff(std::string, CreatePayOffFunction);
	PayOff* CreatePayOff(std::string PayOffID, double Strike);
	~PayOffFactory() {};

private:
	std::map<std::string, CreatePayOffFunction> TheCreatorFunctions;
	PayOffFactory() {}
	PayOffFactory(const PayOffFactory&) {}
	PayOffFactory& operator = (const PayOffFactory) { return *this; }
};