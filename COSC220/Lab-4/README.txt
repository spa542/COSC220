Ryan Rosiak
COSC 220-001
Lab-4 README File
9/18/19

Lab Description:
This labe demonstrates more functions that are used for our singly linked list class. The new functions that were added overload the [] operator. It also overloads the insert function once again. The class implements a basic copy constructor and finally implements a couple functions such as assign and remove requiring an index that allows the user to choose what node they want replaced or removed from the list. All of these functions are implemented without leaking memory. Sample output shows the step by step process of functions being called and the output as it is manipulated. Overall, this program extends the functionality of our linked list.

Files to pay attention to:
main.o, payroll.o, PayRollList.o - These are the three progams that must be linked in order to compile final product

main - Output fil that is run when wanting to run the program

makefile - File that allows user to compile without having to input many commands

MakeFile Instructions: (Bonus)
To compile the program: 
Type "make" without the quotes and the program will compile everything together for you

Then proceed with using ./main in order to run the program

Instructions for Program:

Follow MakeFile instruction above to test how to run your program. 
If not using makefile, you must compile each file individually. Use the g++ -c command
to compile payroll.cpp, PayRollList.cpp, and main.cpp. Once you have all of the .o files, you can
compile all the .o files into one g++ command and run it under the name main. You must use -std=c++11 with your compile commands in order to run the program. 
