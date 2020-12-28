#include <iostream>
#include "Student.h"
#include "Courses.h"

Student::Student()
{
 name = "Brock";
 birthday = "5.8.01";
 major = "CoSc";
 //this is where this goes right?
   start = nullptr;
};

Student::~Student()
{
  CourseNode *cursor = start;
  while(cursor)
  {
    start = start->next;
    delete cursor;
    cursor = start;  
  }
};

Student::Student(string Name, string Birthday, string Major)
{
  name = Name;
  birthday = Birthday;
  major = Major;
};

string Student::getName() // returns student name
{
  return Student::name;
}

string Student::getBirthday() //takes a month, day, and year
{
  return Student::birthday; 
}

string Student::getMajor() // returns major
{
  return Student::major; 
}

void Student::setName(string newName) // sets name to be input
{
  name = newName;
}

void Student::setBirthday(string newBirthday) // sets birthday to input
{
  birthday = newBirthday;
}

void Student::setMajor(string newMajor) //sets major to input
{
  major = newMajor;
}

void Student::createCourse(string className, string department, string semester, char grade)
{//Want to add a class to a specific student
  CourseNode *newNode = new CourseNode;
  CourseNode *cursor = start;
  newNode->c.setClassName(className);
  newNode->c.setDepartment(department);
  newNode->c.setSemester(semester);
  newNode->c.setGrade(grade);
  newNode->next = nullptr;
    
  if(!start)
  {
   start = newNode;
   return;
  }
  
   while(cursor->next)
  {
    cursor = cursor->next; // cursor then points to the next value to check.   
  }
  cursor->next = newNode;
  delete cursor;
  
}

void Student::updateCourse(Courses newOne, int value)
 {
   CourseNode *cursor = start;
 
   if(!start)
   {
    cout << "You dont have any courses in the list!" << endl;
    return;
   }
   
    for(int i =0; i < value - 1; i++) // travels until cursor points to the node wanted
    {
      cursor = cursor->next;
    }
    cursor->c = newOne; 
    delete cursor;
 }
 
 void Student::removeCourse(int value) //removes a course
{
  CourseNode *cursor = start;
  CourseNode *del = cursor;
  CourseNode *temp = start;
  if((value-2) < 0) // if value is -1, move head forward and delete 1st spot
  {
   start = cursor->next;
   delete temp;
   return;
  }

  for(int i = 0; i < value - 2; i++) // move to node before value
  {
    cursor = cursor->next;
  }
 
    del = cursor->next;
    cursor->next = cursor->next->next;
    delete del;
  
}

void Student::printCourse(int value) //prints courses
{
  //int i = 10;
  CourseNode *cursor = start;
  CourseNode *current = start;
   //cout << i << ". ";
  for(int i = 0; i < value - 2; i++)
  {
    current = current->next;
  }
  while(cursor)
  {
   cout << cursor->c.getClassName() << " ";
   cout << cursor->c.getDepartment() << " ";
   cout << cursor->c.getSemester() << " ";
   cout << cursor->c.getGrade() << endl;
   //i++;
   //cout << i << ". ";
   cursor = cursor->next;
  }
  
  if (!start)
  {
    cout << "No Courses" << endl;
  }
  cout << endl;
}

//operator overload
// void Student::operator=(Courses &other)
// {
//   start = nullptr;
//   CourseNode *newCursor = other.start;
//   
//   while(cursor);
//   {
//     createCourse(newCursor->c);
//     newCursor = newCursor->next;
//   }
// }

bool Student::operator==(Student secondSide)
 {
  if(name==secondSide.getName() && birthday==secondSide.getBirthday() && major==secondSide.getName())
  {
   return true; 
  }
  return false;
 }
 
 void Student::operator=(Student *newOne) //sets a new Obj from the user
 {
   this->setName(newOne->getName());
   this->setBirthday(newOne->getBirthday());
   this->setMajor(newOne->getMajor());
 }

