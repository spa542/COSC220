#include "Hourly.h"

/*
 * Non-Default Constructor
 * Initializes all private members
 */
Hourly::Hourly(std::string empName, double rate) : Employee(empName, rate) {
	hoursWorked = 0;
}

/*
 * addHours Function
 * Adds passed float to  hoursWorked
 */
void Hourly::addHours(float add) {
	hoursWorked += add;
}

/*
 * pay Function
 * Overrides pay() parent function and returns hoursWorked time payRate
 */
double Hourly::pay() {
	return payRate * hoursWorked;
}

/*
 * print Function
 * Overrides the print() parent function and prints out all info
 */
void Hourly::print() const {
	Employee::print();
	std::cout << "Worked " << hoursWorked << " hour(s)" << std::endl;
}
