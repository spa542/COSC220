#ifndef _HANOISTACK_H_
#define _HANOISTACK_H_
#include "Disk.h" // Disk class
#include <iostream> // cout, cin

class HanoiStack {
	friend std::ostream &operator<<(std::ostream&, const HanoiStack&); // Prints the stack
	private:
		struct DiskNode {
			Disk d;
			DiskNode* next;
		};

		DiskNode* head;
	public:
		HanoiStack(); // Default Ctor
		HanoiStack(const HanoiStack&); // Copy Ctor
		~HanoiStack(); // Destructor
		void push(Disk); // Pushes a disk onto the stack
		Disk pop(); // Pops the top disk off of the stack and returns a pointer to the
				// popped DiskNode
		void operator+=(const Disk&); // an alternative to pushing a disk onto the stack
		HanoiStack operator=(const HanoiStack&); // overloaded assignment
		bool win(int); // Checks if the stack matches the win condition
		int seeTop(); // Returns the top disks size of the stack
};

#endif
