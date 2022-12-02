#include "room.h"

//default constructor
Room::Room() {
}

//initialize room with a description
Room::Room(char* newdesc) {
  strcpy(description, newdesc);
}

//connect two rooms
void Room::setPath(char direction, Room* neighbor) {
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
    std::cout << "There is a " << item << " here.\n";
  }
}

//print all possible directions
void Room::displayExits() {
  std::cout << "There are exits:\n";
  for (auto it = exits.begin(); it != exits.end(); ++it) {
    if (it->first == 'N') std::cout << "NORTH\n";
    if (it->first == 'S') std::cout << "SOUTH\n";
    if (it->first == 'E') std::cout << "EAST\n";
    if (it->first == 'W') std::cout << "WEST\n";
  }
  std::cout << "\n";
}

Room* Room::getExit(char direction) {
  std::cout << exits[direction] << "\n";
  return exits[direction];
}

//adds an item into the vector of items in the room
void Room::setItem(char* item) {
  items.push_back(item);
}

//try to have the user pick up an item, remove from items in room
bool Room::getItem(char* takenItem) {
  for (auto it = items.begin(); it != items.end(); ++it) {
    if (strcmp(*it, takenItem) == 0) {
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

Room::~Room() {
}
