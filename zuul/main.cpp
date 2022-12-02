/*
Name:
Date:

 */


#include <iostream>
#include <vector>
#include "room.h"
#include "item.h"

void move(char direction, Room* currentRoom) {
  currentRoom = currentRoom->getExit(direction);
}

bool get(item item) {
  return false;
}

bool drop(std::vector<char*>& inventory, char* item, Room* currentRoom) {
  for (auto it = inventory.begin(); it != inventory.end(); ++it) {
    if (strcmp(item, *it) == 0) {
      inventory.erase(it);
      currentRoom->setItem(item);
      return true;
    }
  }
  return false;
}

  
int main() {
  std::vector<Room*> rooms;
  Room* startRoom = new Room();
  Room* room1 = new Room();
  Room* room2 = new Room();
  rooms.push_back(new Room());

  startRoom->setPath('N', room1);

  startRoom->setItem("Torch");
  room1->setItem("Test");
  
  std::vector<char*> inventory;
  inventory.push_back(new char[20]{"Test"});
  int currentRoom = 0;
  
  bool playing = true;
  while (playing) {
    char input[10];
    currentRoom->displayItems();
    currentRoom->displayExits();
    std::cin >> input;

    if (strncmp(input, "go", 2) == 0) {
      char direction;
      std::cin >> direction;
      if (!currentRoom->isExit(direction)) std::cout << "No such direction exists.\n";
      else move(direction, currentRoom);
    }

    if (strncmp(input, "get", 3) == 0) {
      char item[20];
      std::cin >> item;
      bool success = currentRoom->getItem(item);
      if (success) {
	inventory.push_back(item);
	std::cout << item << " was added to your inventory.\n";
      }
      else std::cout << "No such item was found.\n";
    }

    if (strncmp(input, "drop", 4) == 0) { //remove item from inventory into room
      char item[20];
      std::cin >> item;
      bool success = drop(inventory, item, currentRoom);
      if (success) std::cout << item << " was dropped.\n";
      else std::cout << "No " << item << " was found.\n";
    }
    
    if (strncmp(input, "quit", 4) == 0) {
      playing = false;
      break;
    }
  }

}
