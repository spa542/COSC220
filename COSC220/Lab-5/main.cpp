#include "payroll.h"
#include "PayRollStack.h"
#include <iostream>

int main() {
	
	PayRoll p1("Ryan", 25, 15);	// Objects that will be used in testing
	PayRoll p2("Skylar", 32, 50);
	PayRoll p3("John", 10, 25);
	PayRoll p4("Mary", 12, 25);
	PayRoll p5("Marvin", 12, 10);

	std::cout << "Testing for Lab-5\n";
	std::cout << "Push() Function Test: " << std::endl;	// Test the push function
	PayRollStack stack;
	stack.push(p1);
	stack.push(p2);
	stack.push(p3);
	stack.push(p4);
	stack.push(p5);
	stack.printStack();
	std::cout << "==================================" << std::endl;
	
	std::cout << "Copy Constructor Test:" << std::endl;	// Test the copy constructor
	std::cout << "Stack 1 \n";
	stack.printStack();
	PayRollStack stack2(stack);
	std::cout << "Stack 2 \n";
	stack2.printStack();	
	std::cout << "==================================" << std::endl;

	std::cout << "Overloaded Assignment Test: " << std::endl; // Test the overloaded assignment 
	std::cout << "Stack 1 \n";
	stack.printStack();
	PayRollStack stack3;
	stack3 = stack;
	std::cout << "Stack 2 \n";
	stack3.printStack();
	std::cout << "Sample identical assignment: " << std::endl;
	stack = stack;
	std::cout << "==================================" << std::endl;

	std::cout << "Pop Function Test (returns a PayRoll object): \n"; // Test the pop function
	std::cout << "Current stack: " << std::endl;
	stack.printStack();
	std::cout << "First pop(): \n"; 
	stack.pop().printInfo();
	std::cout << "Second pop(): \n";
	stack.pop().printInfo();
	std::cout << "Third pop(): \n";
	stack.pop().printInfo();
	std::cout << "Stack after pops: " << std::endl;
	stack.printStack();
	std::cout << "Popping rest of nodes to empty list: " << std::endl;
	stack.pop();
	stack.pop();
	std::cout << "Empty stack: " << std::endl;
	stack.printStack();
	stack.pop();
	std::cout << "Example empty stack pop: \n";
	PayRollStack stack4;
	stack4.pop();
	std::cout << "==================================" << std::endl;

	std::cout << "Pop Function Test (a reference to a PayRoll object is passed): \n"; // Test other pop function
	std::cout << "Repopulating previous stack... \n";
	stack.push(p1);
	stack.push(p2);
	stack.push(p5);
	stack.push(p3);
	stack.push(p4);
	std::cout << "Current stack: \n";
	stack.printStack();
	PayRoll pRef;
	PayRoll pRef2;
	stack.pop(pRef);
	stack.pop(pRef2);
	std::cout << "Info from popped nodes: " << std::endl;
	std::cout << "First pop: \n";
	pRef.printInfo();
	std::cout << "Second pop: \n";
	pRef2.printInfo();
	std::cout << "Stack after popped nodes: " << std::endl;
	stack.printStack();
	std::cout << "==================================" << std::endl;
	
	std::cout << "Size() Function Test: \n"; // Test the size function
	std::cout << "First stack: " << std::endl;
	stack.printStack();
	std::cout << "Size of stack: " << stack.size() << "\n";
	std::cout << "Second stack: " << std::endl;
	PayRollStack stack5;
	stack5.push(p4);
	stack5.push(p2);
	stack5.printStack();
	std::cout << "Size of stack: " << stack5.size() << "\n";
	std::cout << "Empty stack example: " << std::endl;
	std::cout << "Size of stack: " << stack4.size() << "\n";	
	std::cout << "==================================" << std::endl;
	
	return 0;
}
