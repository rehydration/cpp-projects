//Parent class, provides access to title and year

#ifndef PARENT_H
#define PARENT_H
#include <iostream>
#include <cstring>

class Parent {
 public:
  Parent(); //empty default constructor
  Parent(char* newtitle, int newyear); //constructor
  virtual char* getType();
  char* getTitle();
  int getYear();
  virtual ~Parent(); //destructor
 private:
  char* title;
  int year;
  char* placeholder;
};

#endif
