#include "payroll.h"	// PayRoll Class
#include "PayRollList.h" // Linked List class
#include <iostream> 	// cout, cin, endl
#include <fstream> 	// ifstream

/*
 * Ryan Rosiak
 * COSC 220-001
 * Lab-3
 */ 

int main() {

	PayRollList list; 
	
	std::cout << "List 1: " << std::endl;

	list.printPayChecks();		// Example of empty list print out

	std::cout << "List 1 now being filled: " << std::endl;	// First test of inserting into linked list and then outputting to console

	list.insert("Ryan", 15.25, 10);		// Basic insert of of the linked list
	list.insert("John", 12, 25);
	list.insert("Skylar", 13, 20);
	list.insert("Bob", 20, 5);
	PayRoll mary("Mary", 16, 22);
	list.insert(mary);

	list.printPayChecks();	
	
	PayRollList list2;		// Second test of inserting into linked list and then outputting to console

	std::cout << "List 2: Will show step by step of insert" << std::endl;
	
	std::cout << "Insert 1: " << std::endl;
	list2.insert("Jake", 45, 10);
	list2.printPayChecks();

	PayRoll martha("Martha", 5.45, 19);
	PayRoll jenny("Jenny", 15.22, 15);
	PayRoll james("James", 48, 12);

	std::cout << "Insert 2: " << std::endl;		// Step by step output of where the objects are getting inserted
	list2.insert(martha);
	list2.printPayChecks();
	std::cout << "Insert 3: " << std::endl;
	list2.insert(jenny);
	list2.printPayChecks();
	std::cout << "Insert 4: " << std::endl;
	list2.insert(james);
	list2.printPayChecks();

	std::cout << "----------------File Portion----------------" << std::endl; // File is "employee.dat"
	
	std::ifstream datafile;
	datafile.open("employee.dat");	

	if (!datafile) {
		std::cout << "Error opening file. \n";
		return 1;
	}

	PayRoll parray[6];
	std::string n;
	double pr, hr;
	for (int i = 0; i < 6; i++) {		// Takes in input from structured .dat file
		datafile >> n;
		datafile >> pr;
		datafile >> hr;
		parray[i].setName(n);
		parray[i].setRate(pr);
		parray[i].setHours(hr);
	}
	datafile.close();

	PayRollList list3;		// Creates a third test list to store the array of objects taken from the file

	for (int i = 0; i < 6; i++) {
		list3.insert(parray[i]);
	}

	std::cout << "DataFile now apart of linked list: " << std::endl; // Shows linked list after array is input into it
	list3.printPayChecks();

	return 0;
}
