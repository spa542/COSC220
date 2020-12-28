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

/*
 * Copy Constructor:
 * Copys all items from a list into a another list
 */
PayRollList::PayRollList(PayRollList &rhs) {
	head = nullptr;
	ListNode* rhsCursor = rhs.head;
	while (rhsCursor) {
		insert(rhsCursor->p);
		rhsCursor = rhsCursor->next;
	}
}

/*
 * Length Function:
 * Returns the length of the current list
 */
int PayRollList::length() {
	int total = 0;
	if (head == nullptr) {
		return total;
	}
	ListNode* cursor = head;
	while (cursor) {
		total++;
		cursor = cursor->next;
	}
	return total;
}

/*
 * Overloaded operator[]:
 * Takes an integer index and (if it exists) returns a reference to the PayRoll
 * inside it
 */
PayRoll* PayRollList::operator[](int input) {
	if (input > length()) {
		return nullptr;
	}
	if (head == nullptr) {
		return nullptr;
	}
	int tracker = 0;
	ListNode* cursor = head;
	while (cursor) {
		if (tracker == (input - 1)) {
			PayRoll* ref = &cursor->p;
			return ref;
		}
		cursor = cursor->next;
		tracker++;
	}
}

/* Remove Function:
 * Remove the list item at the specified position
 */
void PayRollList::remove(int input) {
	if (input < 1) {
		std::cout << "Invalid! Index starts at 1." << std::endl;
		return;
	}
	if (input > length()) {
		std::cout << "Index larger than size of current list" << std::endl;
		return;
	}
	if (head == nullptr) {
		std::cout << "List is empty already" << std::endl;
		return;
	}
	if (head->next == nullptr) {
		ListNode* temp = head;
		delete temp;
		head = nullptr;
		return;
	}
	if (input == 1) {
		ListNode* temp = head;
		head = head->next;
		delete temp;
		return;
	}
	int tracker = 1;
	ListNode* cursor = head->next;
	ListNode* previous = head;
	while (cursor) {
		if (tracker == length()) {
                        previous->next = nullptr;
                        delete cursor;
                        return;
                }

		if (tracker == (input - 1)) {
			previous->next = cursor->next;
			delete cursor;
			return;
		}
		tracker++;
		previous = cursor;
		cursor = cursor->next;
	}
}

/* Assign Function:
 * Copy a PayRoll into a specific position
 */
void PayRollList::assign(int inputPos, PayRoll inputOBJ) {
	if (inputPos < 1) {
		std::cout << "Invalid! Index starts at 1." << std::endl;
	        return;	
	}
	if (inputPos > length()) {
                std::cout << "Index larger than size of current list" << std::endl;
                return;
        }
        int tracker = 0;
        ListNode* cursor = head;
        while (cursor) {
                if (tracker == (inputPos - 1)) {
                        cursor->p = inputOBJ;
			return;
                }
		tracker++;
		cursor = cursor->next;
        }
}

/* Overloaded Insert:
 * Inserts the PayRoll into the list so that it is now at the specified position
 */
void PayRollList::insert(int inputPos, PayRoll inputOBJ) {
	if (inputPos < 1) {
		std::cout << "Invalid! Index starts at 1." << std::endl;
		return;
	}
	if (inputPos > (length() + 1)) {
		std::cout << "Index larger than size of current list" << std::endl;
		return;
	}
	ListNode* newNode = new ListNode;
	newNode->p.setName(inputOBJ.getName());
	newNode->p.setRate(inputOBJ.getRate());
	newNode->p.setHours(inputOBJ.getHours());
	newNode->next = nullptr;
	if (head == nullptr && inputPos == 1) {
		head = newNode;
		return;
	}
	if (inputPos == 1) {
		ListNode* temp = head;
		head = newNode;
		newNode->next = temp;
		return;
	}
	if (head->next == nullptr && inputPos == 2) {
		head->next = newNode;
		return;
	}
	int tracker = 1;
	ListNode* cursor = head->next;
	ListNode* previous = head;
	while(cursor) {
		if (tracker == (inputPos - 1)) {
			previous->next = newNode;
			newNode->next = cursor;
			return;
		}
		if (cursor->next == nullptr) {
			break;
		}
		tracker++;
		previous = cursor;
		cursor = cursor->next;
	}
	// If made it to here than we want to add to tail 
	cursor->next = newNode;
}
