#include "HanoiStack.h"

/*
 * Default Constructor:
 * Initializes head of stack list
 */
HanoiStack::HanoiStack() {
	head = nullptr;
}

/*
 * Copy Constructor:
 * Allows for deep copy of stack list
 */
HanoiStack::HanoiStack(const HanoiStack &rhs) {
	head = nullptr;
	DiskNode* rhsCursor = rhs.head;
	while (rhsCursor) {
		push(rhsCursor->d);
		rhsCursor = rhsCursor->next;
	}
}

/*
 * Destructor:
 * Deletes dynamically allocated memory
 */
HanoiStack::~HanoiStack() {
	DiskNode* cursor = head;
	while (cursor) {
		cursor = cursor->next;
		delete head;
		head = cursor;
	}	
}

/*
 * push(Disk) Function:
 * Pushes a disk onto the stack
 */
void HanoiStack::push(Disk newDisk) {
	DiskNode* newNode = new DiskNode;
	newNode->d = newDisk;
	newNode->next = nullptr;

	if (head == nullptr) {
		head = newNode;
		return;
	}
	DiskNode* cursor = head;
	while (cursor->next) {
		cursor = cursor->next;
	}
	if (newNode->d.getSize() > cursor->d.getSize()) {
		std::cout << "Cannot place disk, disk is larger than disk below it" << std::endl;
		delete newNode;
		return;
	}
	cursor->next = newNode;
}

/*
 * pop() Function:
 * Pops a DiskNode off of the stack and returns a DiskNode pointer of the popped DiskNode
 */
Disk HanoiStack::pop() {
	if (head == nullptr) {
		std::cout << "No disks on current stack" << std::endl;
		Disk bad(-1);
		return bad;
	}
	if (head->next == nullptr) {
		Disk rtnMe = head->d;
		delete head;
		head = nullptr;
		return rtnMe;
	}
	DiskNode* cursor = head;
	DiskNode* prev = head;
	while (cursor->next) {
		prev = cursor;
		cursor = cursor->next;
	}
	prev->next = nullptr;
	Disk rtnMe = cursor->d;
	delete cursor;
	return rtnMe;
}

/*
 * Overloaded operator+=:
 * Allows a different way for a disk to be pushed onto the stack
 */
void HanoiStack::operator+=(const Disk &rhs) {
	push(rhs);
}

/*
 * Overloaded operator<<:
 * Acts as the print function for the stack, prints the stack visually and all of its contents
 */
std::ostream& operator<<(std::ostream &os, const HanoiStack &obj) {
	if (obj.head == nullptr) {
		for (int i = 0; i < 7; i++) {
			os << "             " << std::endl;
		}
		os << "=============" << std::endl;
		return os;
	}
	HanoiStack::DiskNode* cursor = obj.head;
	int counter = 0;
	while (cursor) {
		cursor = cursor->next;
		counter++;
	}
	for (int i = 0, j = counter; i < counter; i++, j--) {
		cursor = obj.head;
		for (int l = 1; l < j; l++) {
			cursor = cursor->next;
		}
		int limit = (13 - cursor->d.getSize()) / 2;
		for (int n = 0; n < limit; n++) {
			os << " ";
		}
		for (int q = 0; q < cursor->d.getSize(); q++) {
			os << "#";
		}
		for (int m = 0; m < limit; m++) {
			os << " ";
		}
		os << std::endl;
	}
	os << "=============" << std::endl;
	return os;
}

/*
 * Overloaded operator=:
 * Allows for different stack lists to be copied over one another
 */
HanoiStack HanoiStack::operator=(const HanoiStack &rhs) {
	DiskNode* cursor = head;
	while (cursor) {
		cursor = cursor->next;
		delete head;
		head = cursor;
	}

	head = nullptr;
	if (this == &rhs) {
		std::cout << "Cannot assign, Objects are identical" << std::endl;
		return *this;
	}

	DiskNode* rhsCursor = rhs.head;
	while (rhsCursor) {
		push(rhsCursor->d);
		rhsCursor = rhsCursor->next;
	}
	return *this;
}

/*
 * win() Function:
 * Checks to see if the stack matches the win condition and then returns is true or not
 */
bool HanoiStack::win(int numOfDisks) {
	if (head == nullptr) {
		return false;
	}
	int count = 0;
	DiskNode* cursor = head;
	while (cursor) {
		cursor = cursor->next;
		count++;
	}
	if (count == numOfDisks) {
		cursor = head;
		for (int i = numOfDisks; i > 0; i--) {
			if (cursor->d.getSize() != i) {
				return false;
			}
			cursor = cursor->next;
		}
		return true;
	} else {
		return false;
	}
}

/*
 * seeTop() Function:
 * Returns the size of the top disk on the stack
 */
int HanoiStack::seeTop() {
	if (head == nullptr) {
		return 11;
	}
	DiskNode* cursor = head;
	while (cursor->next) {
		cursor = cursor->next;
	}
	return cursor->d.getSize();
}
