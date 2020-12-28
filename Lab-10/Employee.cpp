#include "Employee.h"


/*
 * Default Constructor:
 * Initializes all values to base
 */
Employee::Employee() {
	name = "";
	payRate = 0;
}

/*
 * Non-Default Constructor:
 * Initializes all protected members of the employee class
 */
Employee::Employee(std::string empName, double empRate) {
	name = empName;
	payRate = empRate;
}

/*
 * pay Function:
 * Returns the amount the employee should be paid
 */
double Employee::pay() {
	return payRate;		
}

/*
 * print Function:
 * Prints to stdout the employee information
 */
void Employee::print() const {
	std::cout << name << "'s payrate is " << payRate << std::endl;	
}
