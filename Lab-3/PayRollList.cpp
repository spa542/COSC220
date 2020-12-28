#include "PayRollList.h"

/*
 * Default Constructor
 * Takes no parameters and initializes head pointer to null
 */
PayRollList::PayRollList() {
	head = nullptr;
}

/*
 * Insert Function:
 * Takes name, rate, and hours worked as parameters for a new ListNode.
 * Then calls overidden insert function to insert in order of payrate.
 */
void PayRollList::insert(std::string n, double pr, double h) {
	PayRoll input(n, pr, h);
	insert(input);
}

/*
 * Overidden insert: 
 * Takes a PayRoll object directly.
 * Then, inserts the object into the linked list by order of payrate.
 */
void PayRollList::insert(PayRoll newP) {
	ListNode* newNode = new ListNode;
	newNode->p.setName(newP.getName());
	newNode->p.setRate(newP.getRate());
	newNode->p.setHours(newP.getHours());
	newNode->next = nullptr;
	
	if (head == nullptr) {
		head = newNode;
		return;
	}
	
	if (head->p.getRate() < newNode->p.getRate()) {
		ListNode* temp = head;
		head = newNode;
		newNode = temp;
		head->next = newNode;
		return;
	}

	ListNode* cursor = head;
	while (cursor->next != nullptr) {
		ListNode* forward = cursor->next;
		if ((cursor->p.getRate() > newNode->p.getRate()) && (forward->p.getRate() < newNode->p.getRate())) {
			cursor->next = newNode;
			newNode->next = forward;
			return;
		}
		
		cursor = cursor->next;
	}
	cursor->next = newNode;
}

/*
 * PrintPayChecks Function:
 * Prints each employee name and total pay out.
 */
void PayRollList::printPayChecks() {
	if (head == nullptr) {
		std::cout << "The list is empty" << std::endl;
		return;
	}

	ListNode* cursor = head;
	while (cursor) {
		cursor->p.printInfo();
		std::cout << std::endl;
		cursor = cursor->next;
	}
}

/*
 * PayRollList Destructor:
 * Destroys dynamically allocated data
 */
PayRollList::~PayRollList() {
	if (head == nullptr) {
		return;
	}
	ListNode* cursor = head;
	while (cursor) {
		cursor = cursor->next;
		delete head;
		head = cursor;
	}
}
