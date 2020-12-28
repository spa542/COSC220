#include "Disk.h" // Disk class
#include "HanoiStack.h" // HanoiStack class
#include <iostream> // cout, endl
#include <stdlib.h> // atoi
#include <stdio.h> // printf

void initializeGame(HanoiStack&, int); // Initializes stackA with how many disks are entered by the user
int pickUpDisk(); // shows choice for which stack to pick a disk up
int putDownDisk(); // shows choice for which stack to place a disk
void moveDisk(HanoiStack&, HanoiStack&, HanoiStack&); // UI for moving disks from stack to stack
void printDirections(); // prints the directions for the game
bool checkWin(HanoiStack&, HanoiStack&, int); // checks if stackB or stackC are winning stacks
void rePush(HanoiStack&, HanoiStack&, HanoiStack&, int, Disk); // pushes a disk back onto its
						// orignial stack to if choice of disk placement was
						// incorrect acording to the rules of the game
void solveHanoi(int, int, int, int); // Shows the moves that are needed to complete the game correctly

int main(int argc, char** argv) {
	
	int count = argc; // amount of arguments at start of the program
	if (count != 2) {
		std::perror("Cannot Execute Program: Error Code\n\t--Amount of arguments incorrect\n\t--To run:\n\t\t./main numOfDisks\n");
		exit(1);		// checks for correct argument input at start of program
	}
	int numOfDisks = atoi(argv[1]); // takes the second argument as the # of disks to start with
	bool done = false; // game flag
	int choice;
	if (numOfDisks < 1 || numOfDisks > 10) {
		std::perror("Cannot Execute Program: Error Code\n\t--Second Argument Invalid Input\n\t--To run:\n\t\tnumOfDisks must be between 1 and 10 inclusive\n");	
		exit(1);		// checks for correct argument input at start of program
	}

	HanoiStack stackA, stackB, stackC;	// three stacks for game
	initializeGame(stackA, numOfDisks);	// initializes stackA from input
	
	std::cout << "\tWelcome to the Towers of Hanoi!\n\n";
	std::cout << "Here is how to play: " << std::endl;
	printDirections(); // prints the directions

	do {
		std::cout << "A." << std::endl;
		std::cout << stackA;
		std::cout << "B." << std::endl;
		std::cout << stackB;
		std::cout << "C." << std::endl;
		std::cout << stackC;
		std::cout << "Options:" << std::endl;
		std::cout << "1. Move a disk" << std::endl;
		std::cout << "2. Print Optimal Solution" << std::endl;
		std::cout << "3. Quit" << std::endl;
		do {
			std::cout << "Enter your choice (1-3): ";
			std::cin >> choice;
			std::cout << std::endl;
		} while (choice < 1 || choice > 3); // input validation

		switch (choice) {
			
			case 1: 
				moveDisk(stackA, stackB, stackC); // main game UI	
				break;
			case 2:
				std::cout << "Here is the solution: Take notes!!!!!" << std::endl;
				solveHanoi(numOfDisks, 1, 2, 3);
				break;
			case 3:
				done = true; // game quit
				break;	
		}
		if (checkWin(stackB, stackC, numOfDisks)) { // checks to see if win condition satisfied
			std::cout << stackA;
			std::cout << stackB; // prints the stacks
			std::cout << stackC;
			std::cout << "YOU WIN!!!!!!" << std::endl;
			done = true;
		}
	} while (!done);

	return 0;
}

/*
 * solveHanoi Function:
 * Recursive algorithm that tells the user the optimal moves in order in order to complete the game
 */
void solveHanoi(int n, int start, int end, int tmp) {
	if (n >= 1) {
		solveHanoi(n - 1, start, tmp, end);
		printf("Move disk %d from stack %d to stack %d\n", n, start, end);
		solveHanoi(n - 1, tmp, end, start);
	}
}

/*
 * initializeGame Function:
 * Takes the input of how many disks to start with and initializes stackA with that many disks
 */
void initializeGame(HanoiStack &s, int numOfDisks) {
	for (int i = numOfDisks; i >= 1; i--) {
		Disk dk(i);
		s.push(dk);
	}
}

/*
 * moveDisk Function:
 * Takes all three stacks and starts the UI for the user to move a disk
 */
void moveDisk(HanoiStack &a, HanoiStack &b, HanoiStack &c) {
	int choiceStack = pickUpDisk(); // Returns what stack a disk is being taken from
	int lastChoice = 0;
	Disk hold;
	if (choiceStack == 1) {
		hold = a.pop();
		lastChoice = 1;
		if (hold.getSize() == -1) { // Checks if the stack is empty
			return;
		}	
	} else if (choiceStack == 2) {
		hold = b.pop();
		lastChoice = 2;
		if (hold.getSize() == -1) { // Checks if the stack is empty
			return;
		}
	} else if (choiceStack == 3) {
		hold = c.pop();
		lastChoice = 3;
		if (hold.getSize() == -1) { // Checks if the stack is empty
			return;
		}
	}	
	std::cout << "Current disk being held: " << hold.getSize() << std::endl; // shows user disk
	choiceStack = putDownDisk(); // Returns what stack a disk a being placed on
	if (choiceStack == 1) {
		if (a.seeTop() > hold.getSize()) {
			a.push(hold);
			return;
		} else
			rePush(a, b, c, lastChoice, hold); // Pushes a disk back on its original stack
	}
	else if (choiceStack == 2) {
		if (b.seeTop() > hold.getSize()) {
			b.push(hold);
			return;
		} else
			rePush(a, b, c, lastChoice, hold); // Pushes a disk back on its original stack
	} else if (choiceStack == 3) {
		if (c.seeTop() > hold.getSize()) {
			c.push(hold);
			return;
		} else
			rePush(a, b, c, lastChoice, hold); // Pushes a disk back on its original stack
	}
		
}

/*
 * printDirections Function:
 * Prints the directions of the game for the user to understand how to play
 */
void printDirections() {
	std::cout << "Rules of the Game:" << std::endl;
	std::cout << "1. You can only move one disk at a time (taking the top disk from a single " <<
		"stack and you must place it onto a stack before taking another disk)" << std::endl;
	std::cout << "2. No disk can be placed on a disk smaller than itself" << std::endl;
	std::cout << "How to Win:" << std::endl;
	std::cout << "--Create the original pyramid again on the second (Stack B) or the third " << 
		"(Stack C) stack to finish the game" << std::endl;
	std::cout << "--Or just select option to show optimal solution" << std::endl;
}

/*
 * pickUpDisk Function:
 * UI for user to input what stack to take a disk from
 */
int pickUpDisk() {
	int choice;
	do {
		std::cout << "Which stack would you like to take a disk from? (1-3)" << std::endl;
		std::cout << "1. A\t2. B\t3. C" << std::endl;
		std::cin >> choice;
		if (choice == 1)
			return 1;
		else if (choice == 2)
			return 2;
		else if (choice == 3)
			return 3;
	} while (choice < 1 || choice > 3);
}

/*
 * putDownDisk Function:
 * UI for user to input what stack to place a disk on
 */
int putDownDisk() {
	int choice;
	do {
		std::cout << "Which stack would you like to place the disk? (1-3)" << std::endl;
		std::cout << "1. A\t2. B\t3. C" << std::endl;
		std::cin >> choice;
		if (choice == 1)
			return 1;
		else if (choice == 2)
			return 2;
		else if (choice == 3)
			return 3;
	} while (choice < 1 || choice > 3);
}

/*
 * checkWin Function:
 * Uses internal function for stackB and stackC to see if they are winning formations
 */
bool checkWin(HanoiStack &b, HanoiStack &c, int numOfDisks) {
	if (b.win(numOfDisks) || c.win(numOfDisks))
		return true;

	return false;
}

/*
 * rePush Function:
 * Pushes the disk being held back on to its orignial stack because stack that was input by user
 * was incorrect
 */
void rePush(HanoiStack &a, HanoiStack &b, HanoiStack &c, int lastChoice, Disk hold) {
	if (lastChoice == 1) {
		a.push(hold);
	} else if (lastChoice == 2) {
		b.push(hold);
	} else if (lastChoice == 3) {
		c.push(hold);
	}
	std::cout << "Cannot place bigger disk on top of a smaller disk" << std::endl;
}
