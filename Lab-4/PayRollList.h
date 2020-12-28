#ifndef _PAYROLLLIST_H
#define _PAYROLLLIST_H
#include "payroll.h"
#include <string>
#include <iostream>

class PayRollList {

private:
	struct ListNode {	// nodes for linked list
		PayRoll p;
		ListNode* next;	
	};
	
	ListNode* head; // head of linked list

public:
	PayRollList(); // Default ctor
	~PayRollList();	// Destructor
	PayRollList(PayRollList&); // Copy Constructor
	
	int length(); // Returns length of list
	PayRoll* operator[](int); // Overloaded index operator
	void remove(int); // Removes the list item at the specified position
	void assign(int, PayRoll); // Copys a PayRoll into a specific position
	void insert(int, PayRoll); // inserts a PayRoll into the list at the specified position
	void insert(std::string, double, double); // insert into linked list using 3 parameters
	void insert(PayRoll);	// insert into linked list using PayRoll object
	void printPayChecks(); // Print function for all items in linked list
	
};


#endif
