#include "Disk.h"

/* 
 * Default Constructor:
 * Takes no arguments and initializes the disk to its default value
 */
Disk::Disk() {
	size = 0;
}

/*
 * Overloade Constructor:
 * Takes an int and initializes the disk to the passed parameter
 */
Disk::Disk(int s) {
	size = s;
}

/* 
 * getSize Function:
 * Returns the size of the disk (diameter)
 */
int Disk::getSize() {
	return size;
}
