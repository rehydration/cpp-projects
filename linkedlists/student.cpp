#include "student.h"

Student::Student() {
}

Student::Student(char* newfname, char* newlname,
		 int newid, float newgpa) {
  strcpy(fname, newfname);
  strcpy(lname, newlname);
  id = newid;
  gpa = newgpa;
}

//set student first name
void Student::setFname(char* newfname) {
  strcpy(fname, newfname);
}

//set student last name
void Student::setLname(char* newlname) {
  strcpy(lname, newlname);
}

//set student ID
void Student::setID(int newid) {
  id = newid;
}

//set student GPA
void Student::setGPA(float newgpa) {
  gpa = newgpa;
}

//print all fields of student
void Student::display() {
  std::cout << fname << " " << lname << ", " << id << ", " << gpa << "\n";
}

Student::~Student() {
}
