//Video game class

#include <iostream>
#include <cstring>
#include "videogame.h"

VideoGame::VideoGame() { //empty default constructor
}

VideoGame::VideoGame(char* newtitle, int newyear,
		     char* newpublisher, char* newrating) //constructor
  : Parent(newtitle, newyear), publisher(newpublisher), rating(newrating) { //call parent constructor, define fields
  type = new char[10];
  strcpy(type, "VIDEOGAME");
}

char* VideoGame::getType() { //return media type (VIDEOGAME)
  return type;
}

char* VideoGame::getPublisher() { //return publisher
  return publisher;
}

char* VideoGame::getRating() { //return rating
  return rating;
}

VideoGame::~VideoGame() { //destructor, delete pointers
  delete type;
  delete publisher;
  delete rating;
}
