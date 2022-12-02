#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <vector>
#include <cstring>
#include <map>

class Room {
 public:
  Room();
  void setPath(char, Room*);
  void displayItems();
  void displayExits();
  void setItem(char*);
  void getItem(char*);
  ~Room();
 private:
  std::vector<char*> items;
  std::map<char, Room*> exits;
};

#endif
