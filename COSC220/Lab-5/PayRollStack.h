#ifndef _PAYROLLSTACK_H_
#define _PAYROLLSTACK_H_
#include "payroll.h"
#include <iostream>

class PayRollStack {
private:
	struct StackNode {	// Node 
		PayRoll p;
		StackNode* next;
	};		
	
	StackNode* head;	// Bottom of the stack or head of linked list
public:
	PayRollStack(); 	// Default ctor
	~PayRollStack();	// Destructor
	PayRollStack(const PayRollStack&);	// Copy ctor
	PayRollStack operator=(const PayRollStack&);	// Oeverloaded assignment

	void push(PayRoll p);	// Adds object to stack 
	PayRoll pop();		// Same but uses a reference to the pop function
	void pop(PayRoll&);	// Returns a number of elements on the stack
	
	int size();	// Returns the number of elements on the stack
	void printStack(); // Prints the stack for testing purposes
};

#endif
