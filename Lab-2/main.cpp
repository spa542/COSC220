#include "payroll.h" // Class file
#include <iostream>  // cout, cin, endl

int main() {
	
	int inHour;         // Input variable for hours worked
	bool done = false;  // Flag variable for loop

	PayRoll* parray[7];  
    PayRoll parray2[7];

	PayRoll p1 {"Bob", 12};
	PayRoll p2 {"Ryan", 15};
	PayRoll p3 {"Sky", 22};
	PayRoll p4 {"Mary", 25};
	PayRoll p5 {"Jeff", 9};
	PayRoll p6 {"Arnold", 11};
	PayRoll p7 {"Naomi", 18};       // Initialize all the objects

	parray[0] = &p1;
	parray[1] = &p2;
	parray[2] = &p3;
	parray[3] = &p4;
	parray[4] = &p5;
	parray[5] = &p6;         // Assign all of the object's addresses to the pointer array
	parray[6] = &p7;
    
    PayRoll p8 {"Bob", 12};
	PayRoll p9 {"Ryan", 15};
	PayRoll p10 {"Sky", 22};
	PayRoll p11 {"Mary", 25};
	PayRoll p12 {"Jeff", 9};
	PayRoll p13 {"Arnold", 11};
	PayRoll p14 {"Naomi", 18};       

	parray2[0] = p8;
	parray2[1] = p9;
	parray2[2] = p10;
	parray2[3] = p11;
	parray2[4] = p12;
	parray2[5] = p13;
	parray2[6] = p14;

	for (int i = 0; i < 7; i++) {
		std::cout << "Enter the amount of hours worked for " << parray[i]->getName() << ": ";
		std::cin >> inHour;
		while (!done) {
			if (inHour <= 60) {                         // Validates that the hours are not over 60
				std::cout << "Success!" << std::endl;
				parray[i]->setHours(inHour);
				done = true;        // Continues to next position in the array
			} else {
				std::cout << "Unsuccessful! Hours cannot be over 60. " << std::endl;
				std::cout << "Enter the amount of hours worked for " << parray[i]->getName()
				<< ": ";
				std::cin >> inHour;     // Gives another chance to input a correct number
				std::cout << std::endl;
		        }
		}
		done = false;   // Allows for repeated validation
	}
	
	for (int i = 0; i < 7; i++) {       // Prints the info of all of the PayRoll objects
		parray[i]->printInfo();
		std::cout << std::endl;
	}

    std::cout << "Size of pointer array: " << std::endl;
    std::cout << sizeof(parray) << std::endl;
    std::cout << "Size of regular array of objects: " << std::endl;
    std::cout << sizeof(parray2) << std::endl;
    
    std::cout << "Memory addresses for pointer array: " << std::endl;
    for (int i = 0; i < 7; i++) {
        std::cout << parray[i] << std::endl;
    }
    std::cout << "Memory addresses for regular array of objects: " << std::endl;
    for (int i = 0; i < 7; i++) {
        std::cout << &parray2[i] << std::endl;
    }
    
	return 0;
}

/* 9.
* The difference between the pointer array and the regular array of objects
* is that the pointer array is holding only the memory address that is pointing to 
* the location of the objects that are deep within it. The actual array of class objects 
* must store all of the data and bytes from each object into one array. Therefore, it is much
* larger of an array because the object and its data members has much more memory used
* then does just an array of a pointer pointing to memory addresses. 
*/

/* 10.
* The addresses are right next to each other within their own given array because that is the way 
* that an array handles incrementing subscripts and keeping objects together. Each object in memory is 
* its specificed amount of memory away from each other. This is the same for both arrays. But they both also
* seem to be somewhat together in memory as well. In other words, both arrays are close to each other in 
* memory. That could be a coincidence but it is no coincidence that each object address in each given array 
* follows one another in memory.
*/
