Ryan Rosiak
COSC 220-001
Lab-3 README File
9/12/19

Lab Description:
This lab starts with and demonstrates the basic fundamentals of a data structure called a linked list. This data structure
allows the programmer to create dynamic storage on the heap that is all linked together while only using one route to that data
that is on the stack. This is helpful because we can trace from the head of the list to get to all of the data that we need without
using as much data then normally creating a bunch of instances of classes. This also allows us to go through the list and add/insert
data with ease and faster due to it using pointer manipulation. Overall, this program demonstrates the basic function of the constructor
and destructor of the linked list. As well as inserting members into the linked list through outside parameters or through 
passing complete objects. And lastly, by printing out the linked list correctly to the command line to see what is being 
stored. The data management of the linked list is highly important and is demonstrated here.

Files to pay attention to:

main.o, payroll.o, PayRollList.o - These are the three programs that must be linked in order to compile final product

main - Output file that is run when running the program

employee.dat - Data file that contains employee information for one of the linked lists that are created

----------------------------------------------------------------------------------
Format for .dat file:

"Start of File"
Name
Payrate
Hour

Name
Payrate
Hour

Name
Payrate
Hour
"End of File"
----------------------------------------------------------------------------------

Instructions for Program:

To compile on your computer. Use the g++ -c compile command to compile
payroll.cpp, PayRollList.cpp, and main.cpp individually in order to have the 
.o files available to you. Once you have the .o files, you can compile all the .o
files in one g++ command and run it under the name 'main'. Use ./main to run
program. There is a second portion to running the program. This program also uses 
a .dat file that contains employee info and file streams it into the program to demonstrate
more with the linked list. Be aware of the employee.dat file and know that it must be in
the folder with the rest of the program files in order to run correctly.

