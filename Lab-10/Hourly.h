#ifndef _HOURLY_
#define _HOURLY_
#include "Employee.h"
#include <iostream>

class Hourly : public Employee {
	private:
		float hoursWorked;
	public:
		Hourly(std::string, double); // Non-Default Ctor
		void addHours(float); // Adds passed float to hoursWorked
		double pay() override; // Overrides pay() parent function and returns hoursWorked times payRate
		void print() const override; // Overrides print() parent function and prints out all info
};

#endif
