//Music class, contains fields for artist, duration, and publisher

#ifndef MUSIC_H
#define MUSIC_H
#include <iostream>
#include <cstring>
#include "parent.h"

class Music : public Parent {
 public:
  Music(); //default constructor
  Music(char* newtitle, int newyear,
	char* newartist, int newduration, char* newpublisher); //constructor
  virtual char* getType();
  char* getArtist();
  int getDuration();
  char* getPublisher();
  virtual ~Music(); //destructor
 protected:
  char* type;
  char* artist;
  int duration;
  char* publisher;
};

#endif
