#ifndef _STUDENTDB_H_
#define _STUDENTDB_H_
#include <string>
#include <iostream>
#include "course.h"
#include "student.h"

class StudentDB {
	private:
		struct CourseNode {
			Course c;
			CourseNode* cnext;
		};

		struct StudentNode {
			Student s;
			StudentNode* snext;
			CourseNode* chead;
		};

		StudentNode* head;
		
		StudentNode *findStudent(std::string);
		CourseNode *findCourse(std::string, std::string);
	public:
		StudentDB(); // Default ctor
		~StudentDB(); // Destructor
		StudentDB(const StudentDB&); // Copy ctor
		StudentDB operator=(const StudentDB&); // Overloaded assignment
		void addStudent(Student); // adds a student to list
		void updateStudent(Student, std::string); // updates a student to new student passed
		void removeStudent(std::string); // removes a student
		void addCourse(Course, std::string); // pass name of student and new Course obj
		void removeCourse(std::string, std::string); // removes Course from student passed
		void updateCourse(std::string, std::string, Course); // updates course at student and course passed through
		void printDatabase(); // prints all students and all their corresponding courses
};

#endif
