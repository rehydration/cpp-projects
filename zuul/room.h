//Room class
//holds items, exits, locked

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
  Room(int, char*, bool);
  void setPath(char, int);
  void displayDesc();
  void displayItems();
  void displayExits();
  void setItem(Item);
  bool getItem(char*);
  int getExit(char);
  bool isExit(char);
  bool isLocked();
  
  ~Room();
 private:
  int id;
  char* description;
  bool locked;
  std::vector<Item> items;
  std::map<char, int> exits;
};

#endif
