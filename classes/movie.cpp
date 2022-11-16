#include <iostream>
#include <cstring>
#include "movie.h"

Movie::Movie() { //empty default constructor
}

Movie::Movie(char* newtitle, int newyear,
	     char* newdirector, int newduration, char* newrating) //constructor
  : Parent(newtitle, newyear), director(newdirector), //call parent constructor, define fields
    duration(newduration), rating(newrating) {
  type = new char[6];
  strcpy(type, "MOVIE");
}

char* Movie::getType() { //returns media type (MOVIE)
  return type;
}

char* Movie::getDirector() { //returns director
  return director;
}

int Movie::getDuration() { //returns duration
  return duration;
}

char* Movie::getRating() { //returns rating
  return rating;
}

Movie::~Movie() { //destructor, delete pointers
  delete type;
  delete director;
  delete rating;
}
