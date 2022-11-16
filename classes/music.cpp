//Music class

#include <iostream>
#include <cstring>
#include "music.h"

Music::Music() { //empty default constructor
}

Music::Music(char* newtitle, int newyear,
	     char* newartist, int newduration, char* newpublisher) //constructor
  : Parent(newtitle, newyear), artist(newartist),
    duration(newduration), publisher(newpublisher) { //call parent constructor & initialize
  type = new char[6];
  strcpy(type, "MUSIC");
}

char* Music::getType() { //returns media type (MUSIC)
  return type;
} 

char* Music::getArtist() { //returns artist
  return artist;
}

int Music::getDuration() { //returns duration
  return duration;
}

char* Music::getPublisher() { //returns publisher
  return publisher;
}

Music::~Music() { //destructor
  delete type;
  delete artist;
  delete publisher;
}
