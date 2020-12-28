#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_
#include <iostream> // cout, endl

class Employee {
	protected:
		double payRate;
		std::string name;
	public:
		Employee(); // Default Ctor
		Employee(std::string, double); // Non-Default Ctor
		virtual double pay();	// Returns the amount the employee should be paid
		virtual void print() const;	// Prints to stdout the employee information
};

#endif
