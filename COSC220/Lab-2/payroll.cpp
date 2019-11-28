#include "payroll.h" // Header file
#include <iostream>  // cout, endl
#include <string>

/* Ryan Rosiak
 *
 * Implementaion file for payroll.h:
 * 
*/ 

/* 
 * Default Constructor:
 * Initializes all members to default values.
*/
PayRoll::PayRoll() {
	name = "";
	payrate = 0;
	hours = 0.0;
}
/*
 * Constructor:
 * Takes a string and int as arguments and assigns them to 
 * name and payrate.
*/
PayRoll::PayRoll(std::string n, int pr) {
	name = n;
	payrate = pr;
}

/*
 * Setter:
 * Takes an double as an arugment and assigns it to hours
*/
void PayRoll::setHours(double h) {
	hours = h;
}

/*
 * Calculate Function:
 * Calculates the total pay by returning the value of hours
 * multiplied by pay
*/
double PayRoll::calculatePay() {
	return hours * payrate;
}

/*
 * PrintInfo Function:
 * Displays all possible info in given class
*/
void PayRoll::printInfo() {
	std::cout << "Name: " << name << std::endl;
	std::cout << "PayRate: " << payrate << std::endl;
	std::cout << "Hours: " << hours << std::endl;
	std::cout << "Total Pay: " << calculatePay() << std::endl;	
}

/*
 * Getter:
 * Returns a string that is the name of said object
*/
std::string PayRoll::getName() {
	return name;
}
