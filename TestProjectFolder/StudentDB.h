#ifndef STUDENTDB_H
#define STUDENTDB_H
#include "Student.h"
#include "Courses.h"
#include <string>

class StudentDB{
private:
  struct StudentNode //student struct
  {
    Student s;
    StudentNode *next;
  };

  StudentNode* head; //start of the node
 
public:
  StudentDB();
  
  ~StudentDB();
  
  void createStudent(string, string, string);
  
  void updateStudent(Student*, int);

  void removeStudent(int);
  
  void printStudents();
  
  int length();
 
  //StudentDB(StudentDB &other);
  
};
#endif