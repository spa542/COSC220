#ifndef _EXECUTIVE_
#define _EXECUTIVE_
#include "Employee.h"
#include <iostream>

class Executive : public Employee {
	private:
		double bonus;
	public:
		Executive(std::string, double, double); // Non-Default Ctor
		void setBonus(double); // Sets the bonus for the executive
		double pay() override; // Overrides the pay() parent method and returns the total pay
		void print() const override; // Overrides the print() parent method and prints the Executive info	

};

#endif
