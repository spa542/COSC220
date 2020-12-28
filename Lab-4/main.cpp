#include <iostream> // cout, endl
#include "payroll.h" // PayRoll class
#include "PayRollList.h" // PayRollList class

int main() {

	PayRollList list;
	
	std::cout << "Length Test cases: " << std::endl;		// Length Test Cases
	std::cout << "Current empty list length: " << std::endl;
	std::cout << list.length() << std::endl;
	list.insert("Ryan", 25, 10);
	list.insert("John", 10, 15);
	list.insert("Skylar", 12, 40);
	list.printPayChecks();
	std::cout << "Now current list length after 3 additions: " << std::endl;
	std::cout << list.length() << std::endl;
	std::cout << "===========================================" << std::endl;

	std::cout << "Operator[] test cases: " << std::endl;		// Operator[] Test Cases
	std::cout << "Name of first item in list: " << std::endl;
	std::cout << list[1]->getName() << std::endl;
	std::cout << "Payrate of second item in list: " << std::endl;
	std::cout << list[2]->getRate() << std::endl;
	std::cout << "Hours of third item in list: " << std::endl;
	std::cout << list[3]->getHours() << std::endl;
	std::cout << "===========================================" << std::endl;
	
	std::cout << "List remove() function test cases: " << std::endl;	// remove() Test Cases
	std::cout << "Removing the second position in the list..." << std::endl;
	list.remove(2);
	list.printPayChecks();
	std::cout << "Removing the head of the list..." << std::endl;
	list.remove(1);
	list.printPayChecks();
	std::cout << "Repopulating list real quick..." << std::endl;
	list.insert("Margaret", 14, 23);
	list.insert("Mary", 25, 58);
	list.insert("Marvin", 42, 10);
	list.printPayChecks();
	std::cout << "Removing tail of list..." << std::endl;
	list.remove(4);
	list.printPayChecks();
	std::cout << "Example of invalid index..." << std::endl;
	list.remove(-5);
	list.remove(6);
	std::cout << "===========================================" << std::endl;	
	
	PayRoll p1("Beatrice", 45, 23);	// Example objects created
	PayRoll p2("Roberto", 12, 40);

	std::cout << "Assign Function Test cases: " << std::endl;	// Assign function Test Cases
	std::cout << "Current size of list: " << list.length() << std::endl;
	std::cout << "Example Invalid Input: " << std::endl;
	list.assign(7, p1);
	list.assign(0, p2);
	std::cout << "Current List: " << std::endl;
	list.printPayChecks();
	std::cout << "Assigning Beatrice info to subscript 2: " << std::endl;
	list.assign(2, p1);
	std::cout << "Assigning Roberto info to tail of subscript: " << std::endl;
	list.assign(3, p2);
	std::cout << "Assigning Beatrice info to head: " << std::endl;
	list.assign(1, p1);
	list.printPayChecks();
	std::cout << "==========================================" << std::endl;

	std::cout << "Overloaded insert function using position Test cases: " << std::endl; // Overloaded Insert Test Cases
	PayRollList list2;
	std::cout << "Current New list size: " << list2.length() << std::endl;
	std::cout << "Inserting Beatrice info into empty list at beginnning: " << std::endl;
	list2.insert(1, p1);
	list2.printPayChecks();
	std::cout << "Inserting Roberto info at tail of list: " << std::endl;
	std::cout << "Current list size before insert: " << list2.length() << std::endl;
	list2.insert(2, p2);
	list2.printPayChecks();
	PayRoll p3("Jamison", 14, 25);
	PayRoll p4("Skylar", 36, 45);
	std::cout << "Inserting Jamison info at tail of list: " << std::endl;
	std::cout << "Current list size before insert: " << list2.length() << std::endl;
	list2.insert(3, p3);
	list2.printPayChecks();
	std::cout << "Inserting Skylar info at second position in list: " << std::endl;
	std::cout << "Current list size before insert: " << list2.length() << std::endl;
	list2.insert(2, p4);
	list2.printPayChecks();
	std::cout << "Inserting Skylar info at head in list: " << std::endl;
	std::cout << "Current list size before insert: " << list2.length() << std::endl;
	list2.insert(1, p4);
	list2.printPayChecks();
	std::cout << "==========================================" << std::endl;
	
	std::cout << "Copy Constructor Test Case: " << std::endl;	// Copy Constructor Test Cases
	PayRollList originalList;
	originalList.insert("Jerry", 10, 10);
	originalList.insert("Magnolia", 12, 15);
	originalList.insert("Veridian", 12, 16);
	originalList.insert("Virgo", 2, 14);
	std::cout << "Original List: " << std::endl;
	originalList.printPayChecks();
	PayRollList copiedList(originalList);
	std::cout << "Copied List: " << std::endl;
	copiedList.printPayChecks();

	return 0;
}
