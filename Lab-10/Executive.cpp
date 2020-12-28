#include "Executive.h"

/*
 * Non-Default Constructor
 * Initializes all private members
 */
Executive::Executive(std::string empName, double rate, double bon) : Employee(empName, rate) {
	bonus = bon;
}

/*
 * setBonus Function
 * Sets the bonus for the executive
 */
void Executive::setBonus(double bon) {
	bonus = bon;
}

/*
 * pay Function
 * Overrides the pay() parent method and returns the total pay
 */
double Executive::pay() {
	double total =  Employee::pay() + bonus;
	bonus = 0;
	return total;	
}

/*
 * print Function
 * Overrides the print() parent method and prints the Executive info
 */
void Executive::print() const {
	Employee::print();
	std::cout << "Bonus: " << bonus << std::endl;
}
