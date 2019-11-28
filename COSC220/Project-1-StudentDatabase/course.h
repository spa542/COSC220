#ifndef _COURSE_H_
#define _COURSE_H_
#include <iostream>
#include <string>

class Course {
	private:
		std::string name;
		std::string department;
		std::string semester;
		char grade;
	public:
		Course(); // Default ctor
		Course(std::string, std::string, std::string, char); // Overloaded ctor
		std::string getName(); // returns name
		std::string getDepartment(); // returns department
		std::string getSemester(); // returns semester
		char getGrade();	// returns grade
		void setName(std::string); // sets name
		void setDepartment(std::string); // sets department
		void setSemester(std::string); // sets semester
		void setGrade(char); // sets grade
		void printCourseInfo(); // prints all course info
};

#endif
