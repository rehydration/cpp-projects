//Video game class, contains fields for publisher and rating

#ifndef VIDEOGAME_H
#define VIDEOGAME_H
#include <iostream>
#include <cstring>
#include "parent.h"

class VideoGame : public Parent {
public:
  VideoGame(); //empty default constructor
  VideoGame(char* newtitle, int newyear,
	    char* newpublisher, char* newrating); //constructor
  virtual char* getType();
  char* getPublisher();
  char* getRating();
  virtual ~VideoGame(); //destructor
private:
  char* type;
  char* publisher;
  char* rating;
};

#endif
