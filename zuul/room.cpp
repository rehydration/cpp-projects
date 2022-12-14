#include "room.h"

//default constructor
Room::Room() {
}

//initialize room with a description
Room::Room(int newid, char* newdesc, bool newlock) {
  id = newid;
  description = new char[50];
  strcpy(description, newdesc);
  locked = newlock;
}

//connect two rooms
void Room::setPath(char direction, int neighbor) {
  exits[direction] = neighbor;
}

//print room description
void Room::displayDesc() {
  std::cout << description << "\n";
}

//print all items within the room
void Room::displayItems() {
  if (items.size() == 0) std::cout << "There are no items in this room.\n";
  for (auto item : items) {
    std::cout << "There is a " << item.name << " here.\n";
  }
}

//print all possible directions
void Room::displayExits() {
  std::cout << "There are exits:\n";
  //check key values
  for (auto it = exits.begin(); it != exits.end(); ++it) {
    if (it->first == 'N') std::cout << "N\n";
    if (it->first == 'S') std::cout << "S\n";
    if (it->first == 'E') std::cout << "E\n";
    if (it->first == 'W') std::cout << "W\n";
  }
  std::cout << "\n";
}

//return the room in a given direction
int Room::getExit(char direction) {
  //std::cout << exits[direction] << "\n";
  return exits[direction];
}

//adds an item into the vector of items in the room
void Room::setItem(Item item) {
  items.push_back(item);
}

//try to have the user pick up an item, remove from items in room
bool Room::getItem(char* item) {
  for (auto it = items.begin(); it != items.end(); ++it) {
    if (strcmp((*it).name, item) == 0) {
      items.erase(it);
      return true;
    }
  }
  return false;
}

//check if a given direction is a valid exit
bool Room::isExit(char direction) {
  if (!exits.count(direction)) return false;
  return true;
}

//return whether this room is locked
bool Room::isLocked() {
  return locked;
}

Room::~Room() {
  delete description;
  //for (auto item : items) delete item;
}
