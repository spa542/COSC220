#include <iostream>
#include "StudentDB.h"
#include "Student.h"
#include "Courses.h"

StudentDB::StudentDB()
{
 head = nullptr; 
};

StudentDB::~StudentDB()
{
  StudentNode *cursor = head;
  while(cursor)
  {
    head = head->next;
    delete cursor;
    cursor = head;  
  }
};

void StudentDB::createStudent(string name, string birthday, string major)
{
  StudentNode *newNode = new StudentNode; // creates a dynamic array
  StudentNode *cursor = head; // points cursor to the location of head
  //Student s(name, birthday, major); //calls the constructor
  newNode->s.setName(name);// The value in newNode runs through temp 
  newNode->s.setBirthday(birthday);
  newNode->s.setMajor(major);
  newNode->next = nullptr;

  if(!head)
  {
   head = newNode;
   return;
  }
 
  while(cursor->next)
  {
    cursor = cursor->next; // cursor then points to the next value to check.   
  }
  cursor->next = newNode;
}

void StudentDB::updateStudent(Student *newOne, int value)
 {
   //need to allow the user to choose the student node to change
   StudentNode *cursor = head;
   //StudentNode *temp = head;
   if(!head)
   {
    cout << "You dont have any students in the list!" << endl;
    return;
   }
/*   
   if(value - 1 == 0)
   {
     
   }*/
    for(int i =0; i < value - 1; i++) // travels until cursor points to the node wanted
    {
      cursor = cursor->next;
    }
    cout << "after for" <<endl;
  cursor->s = newOne;
 }

void StudentDB::removeStudent(int value) //removes a student
{
  StudentNode *cursor = head;
  StudentNode *del = cursor;
  StudentNode *temp = head;
  
  if((value-2) < 0) // if value is -1, move head forward and delete 1st spot
  {
   head = cursor->next;
   delete temp;
   return;
  }
  for(int i = 0; i < value - 2; i++)
  {
    cursor = cursor->next;
  }
  
    del = cursor->next;
    cursor->next = cursor->next->next;
    delete del;
  
  
}

// Student operator=(const Student &other)
// { 
//   // want to prevent self-assignment.
//   if(this != &other)
//   {
//     name = other.name;
//     birthday = other.age;
//     major = other.major;
//         // allocate a new array and copy the elements
//         name = other.name;
// 	birthday = other.birthday;
// 	major = other.major;
//    }
//       return *this;
// }

void StudentDB::printStudents() // prints the student names
{
  int i = 1;
  StudentNode *cursor = head;
   //cout << i << ". ";
  while(cursor)
  {
   cout << i << ". ";
   cout << cursor->s.getName() << " ";
   cout << cursor->s.getBirthday() << " ";
   cout << cursor->s.getMajor() << endl;
   i++;
   //cout << i << ". ";
   cursor = cursor->next;
  }
  if (!head)
  {
    cout << "List is empty" << endl;
  }
  cout << endl;
}

int StudentDB::length() // finds how many students are in the list
{
  int count = 0;
  StudentNode *cursor = head;
  while(cursor)
  {
    count++;
   cursor = cursor->next; 
  }
  cout << "There are " << count << " students";
}

// copy constructor
// StudentDB::StudentDB(StudentDB &other) //copy constructor
// {
//   if(other.head == nullptr)
//   {
//    head = nullptr; 
//   }else{
//   StudentNode *cursor = head;
//   StudentNode *newCursor = other.head;
//   while(cursor)
//   {
//     createStudent(cursor->s);
//     cursor->c = newCursor->c;
//     cursor = cursor->next;
//     newCursor = newCursor->next;
//   }
//   }
// };
