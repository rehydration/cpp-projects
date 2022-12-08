#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include "item.h"

class Room {
 public:
  Room();
  Room(int, char*);
  void setPath(char, int);
  void displayDesc();
  void displayItems();
  void displayExits();
  void setItem(char*);
  bool getItem(char*);
  int getExit(char);
  bool isExit(char);
  
  ~Room();
 private:
  int id;
  char* description;
  std::vector<char*> items;
  std::map<char, int> exits;
};

#endif
