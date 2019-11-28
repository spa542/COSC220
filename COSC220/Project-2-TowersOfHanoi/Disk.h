#ifndef _DISK_H_
#define _DISK_H_

class Disk {
	private:
		int size;
	public:
		Disk(); // Default Ctor
		Disk(int); // Constructor to initialize the disk
		int getSize(); // Returns the size of the disk
};

#endif
