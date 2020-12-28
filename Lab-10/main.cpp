#include <iostream> // cout, endl
#include <stdio.h> // printf
#include "Employee.h" // Employee class
#include "Executive.h" // Executive class
#include "Hourly.h" // Hourly class

int main() {

	std::cout << "Basic Employee Tests: " << std::endl; // Employee tests
	Employee gen1("Ryan", 10.25);
	std::cout << "Printed Info: " << std::endl;
	gen1.print();
	std::cout << "The returned payrate from the pay() function is: " << gen1.pay() << std::endl;
	std::cout << "===============================================\n" << std::endl;	

	std::cout << "Basic Hourly Tests: " << std::endl; // Hourly Tests
	Hourly hour("Skylar", 15.65);
	std::cout << "Print off initialization: " << std::endl;
	hour.print();
	std::cout << "Adding some hours worked.... " << std::endl;
	hour.addHours(40.5);
	std::cout << "Printing now: " << std::endl;
	hour.print();
	std::cout << "The returned payrate form the pay() function is: " << hour.pay() << std::endl;
	std::cout << "===============================================\n" << std::endl;	
	
	std::cout << "Basic Executive Tests: " << std::endl; // Executive Tests
	Executive exec("Mary", 40.5, 125000);
	std::cout << "Printed Info: " << std::endl;
	exec.print();
	std::cout << "Setting a new bonus...." << std::endl;
	exec.setBonus(500000);
	exec.print();
	std::cout << "The returned payrate from the pay() function is: " << exec.pay() << std::endl;	
	std::cout << "===============================================\n" << std::endl;	
	
	std::cout << "Starting Employee pointer array tests: " << std::endl; 
	Employee* empArr[3];
	Employee* emp1 = new Employee("James", 10.25);
	Employee* emp2 = new Hourly("Fred", 19.26);
	Employee* emp3 = new Executive("Charles", 12.6, 750000);
	empArr[0] = emp1;
	empArr[1] = emp2;
	empArr[2] = emp3;
	
        std::cout << "Basic Employee Tests: " << std::endl; // Employee pointer tests
        std::cout << "Printed Info: " << std::endl;
       	empArr[0]->print(); 
        std::cout << "The returned payrate from the pay() function is: " << empArr[0]->pay() << std::endl;
        std::cout << "===============================================\n" << std::endl;

        std::cout << "Basic Hourly Tests: " << std::endl; // Hourly pointer tests
        std::cout << "Print off initialization: " << std::endl;
        empArr[1]->print();
        std::cout << "Adding some hours worked.... " << std::endl;
        ((Hourly*)empArr[1])->addHours(61.2);
        std::cout << "Printing now: " << std::endl;
        empArr[1]->print();
        std::cout << "The returned payrate form the pay() function is: " << empArr[1]->pay() << std::endl;
        std::cout << "===============================================\n" << std::endl;

        std::cout << "Basic Executive Tests: " << std::endl; // Executive pointer tests
        std::cout << "Printed Info: " << std::endl;
        empArr[2]->print();
        std::cout << "Setting a new bonus...." << std::endl;
        ((Executive*)empArr[2])->setBonus(1250000);
        empArr[2]->print();
        std::cout << "The returned payrate from the pay() function is: " << empArr[2]->pay() << std::endl;
        std::cout << "===============================================\n" << std::endl;
	delete empArr[0];
	delete empArr[1];
	delete empArr[2];
	return 0;
}
