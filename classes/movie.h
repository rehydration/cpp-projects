//Movie class, contains fields for director, duration, and rating

#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <cstring>
#include "parent.h"

class Movie : public Parent {
 public:
  Movie(); //empty default constructor
  Movie(char* newtitle, int newyear,
	char* newdirector, int newduration, char* newrating); //constructor
  virtual char* getType();
  char* getDirector();
  int getDuration();
  char* getRating();
  virtual ~Movie(); //destructor
 protected:
  char* type;
  char* director;
  int duration;
  char* rating;
};

#endif
