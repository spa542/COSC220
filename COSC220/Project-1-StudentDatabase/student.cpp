#include "student.h"

/*
 * Default Constructor:
 * Initializes all values to default values in case nothing is input
 */
Student::Student() {
	name = "";
	dob = "";
	major = "";
}

/*
 * Overloaded Constructor:
 * Initializes all values to the strings that are passed through 
 */
Student::Student(std::string n, std::string d, std::string m) {
	name = n;
	dob = d;
	major = m;
}

/*
 * getName Function:
 * Returns a string that is the name of the student
 */
std::string Student::getName() {
	return name;
}

/*
 * getDOB Function:
 * Returns a string that is the date of birth of the student
 */
std::string Student::getDOB() {
	return dob;
}

/*
 * getMajor Function:
 * Returns a string that is the major of the student
 */
std::string Student::getMajor() {
	return major;
}

/*
 * setName Function:
 * Takes a string as a parameter and sets name to it
 */
void Student::setName(std::string n) {
	name = n;
}

/*
 * setDOB Function:
 * Takes a string as a parameter and sets dob to it
 */
void Student::setDOB(std::string d) {
	dob = d;
}

/* 
 * setMajor Function:
 * Takes a string as a parameter and sets major to it
 */
void Student::setMajor(std::string m) {
	major = m;
}

/*
 * printStudentInfo Function:
 * Prints out all of the private members of the current Student
 */
void Student::printStudentInfo() {
	std::cout << "==========================" << std::endl;
	std::cout << "Name: " << name << std::endl;
	std::cout << "Date of Birth: " << dob << std::endl;
	std::cout << "Major: " << major << std::endl;
	std::cout << "==========================" << std::endl;
}
