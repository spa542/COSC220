#include "StudentDB.h"

/*
 * findStudent Function:
 * Takes a string that is the name of the student to be searched for, as well as a pointer to the 
 * head of the list, and returns a StudentNode pointer to the student that was being searched for
 */
StudentDB::StudentNode* StudentDB::findStudent(std::string search) {
	StudentNode* cursor = head;
	if (head == nullptr) {
		std::cout << "The list is empty and no student can be searched for" << std::endl;
		return nullptr;
	}
	while (cursor) {
		if (search.compare(cursor->s.getName()) == 0) {
			return cursor;
		}
		cursor = cursor->snext;
	}
	return nullptr;
}

/*
 * findCourse Function:
 * Takes a string that is the name of the course that is to be searched for and returns a CourseNode
 * pointer to the Course that was being searched for
 */
StudentDB::CourseNode* StudentDB::findCourse(std::string stud, std::string search) {
	StudentNode* currStud = findStudent(stud);
	if (currStud == nullptr) {
		std::cout << "No student was found! Please enter the name exactly as displayed." << std::endl;
		return nullptr;
	}
	if (currStud->chead == nullptr) {
		std::cout << "No courses are assigned to the current student" << std::endl;
		return nullptr;
	}
	CourseNode* cursor = currStud->chead;
	while (cursor) {
		if (search.compare(cursor->c.getName()) == 0) {
			return cursor;
		}
		cursor = cursor->cnext;
	}
	return nullptr;
}

/* Copy Constructor:
 * This constructor copies the list over for a deep copy
 */
StudentDB::StudentDB(const StudentDB &rhs) {
	head = nullptr;
	StudentNode* cursor = rhs.head;
	if (cursor == nullptr) {
		return;
	}	
	CourseNode* down = cursor->chead;
	while (cursor) {
		addStudent(cursor->s);
		while (down) {
			addCourse(down->c, cursor->s.getName());
			down = down->cnext;
		}
		cursor = cursor->snext;
		if (cursor) {
			down = cursor->chead;
		}
	}
}

/* Overloaded Assignment:
 * Allows the ability to assign one list to another to copy it over to the other list
 */
StudentDB StudentDB::operator=(const StudentDB &rhs) {
	if (this == &rhs) {
		return *this;
	}	
	// Delete current objects dynamic memory
	StudentNode* dCursor = head;
        CourseNode* dDown;
        CourseNode* follow;
        while (dCursor) {
                dCursor = dCursor->snext;
                dDown = head->chead;
                follow = dDown;
                delete head;
                while (dDown) {
                        dDown = dDown->cnext;
                        delete follow;
                        follow = dDown;
                }
                head = dCursor;
	}
	// Copy everything over
	head = nullptr;
	StudentNode* cursor = rhs.head;
	if (cursor == nullptr) {
		StudentDB temp;
		return temp;
	}
	CourseNode* down = cursor->chead;
	while (cursor) {
		addStudent(cursor->s);
		while (down) {
			addCourse(down->c, cursor->s.getName());
			down = down->cnext;
		}
		cursor = cursor->snext;
		if (cursor) {
			down = cursor->chead;
		}
	}
	return *this;
}

/*
 * Default Constructor:
 * Initializes list to empty
 */
StudentDB::StudentDB() {
	head = nullptr;
}

/*
 * Destructor:
 * Destroys all dynamically allocated memory
 */
StudentDB::~StudentDB() {
	StudentNode* cursor = head;
	CourseNode* down;
	CourseNode* follow;
	while (cursor) {
		cursor = cursor->snext;
		down = head->chead;
		follow = down;
		delete head;
		while (down) {
			down = down->cnext;
			delete follow;
			follow = down;
		}
		head = cursor;
	}
}

/*
 * addStudent Function:
 * Takes a Student object and appends a student node to the list
 */
void StudentDB::addStudent(Student obj) {
	StudentNode* newNode = new StudentNode;
	newNode->s = obj;
	newNode->snext = nullptr;
	newNode->chead = nullptr;

	if (head == nullptr) {
		head = newNode;
		return;
	}

	StudentNode* cursor = head;
	while (cursor->snext) {
		cursor = cursor->snext;
	}
	cursor->snext = newNode;
}

/*
 * updateStudent Function:
 * Takes a Student object, and a string that will be the name of the student
 * that needs to be updated, the object passed will replace the student node with 
 * the name that was passed through
 */
void StudentDB::updateStudent(Student obj, std::string srchName) {
	StudentNode* currStud = findStudent(srchName);
	if (currStud == nullptr) {
		std::cout << "Name not found! Please enter search name exactly as displayed in database" << std::endl;
		return;
	}
	currStud->s = obj;
}

/*
 * removeStudent Function:
 * Takes a string that is the name of a student to be removed and then is removed
 * from the list
 */
void StudentDB::removeStudent(std::string srchName) {
	StudentNode* currStud = findStudent(srchName);
	if (currStud == nullptr) {
		std::cout << "Name not found! Please enter the search name exactly as displayed in database" << std::endl;
		return;
	}
	if (currStud == head) {
		head = head->snext;
		CourseNode* down = currStud->chead;
		while (down) {
			down = down->cnext;
			delete currStud->chead;
			currStud->chead = down;
		}
		delete currStud;
		return;
	}

	StudentNode* cursor = head;
	while (cursor->snext != currStud) {
		cursor = cursor->snext;
	}
	if (currStud->snext == nullptr) {
		cursor->snext = nullptr;
		CourseNode* down = currStud->chead;
		while (down) {
			down = down->cnext;
			delete currStud->chead;
			currStud->chead = down;
		}
		delete currStud;
		return;
	}
	cursor->snext = currStud->snext;
	CourseNode* down = currStud->chead;
	while (down) {
		down = down->cnext;
		delete currStud->chead;
		currStud->chead = down;
	}
	delete currStud;
}

/*
 * addCourse Function:
 * Takes a Course object and a string of the student that the course will be appended to
 */
void StudentDB::addCourse(Course obj, std::string srchName) {
	StudentNode* currStud = findStudent(srchName);
	if (currStud == nullptr) {
		std::cout << "Name not found in list. (Name must be exactly as found in database)" << std::endl;
		return;
	}

	CourseNode* newNode = new CourseNode;
	newNode->c = obj;
	newNode->cnext = nullptr;

	if (currStud->chead == nullptr) {
		currStud->chead = newNode;
		return;
	}
	CourseNode* cursor = currStud->chead;
	while (cursor->cnext) {
		cursor = cursor->cnext;
	}
	cursor->cnext = newNode;
}

/*
 * removeCourse Function:
 * Takes a string of the student that has the course to be removed as well as the course
 * to be removed and then will be removed from the current student in the list
 */
void StudentDB::removeCourse(std::string srchStud, std::string srchCrse) {
	StudentNode* currStud = findStudent(srchStud);
	if (currStud == nullptr) {
		std::cout << "No student found in list! Please enter name exactly as they are displayed" << std::endl;
		return;
	}
	CourseNode* currCourse = findCourse(srchStud, srchCrse);
	if (currCourse == nullptr) {
		std::cout << "No course found in list! Please enter name exactly as they are displayed" << std::endl;
		return;
	}
	if (currCourse == currStud->chead) {
		currStud->chead = currStud->chead->cnext;
		delete currCourse;
		return;
	}
	CourseNode* cursor = currStud->chead;
	while (cursor->cnext != currCourse) {
		cursor = cursor->cnext;
	}
	if (currCourse->cnext == nullptr) {
		cursor->cnext = nullptr;
		delete currCourse;
		return;
	}
	cursor->cnext = currCourse->cnext;
	delete currCourse;
}

/*
 * updateCoures Function:
 *  Takes a string of the student name and a string of a course name that belongs to the student, 
 *  and the Course object to update the course that was passed for the student
 */
void StudentDB::updateCourse(std::string srchStud, std::string srchCrse, Course obj) {
	CourseNode* currCourse = findCourse(srchStud, srchCrse);
	if (currCourse == nullptr) {
		std::cout << "Course not found on current list! Please type in course name exactly as displayed in database." << std::endl;
		return;
	}
	currCourse->c = obj;
}

/*
 * printDatabase Function:
 * Prints all of the students and all their corresponding courses from the list
 */
void StudentDB::printDatabase() {
	if (head == nullptr) {
		std::cout << "The list is empty, nothing to output" << std::endl;
		return;
	}
	StudentNode* cursor = head;
	CourseNode* cCursor = cursor->chead;
	while (cursor) {
		cursor->s.printStudentInfo();
		while (cCursor) {
			if (cCursor == cursor->chead) {
				std::cout << "------------Courses------------\n";
			}
			cCursor->c.printCourseInfo();
			cCursor = cCursor->cnext;
		}
		if (cursor->chead == nullptr) {
			std::cout << "Currently no courses assigned" << std::endl;
		}
		cursor = cursor->snext;
		if (cursor != nullptr) {
			cCursor = cursor->chead;
		}
	}
}
