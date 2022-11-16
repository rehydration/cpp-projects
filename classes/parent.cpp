//Parent class

#include <iostream>
#include <cstring>
#include "parent.h"

Parent::Parent() { //empty default constructor
}

Parent::Parent(char* newtitle, int newyear)
  : title(newtitle), year(newyear) { //constructor
  placeholder = new char[1];
}

char* Parent::getType() { //virtual function, unused here
  return placeholder;
}

char* Parent::getTitle() { //returns title
  return title;
}

int Parent::getYear() { //returns year
  return year;
}

Parent::~Parent() { //destructor, delete pointers
  delete title;
  delete placeholder;
}
