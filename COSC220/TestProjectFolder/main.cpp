#include <iostream>
#include "Student.h"
#include "Courses.h"
#include "StudentDB.h"
#include <string>
#include <fstream>
//TODO Edit so when Student list is printed, courses are printed too
using namespace std;
StudentDB *StudentList = new StudentDB();
Student *CourseList = new Student();
int main()
{
  int value = 0;
  int userInput;
  char YesorNo;
  bool run = true;
  string name;
  string birthday;
  string major;
  string className;
  string department;
  string semester;
  char grade;
  //reads in a file of students
     ifstream info;
     info.open("ListofStudents");
     while(!info.eof())
     {
      string name = "";
      string birthday;
      string major;
      info >> name >> birthday >> major;
      StudentList->createStudent(name, birthday, major);
     }
     info.close();
     
     //want it allow the user to add to the classes list
     ifstream classes; //reads in a list a classes
     classes.open("ListofCourses");
     while(!info.eof())
     {
      string department;
      classes >> department;
      cout << "1) " << department<<endl;
     }
      info.close();
      
  do{ //the menu
    cout << "What would you like to do?" << endl;
    cout << "1) Add a student " << endl;
    cout << "2) Add a course " << endl;
    cout << "3) Update a student " << endl;
    cout << "4) Update a course " << endl;
    cout << "5) Remove a student " << endl;
    cout << "6) Remove a course " << endl;
    cout << "7) Print Student List " << endl;
    cout << "8) Print Course List " << endl;
    cout << "9) End Program " << endl;
    cin >> userInput;
  
    if(userInput == 1) //add student
    {
      YesorNo = 'y';
	while (YesorNo == 'y')
      {
	cout << "What is the student's name?" << endl;
	cin >> name;
	cout << "What is the student's birthday? ex: 01.23.98" << endl;
	cin >> birthday;
	cout << "What is the student's major?" << endl;
	cin >> major; 
	
	//reads into the student file
// 	info.open("ListofStudents"); 
// 	info >> name >> birthday >> major;
// 	info.close();
	//creates the student
	StudentList->createStudent(name, birthday, major);
	cout << "Would you like to add another student? y or n" << endl;
	cin >> YesorNo;
	cout << endl;
      }
      StudentList->printStudents();
    }
    
    if(userInput == 2) //adds a course
    {
      YesorNo = 'y';
      while (YesorNo == 'y')
      {
	cout << "Which student would you like to create a class for?" << endl;
	StudentList->printStudents();
	cin >> value;
	cout << "What is the name of the class? ex: COSC117 " << endl;
	cin >> className;
	cout << "Enter the name of the class department. ex: COSC" << endl;
	cin >> department;
	cout << "Enter the semester the class was taken. ex: Fall19" << endl;
	cin >> semester;
	cout << "Grade received: " << endl;
	cin >> grade;
	//creates the course
	CourseList->createCourse(className, department, semester, grade);
	cout << "Would you like to add another class? y or n" << endl;
	cin >> YesorNo;
	cout << endl;
      }
      CourseList->printCourse(value);
    }
    
    if(userInput == 3) // updates a student info
    {
      int value;
      string name;
      string birthday;
      string major;
     YesorNo = 'y';
     while(YesorNo == 'y')
     {
	cout << "What is the number of the student you want to change?" << endl;
	StudentList->printStudents();
	cin >> value;
	cout << "Enter their name: ";
	cin >> name;
	cout << "Enter their birthday: ";
	cin >> birthday;
	cout << "Enter their major: ";
	cin >> major;
	//creates a temp object
	Student *temp = new Student(name, birthday, major);
	//puts the temp obj into the update function
	StudentList->updateStudent(temp, value);
	delete temp;
	cout << "Would you like to change another student?" << endl;;
	cin >> YesorNo;
	cout << endl;
     }
     StudentList->printStudents();
    }
    
    if(userInput == 4) //updates a course
    {
      int value;
      string className;
      string department;
      string semester;
      char grade;
      //values taken in
     YesorNo = 'y';
     CourseList->printCourse(value);
     while(YesorNo == 'y') //while they want to continue
     {
	cout << "What is the number of the course you want to change?" << endl;
	cin >> value;
	cout << "Enter the class name: ";
	cin >> className;
	cout << "Enter the department: ";
	cin >> department;
	cout << "Enter the semester: ";
	cin >> semester;
	cout << "Enter the grade received: ";
	cin >> grade;
	Courses temp(className, department, semester, grade);
	CourseList->updateCourse(temp, value); //calls the update function
	cout << "Would you like to change another course? y or n" << endl;;
	cin >> YesorNo; //do you want to continue
	cout << endl;
     }
     CourseList->printCourse(value); //print the students
    }
    
    if(userInput == 5) //remove a student
    {
     StudentList->printStudents();
     YesorNo = 'y';
     while(YesorNo == 'y')
     {
       cout << "Enter the number of the Student you would like to remove? " << endl;
       cin >> value;
       while(value > sizeof(StudentList)) //if the value is greater than size
       {
	cout << "Not a valid Student. Try again." << endl; 
	cin >> value;
       }
       StudentList->removeStudent(value);
       cout << endl;
       StudentList->printStudents();
       YesorNo = 'n';
     }
    }
    
    if(userInput == 6) //removes a course
    {
      CourseList->printCourse(value);
     YesorNo = 'y';
     while(YesorNo == 'y')
     {
       cout << "Enter the number of the course you would like to remove? " << endl;
       cin >> value;
       while(value > sizeof(CourseList))
       {
	cout << "Not a valid course. Try again." << endl; 
	cin >> value;
       }
       CourseList->removeCourse(value);
       cout << endl;
       CourseList->printCourse(value); //prints after the removal
       YesorNo = 'n';
     }
    }
    
    if(userInput == 7) //print the students
    {
      cout << "Here is the list of students: " << endl;
      cout << endl;
      StudentList->printStudents();
    }
    
    if(userInput == 8)
    {
      int value;
      cout << "Enter which Student you'd like to see the courses of: " << endl;
      StudentList->printStudents();
      cin >> value;
      CourseList->printCourse(value);
    }
    
    if(userInput == 9) // end program
    {
      cout << "Goodbye" << endl;
      break;
    }
  } while(run);
}