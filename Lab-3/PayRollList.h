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
	void insert(std::string, double, double); // insert into linked list using 3 parameters
	void insert(PayRoll);	// insert into linked list using PayRoll object
	void printPayChecks(); // Print function for all items in linked list
};


#endif
