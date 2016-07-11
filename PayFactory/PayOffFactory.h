#pragma once
#include "PayOff3.h"
#include <map>
#include <string>

// Singleton pattern
class PayOffFactory
{
public:
	// the typedef allows us to refer to pointers to functions
	// which take in a double and spit out a PayOff* as CreatePayOffFunction
	typedef PayOff* (*CreatePayOffFunction)(double);

	// a static function returns a static object, which will only be constructed once
	static PayOffFactory& Instance();
	void RegisterPayOff(std::string, CreatePayOffFunction);
	PayOff* CreatePayOff(std::string PayOffID, double Strike);
	~PayOffFactory() {};

private:
	std::map<std::string, CreatePayOffFunction> TheCreatorFunctions;
	PayOffFactory() {}
	// Keep the constructor and assignment function private
	// only allowing it called by static function Instance
	PayOffFactory(const PayOffFactory&) {}
	PayOffFactory& operator = (const PayOffFactory) { return *this; }
};