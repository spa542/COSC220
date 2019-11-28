#include <iostream> // cout, endl
#include <string> // std::string
#include "course.h" // Course class
#include "student.h" // Student class
#include "StudentDB.h" // StudentDB linked list database

void addStudent(StudentDB&);	// Wrapper for adding a student
void updateStudent(StudentDB&);	// Wrapper for updating a student
void removeStudent(StudentDB&);	// Wrapper for removing a student
void addCourse(StudentDB&);	// Wrapper for adding a course
void removeCourse(StudentDB&);	// Wrapper for removing a course
void updateCourse(StudentDB&);	// Wrapper for updating a course
void printDatabase(StudentDB&);	// Wrapper for printing a database

int main() {

	StudentDB list;
	bool done = false; // loop flag
	int choice; // input variable for user
	
	puts("\t\tWelcome to the Student Database!\n");
	std::cout << "*Every list starts out empty and database is not saved when program commpletes." << std::endl;	// Special directions for correct use of program
	std::cout << "*Every name and course that is searched for must be entered exactly as it is shown in the database in order to ensure correct operations" << std::endl;
	
	do {
		std::cout << "Command List:\n";	// Instructions posted after every loop
		std::cout << "1. Add Student\n";
		std::cout << "2. Update Student\n";
		std::cout << "3. Remove Student\n";
		std::cout << "4. Add Course\n";
		std::cout << "5. Remove Course\n";
		std::cout << "6. Update Course\n";
		std::cout << "7. Print Database\n";
		std::cout << "8. Quit\n";

		std::cout << "\nPlease enter a command (1 - 8): ";
		std::cin >> choice;
		if (choice < 1 || choice > 8)
			continue;

		switch (choice) {	// Commands call each specific function
			
		case 1:
			addStudent(list);
			break;
		case 2:
			updateStudent(list);
			break;
		case 3:
			removeStudent(list);
			break;
		case 4:
			addCourse(list);
			break;
		case 5:
			removeCourse(list);
			break;
		case 6:
			updateCourse(list);
			break;
		case 7:
			printDatabase(list);
			break;
		case 8:
			done = true;
			break;
		}

	} while(!done);

	return 0;
}

/*
 * addStudent Function:
 * Takes a list reference and adds a student to the list after the needed information 
 * is received in order to create the student
 */
void addStudent(StudentDB &l) {
	std::string name, dob, major;
	std::getline(std::cin, name); // clear the buffer
	std::cout << "Enter a student name: ";
	std::getline(std::cin, name);
	std::cout << "\nEnter the student's date of birth (Format ##/##/####): ";
	std::getline(std::cin, dob);
	std::cout << "\nEnter the students major: ";
	std::getline(std::cin, major);
	Student s1(name, dob, major);
	l.addStudent(s1);
}

/* 
 * updateStudent Function:
 * Takes a list reference and updates a specified student by the user
 */
void updateStudent(StudentDB &l) {
	std::cout << "**Enter exactly as displayed in database! " << std::endl;
	std::string newName, newDOB, newMajor, srchName;
	std::getline(std::cin, newName); // clear the buffer
	std::cout << "Enter the new student name: ";
	std::getline(std::cin, newName);
	std::cout << "\nEnter the new student's date of birth: ";
	std::getline(std::cin, newDOB);
	std::cout << "\nEnter the new student's major: ";
	std::getline(std::cin, newMajor);
	std::cout << "\nWhat is the name of the student to update in the database? ";
	std::getline(std::cin, srchName);
	Student s1(newName, newDOB, newMajor);
	l.updateStudent(s1, srchName);
}

/*
 * removeStudent Function:
 * Takes a list reference and removes a specified student by the user
 */
void removeStudent(StudentDB &l) {
	std::cout << "**Enter exactly as displayed in database! " << std::endl;
	std::string srchName;
	std::getline(std::cin, srchName); // clear the buffer
	std::cout << "Enter the name of the student you want to remove from the list: ";
	std::getline(std::cin, srchName);
	l.removeStudent(srchName);
}

/*
 * addCourse Function:
 * Takes a list reference and adds a course to a specified student by the user after 
 * the info for creating is course is also specified
 */
void addCourse(StudentDB &l) {
	std::string name, depart, sem, srchName;
	char grade;
	std::getline(std::cin, name); // clear the buffer
	std::cout << "Enter the name of the course: ";
	std::getline(std::cin, name);
	std::cout << "\nEnter the department of the course: ";
	std::getline(std::cin, depart);
	std::cout << "\nEnter the semester of the course (fa/sp ## year ex. fa19): ";
	std::getline(std::cin, sem);
	do {
		std::cout << "\nEnter the grade earned for the course (capital character A-F): ";
		std::cin >> grade;
	} while ((grade < 'A') || (grade > 'F'));
	std::getline(std::cin, srchName); // clear the buffer
	std::cout << "\n**Enter exactly as displayed in database! ";
	std::cout << "\nEnter the name of the student for the course to be added to: ";
	std::getline(std::cin, srchName);
	Course c1(name, depart, sem, grade);
	l.addCourse(c1, srchName);
}

/*
 * removeCourse Function:
 * Takes a list reference and removes a specified course from a specified student from the 
 * user
 */
void removeCourse(StudentDB &l) {
	std::cout << "**Enter exactly as displayed in database! " << std::endl;
	std::string srchName, srchCourse;
	std::getline(std::cin, srchName); // clear the buffer
	std::cout << "Enter the name of the student whose course you want to remove: ";
	std::getline(std::cin, srchName);
	std::cout << "\nEnter the name of the course to be removed: ";
	std::getline(std::cin, srchCourse);
	l.removeCourse(srchName, srchCourse);
}

/* updateCourse Function:
 * Takes a list reference and updates a specified course to a specified student after the new
 * course data is entered by the user
 */
void updateCourse(StudentDB &l) {
	std::cout << "**Enter exactly as displayed in database! " << std::endl;
	std::string newName, newDepart, newSem, srchName, srchCourse;
	char newGrade;
	std::getline(std::cin, newName); // clear the buffer
	std::cout << "Enter the new name of the course: ";
	std::getline(std::cin, newName);
	std::cout << "\nEnter the new department of the course: ";
	std::getline(std::cin, newDepart);
	std::cout << "\nEnter the new semester of the course: ";
	std::getline(std::cin, newSem);
	do {
		std::cout << "\nEnter the new grade of the course: ";
		std::cin >> newGrade;
	} while ((newGrade < 'A') || (newGrade > 'F'));
	std::getline(std::cin, srchName); // clear the buffer
	std::cout << "\nEnter the name of the student whose course will be updated: ";
	std::getline(std::cin, srchName);
	std::cout << "\nEnter the course of the student that will be updated: ";
	std::getline(std::cin, srchCourse);
	Course c1(newName, newDepart, newSem, newGrade);
	l.updateCourse(srchName, srchCourse, c1);
}

/*
 * printDatabase Function:
 * Takes a list reference and prints the database to the screen
 */
void printDatabase(StudentDB &l) {
	std::cout << "\tDATABASE:\n";
	l.printDatabase();
}
