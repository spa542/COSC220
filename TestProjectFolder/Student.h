#ifndef STUDENT_H
#define STUDENT_H
#include "Courses.h"
#include <string>
using namespace std;

class Student{
private:
  struct CourseNode //course struct
  {
    Courses c;
    CourseNode *next;
  };
  CourseNode* start; //similar to head
  
string name;
string birthday;
string major;

public:
  
Student();

~Student();
  
Student(string, string, string);

string getName(); //gets student name

void setName(string newName);

string getBirthday(); //takes a month, day, and year

void setBirthday(string newBirthday);

string getMajor(); //asks for student major

void setMajor(string newMajor);

void createCourse(string, string, string, char);

void updateCourse(Courses newOne, int value);

void removeCourse(int);

void printCourse(int);

// void operator=(Courses &other);

bool operator==(Student secondSide);

  void operator=(Student*);
};
#endif