#include <iostream>
#include "Courses.h"

//non default constuctor

Courses::Courses()
{
  className = "COSC220";
  department = "COSC";
  semester = "fal19";
  grade = 'B';
};

Courses::Courses(string Class, string Department, string Semester, char Grade)
{
  className = Class;
  department = Department;
  semester = Semester;
  grade = Grade;
};

string Courses::getClassName()
{
  return Courses::className;
}

string Courses::getDepartment()
{
  return Courses::department;
}

string Courses::getSemester()
{
 return Courses::semester; 
}

char Courses::getGrade()
{
 return Courses::grade;
}

void Courses::setClassName(string newClassName)
{
  className = newClassName;
}

void Courses::setDepartment(string newDepartment)
{
  department = newDepartment;
}

void Courses::setSemester(string newSemester) 
{
  semester = newSemester;
}

void Courses::setGrade(char newGrade)
{
  grade = newGrade;
}
