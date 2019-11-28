#include <iostream>
/*
Ryan Rosiak
Lab-1 Problem 1
COSC 220
8/27/19
*/

double mean(int*, int); // Function that returns a double that is the mean of the array passed using bracket
			// notation
double mean2(int*, int); // Function that returns a double that is the mean of the array passed using
				// pointer notation

int main() {

int size;
std::cout << "Enter the size of the array: " << std::endl;	// asks the user for the size of the array
std::cin >> size;			
int *arr;
arr = new int[size];		// dynamically allocates memory for the array

for (int i = 0; i < size; i++) {			// Loops through and asks the user to enter numbers to
							// fill the array
	std::cout << "Enter a number: " << std::endl;
	std::cin >> arr[i]; 
}

std::cout << "Mean called: " << mean(arr, size) << std::endl;
std::cout << "Mean2 called: " << mean2(arr, size) << std::endl;

delete [] arr; // delete the dynamically allocated array
return 0;
}

double mean(int *arr, int size) { 	// Passed in: array and its size
	double total = 0;
	for (int i = 0; i < size; i++) {  // Adds up all of the array elements
		total += arr[i];
	}
	return total / size; // returns the mean 
}

double mean2(int *arr, int size) { 	// Passed in: array using pointer and its size
	double total = 0;
	for (int i = 0; i < size; i++) { // Adds up all of the array elements
		total += *(arr + i);
	}
	return total / size; 	// returns the mean
}


