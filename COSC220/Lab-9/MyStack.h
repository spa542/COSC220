#ifndef _PAYROLLSTACK_H_
#define _PAYROLLSTACK_H_
#include "payroll.h"
#include <iostream>

template<class T>
class MyStack {
private:
	struct StackNode {	// Node 
		T data;
		StackNode* next;
	};		
	
	StackNode* head;	// Bottom of the stack or head of linked list
public:
	MyStack(); 	// Default ctor
	~MyStack();	// Destructor
	MyStack(const MyStack&);	// Copy ctor
	MyStack operator=(const MyStack&);	// Oeverloaded assignment
	void printStack(); 	// Prints the data members of the stack
	void push(T obj);	// Adds object to stack 
	T pop();		// Same but uses a reference to the pop function
	T peek(); 	// Shows the item on the top of the stack
};


/* Default Ctor:
 * Initializes all values to nullptr
 */
template<class T>
MyStack<T>::MyStack() {
	head = nullptr;
}

/* Destructor:
 * Deletes dynamically allocated data
 */
template<class T>
MyStack<T>::~MyStack() {
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
template<class T>
MyStack<T>::MyStack(const MyStack& rhs) {
	head = nullptr;
	StackNode* rhsCursor = rhs.head;
	while (rhsCursor) {
		push(rhsCursor->data);
		rhsCursor = rhsCursor->next;
	}	
}

/* Overloaded Assignment:
 * Allows the user to assign one stack to another
 */
template<class T>
MyStack<T> MyStack<T>::operator=(const MyStack& rhs) {
	if (this == &rhs) {
		std::cout << "Cannot assign, Objects are identical" << std::endl;
		return *this;
	}
	
	if (head != nullptr) {
		StackNode* cursor = head;
		while (cursor) {
			cursor = cursor->next;
			delete head;
			head = cursor;
		}
		head = nullptr;
	}	
	
	StackNode* rhsCursor = rhs.head;
	while (rhsCursor) {
		push(rhsCursor->data);
		rhsCursor = rhsCursor->next;
	}	
	return *this;
}

/* Push Function:
 * Adds an object to the stack
 */
template<class T>
void MyStack<T>::push(T obj) {
	StackNode* newNode = new StackNode;
	newNode->data = obj;
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
template<class T>
T MyStack<T>::pop() {
	if (head == nullptr) {
		std::cout << "Cannot pop, stack is empty" << std::endl;
		T obj;
		return obj;
	}

	if (head->next == nullptr) {
		StackNode* temp = head;
		head = nullptr;
		T obj = temp->data;
		delete temp;
		return obj;
	}

	StackNode* cursor = head;
	StackNode* previous = head;
	while (cursor->next) {
		previous = cursor;
		cursor = cursor->next;
	}	
	previous->next = nullptr;
	T rtnObj = cursor->data;
	delete cursor;
	return rtnObj;
}

/* PrintStack Function:
 * Prints the stack to the screen for testing and visual output
 */
template<class T>
void MyStack<T>::printStack() {
	if (head == nullptr) {
		std::cout << "The list is empty" << std::endl;
		return;
	}
	StackNode* cursor = head;
	std::cout << "Bottom\n" << std::endl;
	std::cout << cursor->data << std::endl;
	while (cursor->next) {
		cursor = cursor->next;
		std::cout << cursor->data << std::endl;
	}
	std::cout << "Top\n" << std::endl;
}

/* Peek Function:
 * Shows the top item on the stack
 */
template<class T>
T MyStack<T>::peek() {
	if (head == nullptr) {
		std::cout << "The stack is empty" << std::endl;
		T ded;
		return ded;
	}
	StackNode* cursor = head;
	while (cursor->next) {
		cursor = cursor->next;
	}
	auto rtnMe = cursor->data;
	return rtnMe;
}

#endif
