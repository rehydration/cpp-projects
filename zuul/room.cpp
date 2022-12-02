#include "room.h"

Room::Room() {
}

//connect two rooms
void Room::setPath(char direction, Room* neighbor) {
  exits[direction] = neighbor;
}

void Room::displayItems() {
  for (auto item : items) {
    std::cout << "There is a " << item << " here.\n";
  }
}

void Room::displayExits() {
  std::cout << "There are exits:\n";
  for (std::map<char, Room*>::iterator it = exits.begin(); it != exits.end(); ++it) {
    if (it->first == 'N') std::cout << "NORTH\n";
    if (it->first == 'S') std::cout << "SOUTH\n";
  }
}

//adds an item into the list of items in the room
void Room::setItem(char* item) {
  items.push_back(item);
}

//user picks up item, remove from items in room
void Room::getItem(char* takenItem) {
  for (auto item : items) {
    if (strcmp(item, takenItem) == 0) {
      //items.erase(item);
      return;
    }
  }
}

Room::~Room() {
}
