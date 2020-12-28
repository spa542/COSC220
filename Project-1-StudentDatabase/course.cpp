#include "course.h"

/*
 * Default Constructor:
 * This will initialize all private members to default values, as well as
 * initialize the grade to an A in case of no members sent in to initialize
 * them otherwise
 */
Course::Course() {
	name = "";
	department = "";
	semester = "";
	grade = 'A';
}

/*
 * Overloaded Constructor (4 arguments):
 * This will initialize all members to what is passed through by the user
 */
Course::Course(std::string n, std::string d, std::string s, char g) {
	name = n;
	department = d;
	semester = s;
	grade = g;
}

/*
 * getName Function:
 * Returns a string with the name of the course
 */
std::string Course::getName() {
	return name;
}

/*
 * getDepartment Function:
 * Returns a string with the name of the department 
 */
std::string Course::getDepartment() {
	return department;
}

/*
 * getSemester Function:
 * Returns a string with the name of the semester
 */
std::string Course::getSemester() {
	return semester;
}

/*
 * getGrade Function:
 * Returns a character that is the grade of the course
 */
char Course::getGrade() {
	return grade;
}

/*
 * setName Function:
 * Takes a string parameter and sets the name to it
 */
void Course::setName(std::string n) {
	name = n;
}

/*
 * setDepartment Function:
 * Takes a string parameter and sets the department to it
 */
void Course::setDepartment(std::string d) {
	department = d;
}

/*
 * setSemester Function:
 * Takes a string parameter and sets the semester to it
 */
void Course::setSemester(std::string s) {
	semester = s;
}

/*
 * setGrade Function:
 * Takes a char parameter and sets the grade to it
 */
void Course::setGrade(char g) {
	grade = g;
}

/*
 * printCourseInfo Function:
 * Prints out all of the course info
 */
void Course::printCourseInfo() {
	std::cout << "==================================" << std::endl;
	std::cout << "Course Name: " << name << std::endl;
	std::cout << "Department: " << department << std::endl;
	std::cout << "Semester: " << semester << std::endl;
	std::cout << "Grade Received: " << grade << std::endl;	
	std::cout << "==================================\n" << std::endl;
}
