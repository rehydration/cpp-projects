#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <cstring>
#include <iomanip>

class Student {
public:
  Student();
  Student(char*, char*, int, float);
  void setFname(char*);
  void setLname(char*);
  void setID(int);
  int getID();
  void setGPA(float);
  float getGPA();
  void display();
  ~Student();
private:
  char fname[20], lname[20];
  int id;
  float gpa;
};


#endif
  
