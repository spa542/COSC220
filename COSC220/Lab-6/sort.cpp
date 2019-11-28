#include <iostream> // cout
#include <stdio.h> // srand, rand()
#include <time.h> // time functions
#include <chrono> // using crhono and time clocking algorithms

int count = 0;

void bubbleSort(int*, int, bool);	// sort the funtion using bubble sort algorithm
void selectionSort(int*, int, bool);	// sort the function using selection sort algorithm
void insertionSort(int*, int, bool);	// sort the function using insertion sort algorithm
int* makeArray(int);			// creates a dynamic array of integers
void printArray(int*, int);		// prints the array to the screen
void swap(int&, int&);			// swaps two integers that are passed by reference
bool isSorted(int*, int, bool);		// tests to see if the array is sorted in the correct order

int main() {
	bool ascending = true;	// boolean to see which way the array is to be sorted
	srand(time(NULL));	// seed the random number generator
	int sizesLen = 13;	
	int sizes[] = {10, 20, 50, 500, 700, 1000, 5000, 7500, 12000, 25000, 50000, 60000, 100000}; // Amount of integers test cases

	for (int i = 0; i < sizesLen; i++) {	// Bubble sort ascending tests
		int *arr = makeArray(sizes[i]);
		int len = sizes[i];
		std::cout << "Starting bubble sort in ascending order of array of " << len << " integers\n";
		auto start = std::chrono::system_clock::now();
		
		bubbleSort(arr, len, ascending);
		
		auto end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds = end - start; 
		std::time_t end_time = std::chrono::system_clock::to_time_t(end);
		std::cout << "Finished at " << std::ctime(&end_time) << "Elapsed time: " << elapsed_seconds.count() << "s\n";
		std::cout << "Amount of swaps: " << count << std::endl;
		if (isSorted(arr, len, ascending)) {
			std::cout << "Sorted in ascending order!" << std::endl;
		}
		count = 0;
		delete [] arr;
	}
	
	std::cout << "===============================================" << std::endl;

	for (int i = 0; i < sizesLen; i++) {	// Selection sort ascending tests
		int *arr = makeArray(sizes[i]);
                int len = sizes[i];
                std::cout << "Starting selection sort in ascending order of array of " << len << " integers\n";
                auto start = std::chrono::system_clock::now();

               	selectionSort(arr, len, ascending);

                auto end = std::chrono::system_clock::now();
                std::chrono::duration<double> elapsed_seconds = end - start;
                std::time_t end_time = std::chrono::system_clock::to_time_t(end);
                std::cout << "Finished at " << std::ctime(&end_time) << "Elapsed time: " << elapsed_seconds.count() << "s\n";
                std::cout << "Amount of swaps: " << count << std::endl;
                if (isSorted(arr, len, ascending)) {
                        std::cout << "Sorted in ascending order!" << std::endl;
                }
                count = 0;
                delete [] arr;
	}

	std::cout << "===============================================" << std::endl;
	
	for (int i = 0; i < sizesLen; i++) {	// Insertion sort ascending tests
		int *arr = makeArray(sizes[i]);
                int len = sizes[i];
                std::cout << "Starting insertion sort in ascending order of array of " << len << " integers\n";
                auto start = std::chrono::system_clock::now();

                insertionSort(arr, len, ascending);

                auto end = std::chrono::system_clock::now();
                std::chrono::duration<double> elapsed_seconds = end - start;
                std::time_t end_time = std::chrono::system_clock::to_time_t(end);
                std::cout << "Finished at " << std::ctime(&end_time) << "Elapsed time: " << elapsed_seconds.count() << "s\n";
                std::cout << "Amount of swaps: " << count << std::endl;
                if (isSorted(arr, len, ascending)) {
                        std::cout << "Sorted in ascending order!" << std::endl;
                }
                count = 0;
                delete [] arr;
	}
	
	std::cout << "===============================================" << std::endl;
	
	ascending = false;	// change to descending order tests

	for (int i = 0; i < sizesLen; i++) {	// Bubble sort descending tests
                int *arr = makeArray(sizes[i]);
                int len = sizes[i];
                std::cout << "Starting bubble sort in descending order of array of " << len << " integers\n";
                auto start = std::chrono::system_clock::now();

                bubbleSort(arr, len, ascending);

                auto end = std::chrono::system_clock::now();
                std::chrono::duration<double> elapsed_seconds = end - start;
                std::time_t end_time = std::chrono::system_clock::to_time_t(end);
                std::cout << "Finished at " << std::ctime(&end_time) << "Elapsed time: " << elapsed_seconds.count() << "s\n";
                std::cout << "Amount of swaps: " << count << std::endl;
                if (isSorted(arr, len, ascending)) {
                        std::cout << "Sorted in descending order!" << std::endl;
                }
                count = 0;
                delete [] arr;
	}

	std::cout << "===============================================" << std::endl;

	for (int i = 0; i < sizesLen; i++) {	// Selection sort descendng tests
                int *arr = makeArray(sizes[i]);
                int len = sizes[i];
                std::cout << "Starting selection sort in descending order of array of " << len << " integers\n";
                auto start = std::chrono::system_clock::now();

                selectionSort(arr, len, ascending);

                auto end = std::chrono::system_clock::now();
                std::chrono::duration<double> elapsed_seconds = end - start;
                std::time_t end_time = std::chrono::system_clock::to_time_t(end);
                std::cout << "Finished at " << std::ctime(&end_time) << "Elapsed time: " << elapsed_seconds.count() << "s\n";
                std::cout << "Amount of swaps: " << count << std::endl;
                if (isSorted(arr, len, ascending)) {
                        std::cout << "Sorted in descending order!" << std::endl;
                }
                count = 0;
                delete [] arr;
	}

	std::cout << "===============================================" << std::endl;
	
	for (int i = 0; i < sizesLen; i++) {	// Insertion sort descending tests
                int *arr = makeArray(sizes[i]);
                int len = sizes[i];
                std::cout << "Starting insertion sort in descending order of array of " << len << " integers\n";
                auto start = std::chrono::system_clock::now();

                insertionSort(arr, len, ascending);

                auto end = std::chrono::system_clock::now();
                std::chrono::duration<double> elapsed_seconds = end - start;
                std::time_t end_time = std::chrono::system_clock::to_time_t(end);
                std::cout << "Finished at " << std::ctime(&end_time) << "Elapsed time: " << elapsed_seconds.count() << "s\n";
                std::cout << "Amount of swaps: " << count << std::endl;
                if (isSorted(arr, len, ascending)) {
                        std::cout << "Sorted in descending order!" << std::endl;
                }
                count = 0;
                delete [] arr;
	}
	
	return 0;
}

/*
 * isSorted Function:
 * Takes a a dynamic array, a length of that array, and whether the array is supposed to be sorted
 * in ascending or descending order and then determines if the array is sorted correctly
 */
bool isSorted(int* arr, int length, bool ascending) {
	if (ascending) {
		for (int i = 0; i < (length - 1); i++) {
			if (arr[i] > arr[i + 1]) {
				return false;
			}
		}
		return true;
	} else {
		for (int i = 0; i < (length - 1); i++) {
			if (arr[i] < arr[i + 1]) {
				return false;
			}
		}
		return true;
	}
}

/*
 * makeArray Function:
 * Takes an int that is the length of an array and then dynamically creates that array and returns
 * a pointer to that array
 */
int* makeArray(int len) {
        int *rtn = new int[len];
        for (int i = 0; i < len; i++) {
                rtn[i] = 1 + rand() % 100; // from 1 to 100
        }
        return rtn;
}

/*
 * swap Function:
 * Takes two array elements by referene and swaps them
 */
void swap(int& prev, int& next) {
	int temp = prev;
	prev = next;
	next = temp;
	count++; // remember to make it 0 after each test
}

/*
 * bubbleSort Function:
 * Takes a dynamic array, the length of the array, and whether the array is to be sorted in ascending
 * or descending and then sorts the array
 */
void bubbleSort(int* arr, int length, bool ascending) {
	bool didSwap = true;
	while (didSwap) {
		didSwap = false;
		for (int i = 0; i < (length - 1); i++) {
			if (ascending) {
				if (arr[i] > arr[i + 1]) {
					swap(arr[i], arr[i + 1]);
					didSwap = true;	
				}
			} else {
				if (arr[i] < arr[i + 1]) {
					swap(arr[i], arr[i + 1]);
					didSwap = true;	
				}
			}
		}
	}
}

/* 
 * selectionSort Function:
 * Takes a dynamic array, the length of the array, and whether the array is to be sorted in ascending 
 * or descending order and then sorts the array
 */
void selectionSort(int* arr, int length, bool ascending) {
	int min;
	for (int i = 0; i < length - 1; i++) {
		min = i;
		for (int j = i + 1; j < length; j++) {
			if (ascending) {
				if (arr[j] < arr[min]) {
					min = j;
				}
			} else {
				if (arr[j] > arr[min]) {
					min = j;
				}
			}
		}
	swap(arr[i], arr[min]);
	}		
}

/*
 * insertionSort Function:
 * Takes a dynamic array, the length of the array, and whether the array is to be sorted in ascending
 * or descending order and then sorts the array
 */
void insertionSort(int* arr, int length, bool ascending) {
	int j;
	for (int i = 1; i < length; i++) {
		j = i;
		if (ascending) {
			while ((j > 0) && (arr[j] < arr[j - 1])) {
				swap(arr[j], arr[j - 1]);
				j = j - 1;
			}	
		} else {
			while ((j > 0) && (arr[j] > arr[j - 1])) {
				swap(arr[j], arr[j - 1]);
				j = j - 1;
			}
		}
	}
}

/*
 * printArray Function:
 * Takes a dynamic array and the length of the array and prints all of the contents of the array
 * to the screen
 */
void printArray(int* arr, int length) {
	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	puts("====================");
}
