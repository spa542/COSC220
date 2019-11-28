#include "PayRollStack.h"

/* Default Ctor:
 * Initializes all values to nullptr
 */
PayRollStack::PayRollStack() {
	head = nullptr;
}

/* Destructor:
 * Deletes dynamically allocated data
 */
PayRollStack::~PayRollStack() {
	if (head == nullptr) {
		return;
	}
	StackNode* cursor = head;
	while (cursor) {
		cursor = cursor->next;
		delete head;
		head = cursor;
	}	
}

/* Copy Ctor:
 * Copies all elements of linked list stack over to another
 */
PayRollStack::PayRollStack(const PayRollStack& rhs) {
	head = nullptr;
	StackNode* rhsCursor = rhs.head;
	while (rhsCursor) {
		push(rhsCursor->p);
		rhsCursor = rhsCursor->next;
	}	
}

/* Overloaded Assignment:
 * Allows the user to assign one stack to another
 */
PayRollStack PayRollStack::operator=(const PayRollStack& rhs) {
	if (this == &rhs) {
		std::cout << "Cannot assign, Objects are identical" << std::endl;
		return *this;
	}		
	
	StackNode* rhsCursor = rhs.head;
	while (rhsCursor) {
		push(rhsCursor->p);
		rhsCursor = rhsCursor->next;
	}	
	return *this;
}

/* Push Function:
 * Adds an object to the stack
 */
void PayRollStack::push(PayRoll obj) {
	StackNode* newNode = new StackNode;
	newNode->p = obj;
	newNode->next = nullptr;
	
	if (head == nullptr) {
		head = newNode;
		return;
	}	
	
	StackNode* cursor = head;
	while (cursor->next) {
		cursor = cursor->next;	
	}
	cursor->next = newNode;
}

/* Pop Function:
 * Returns the number of elements on the stack
 */
PayRoll PayRollStack::pop() {
	if (head == nullptr) {
		std::cout << "Cannot pop, stack is empty" << std::endl;
		PayRoll obj;
		return obj;
	}

	if (head->next == nullptr) {
		StackNode* temp = head;
		delete temp;
		head = nullptr;
		PayRoll obj;
		return obj;
	}

	StackNode* cursor = head;
	StackNode* previous = head;
	while (cursor->next) {
		previous = cursor;
		cursor = cursor->next;
	}	
	previous->next = nullptr;
	PayRoll rtnObj = cursor->p;
	delete cursor;
	return rtnObj;
}

/* Overloaded Pop Function:
 * Same as previous pop function, only implements using a reference to 
 * the object that is popped off the stack
 */
void PayRollStack::pop(PayRoll& obj) {
	obj = pop();
}

/* Size Function:
 * Returns the number of elements on the stack
 */
int PayRollStack::size() {
	if (head == nullptr) {
		return 0;		
	}	
	StackNode* cursor = head;
	int counter = 0;
	while (cursor) {
		counter++;
		cursor = cursor->next;
	}		 
	return counter;
}

/* PrintStack Function:
 * Prints the stack to the screen for testing and visual output
 */
void PayRollStack::printStack() {
	std::cout << "|Bottom|" << std::endl;
	std::cout << "==========================" << std::endl;
	if (head != nullptr) {
		StackNode* cursor = head;
		while (cursor) {
			cursor->p.printInfo();
			cursor = cursor->next;
			std::cout << "==========================" << std::endl;
		}		
		std::cout << "|Top|\n" << std::endl;
	} else {
		std::cout << "|Top|" << std::endl;
		std::cout << "==========================" << std::endl;
	}
}
