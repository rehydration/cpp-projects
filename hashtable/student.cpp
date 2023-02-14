//Student class, contains first name, last name, ID, GPA

#include "student.h"

Student::Student() {
}

//constructor
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

//get student ID
int Student::getID() {
  return id;
}

//set student GPA
void Student::setGPA(float newgpa) {
  gpa = newgpa;
}

//return student GPA
float Student::getGPA() {
  return gpa;
}

//print all fields of student
void Student::display() {
  std::cout << fname << " " << lname << ", " << id << ", ";
  std::cout << std::fixed << std::setprecision(2) << gpa << "\n";
}

//destructor
Student::~Student() {
}
