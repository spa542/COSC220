#include <iostream>
/*
Ryan Rosiak
Lab-1 Problem 1 Bonus
COSC 220
8/27/19
*/

double mean(int*, int); // Function that returns a double that is the mean of the array passed using bracket
			// notation
double mean2(int*, int); // Function that returns a double that is the mean of the array passed using
				// pointer notation

int *resizeArray(int *arr, int currentSize) {
	int *buff;                              // Create new pointer for new memory allocation
	buff = new int[currentSize + 1];        // Dynamically allocate pointer array to size of current array plus one
	for (int i = 0; i < currentSize; i++) {
		buff[i] = arr[i];                       // Copy all of the original elements of the original array to the new buffer pointer array
	} 
	delete [] arr;              // Delete original array to avoid memory leak
	return buff;                // Return newly allocated array that is one larger than before
}

int main() {

int size = 1;
int *arr;
arr = new int[size];
int input;

for (int i = 0; input != -1; i++) {			// Loops through and asks the user to enter numbers to
                                            // fill the array
	std::cout << "Enter a number: (-1 to exit)" << std::endl;
	std::cin >> input;
	if (input == -1) {          // User input is finished
		break;
	} 
	if (i > (size - 1)) {           // Flag for program to allocate more space in array for more input
		int *temp = resizeArray(arr, size);     // Calls resizeArray and returns a pointer to a newly allocated array that is one size larger
		arr = temp;                         // Assign temp pointer to pointer in main
        size++;                         // Increment counter/flag to keep track of the size
	}
	arr[i] = input;                 // Assign input to current element in array
}

std::cout << "Mean called: " << mean(arr, size) << std::endl;    // Output array mean using array subscript notation
std::cout << "Mean2 called: " << mean2(arr, size) << std::endl;    // Output array mean using pointer arithmetic notation

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