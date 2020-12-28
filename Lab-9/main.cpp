#include "payroll.h" // PayRoll object
#include "MyStack.h" // MyStack list
#include <iostream> // cout, endl

int main() {
	
	std::cout << "Testing for Lab-5\n";
	std::cout << "Test with PayRoll Objects: " << std::endl; // PayRoll tests
	MyStack<PayRoll> m;
	PayRoll p1("Ryan", 25, 52);
	PayRoll p2("Skylar", 30, 55);
	PayRoll p3("Mary", 12, 30);
	std::cout << "Push() Function Test: " << std::endl;	// Test the push function
	std::cout << "Empty list:\n";
	m.printStack();
	std::cout << "First push:\n";
	m.push(p1);
	m.printStack();
	std::cout << "Second push:\n";
	m.push(p2);
	m.printStack();
	std::cout << "Third push:\n";
	m.push(p3);
	m.printStack();
	std::cout << "==================================" << std::endl;
	
	std::cout << "Copy Constructor Test: " << std::endl; // Test the copy constructor
	std::cout << "Previous List: " << std::endl;
	m.printStack();
	MyStack<PayRoll> s(m);
	std::cout << "New Stack at Initialization:" << std::endl;
	s.printStack();	
	std::cout << "==================================" << std::endl;

	std::cout << "Overloaded Assignment Test: " << std::endl; // Test the overloaded assignment 
	std::cout << "Assign previous list to empty list: " << std::endl;
	MyStack<PayRoll> z;
	z = m;
	z.printStack();
	std::cout << "Assign a new list to a populated list: " << std::endl;
	std::cout << "List being copied over: " << std::endl;
	MyStack<PayRoll> j;
	j.push(p3);
	j.push(p1);
	j.push(p2);
	j.printStack();
	std::cout << "Original list being assigned to: " << std::endl;
	z.printStack();
	std::cout << "Revised list after assigning: " << std::endl;
	z = j;
	z.printStack();
	std::cout << "Self assignment test: " << std::endl;
	j = j;
	std::cout << "==================================" << std::endl;

	std::cout << "Pop Function Test: \n"; // Test the pop function
	std::cout << "List being popped off: " << std::endl;
	z.printStack();
	auto pop1 = z.pop();
	std::cout << "First pop: \n" << pop1 << std::endl;
	auto pop2 = z.pop();
	std::cout << "Second pop: \n" << pop2 << std::endl;
	auto pop3 = z.pop();
	std::cout << "Third pop: \n" << pop3 << std::endl;
	std::cout << "Empty list pop:" << std::endl;
	z.pop();
	std::cout << "==================================" << std::endl;
	
	std::cout << "Peek Function Test: \n"; // Test the peek function
	std::cout << "Empty list peek(): " << std::endl;
	auto peek1 = z.peek();
	std::cout << "List being peeked off of: " << std::endl;
	j.printStack();
	std::cout << "Peek off the top: " << std::endl;
	auto peek2 = j.peek();
	std::cout << "Peeked item: " << peek2 << std::endl;
	std::cout << "==================================" << std::endl;
	
	std::cout << "Test with ints: " << std::endl; // Int tests
	MyStack<int> m1;
	int p4 = 10;
	int p5 = 20;
	int p6 = 30;
	std::cout << "Push() Function Test: " << std::endl;	// Test the push function
	std::cout << "Empty list:\n";
	m1.printStack();
	std::cout << "First push:\n";
	m1.push(p4);
	m1.printStack();
	std::cout << "Second push:\n";
	m1.push(p5);
	m1.printStack();
	std::cout << "Third push:\n";
	m1.push(p6);
	m1.printStack();
	std::cout << "==================================" << std::endl;
	
	std::cout << "Copy Constructor Test: " << std::endl; // Test the copy constructor
	std::cout << "Previous List: " << std::endl;
	m1.printStack();
	MyStack<int> s1(m1);
	std::cout << "New Stack at Initialization:" << std::endl;
	s1.printStack();	
	std::cout << "==================================" << std::endl;

	std::cout << "Overloaded Assignment Test: " << std::endl; // Test the overloaded assignment 
	std::cout << "Assign previous list to empty list: " << std::endl;
	MyStack<int> z1;
	z1 = m1;
	z1.printStack();
	std::cout << "Assign a new list to a populated list: " << std::endl;
	std::cout << "List being copied over: " << std::endl;
	MyStack<int> j1;
	j1.push(p6);
	j1.push(p4);
	j1.push(p5);
	j1.printStack();
	std::cout << "Original list being assigned to: " << std::endl;
	z1.printStack();
	std::cout << "Revised list after assigning: " << std::endl;
	z1 = j1;
	z1.printStack();
	std::cout << "Self assignment test: " << std::endl;
	j1 = j1;
	std::cout << "==================================" << std::endl;

	std::cout << "Pop Function Test: \n"; // Test the pop function
	std::cout << "List being popped off: " << std::endl;
	z1.printStack();
	auto pop4 = z1.pop();
	std::cout << "First pop: \n" << pop4 << std::endl;
	auto pop5 = z1.pop();
	std::cout << "Second pop: \n" << pop5 << std::endl;
	auto pop6 = z1.pop();
	std::cout << "Third pop: \n" << pop6 << std::endl;
	std::cout << "Empty list pop:" << std::endl;
	z1.pop();
	std::cout << "==================================" << std::endl;
	
	std::cout << "Peek Function Test: \n"; // Test the peek function
	std::cout << "Empty list peek(): " << std::endl;
	auto peek3 = z1.peek();
	std::cout << "List being peeked off of: " << std::endl;
	j1.printStack();
	std::cout << "Peek off the top: " << std::endl;
	auto peek4 = j1.peek();
	std::cout << "Peeked item: " << peek4 << std::endl;
	std::cout << "==================================" << std::endl;
	
	std::cout << "Test with Strings: " << std::endl; // String tests
	MyStack<std::string> m2;
	std::string p7 = "Hello there";
	std::string p8 = "Hi how are you";
	std::string p9 = "I am great how are you";
	std::cout << "Push() Function Test: " << std::endl;	// Test the push function
	std::cout << "Empty list:\n";
	m2.printStack();
	std::cout << "First push:\n";
	m2.push(p7);
	m2.printStack();
	std::cout << "Second push:\n";
	m2.push(p8);
	m2.printStack();
	std::cout << "Third push:\n";
	m2.push(p9);
	m2.printStack();
	std::cout << "==================================" << std::endl;
	
	std::cout << "Copy Constructor Test: " << std::endl; // Test the copy constructor
	std::cout << "Previous List: " << std::endl;
	m2.printStack();
	MyStack<std::string> s2(m2);
	std::cout << "New Stack at Initialization:" << std::endl;
	s2.printStack();	
	std::cout << "==================================" << std::endl;

	std::cout << "Overloaded Assignment Test: " << std::endl; // Test the overloaded assignment 
	std::cout << "Assign previous list to empty list: " << std::endl;
	MyStack<std::string> z2;
	z2 = m2;
	z2.printStack();
	std::cout << "Assign a new list to a populated list: " << std::endl;
	std::cout << "List being copied over: " << std::endl;
	MyStack<std::string> j2;
	j2.push(p9);
	j2.push(p7);
	j2.push(p8);
	j2.printStack();
	std::cout << "Original list being assigned to: " << std::endl;
	z2.printStack();
	std::cout << "Revised list after assigning: " << std::endl;
	z2 = j2;
	z2.printStack();
	std::cout << "Self assignment test: " << std::endl;
	j2 = j2;
	std::cout << "==================================" << std::endl;

	std::cout << "Pop Function Test: \n"; // Test the pop function
	std::cout << "List being popped off: " << std::endl;
	z2.printStack();
	auto pop7 = z2.pop();
	std::cout << "First pop: \n" << pop7 << std::endl;
	auto pop8 = z2.pop();
	std::cout << "Second pop: \n" << pop8 << std::endl;
	auto pop9 = z2.pop();
	std::cout << "Third pop: \n" << pop9 << std::endl;
	std::cout << "Empty list pop:" << std::endl;
	z2.pop();
	std::cout << "==================================" << std::endl;
	
	std::cout << "Peek Function Test: \n"; // Test the peek function
	std::cout << "Empty list peek(): " << std::endl;
	auto peek5 = z2.peek();
	std::cout << "List being peeked off of: " << std::endl;
	j2.printStack();
	std::cout << "Peek off the top: " << std::endl;
	auto peek6 = j2.peek();
	std::cout << "Peeked item: " << peek6 << std::endl;
	std::cout << "==================================" << std::endl;

	return 0;
}
