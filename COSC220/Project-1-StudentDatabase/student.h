#ifndef _STUDENT_H_
#define _STUDENT_H_
#include <iostream>
#include <string>

class Student {
	private:
		std::string name;
		std::string dob;
		std::string major;
	public:
		Student(); // Default ctor
		Student(std::string, std::string, std::string); // Overloaded ctor
		std::string getName(); // returns name
		std::string getDOB(); // returns dob
		std::string getMajor(); // returns major
		void setName(std::string); // sets name
		void setDOB(std::string); // sets dob
		void setMajor(std::string); // sets major
		void printStudentInfo(); // prints out all Student info
};

#endif
