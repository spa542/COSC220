#ifndef COURSES_H
#define COURSES_H
#include <string>
using namespace std;

class Courses{
private: 
  string className;
  string department;
  string semester;
  char grade;
public:
string getClassName();
string getDepartment();
string getSemester();
char getGrade();

void setClassName(string newClassName);
void setDepartment(string newDepartment);
void setSemester(string newSemester);
void setGrade(char newGrade);
  
Courses();
Courses(string, string, string, char);
};
#endif