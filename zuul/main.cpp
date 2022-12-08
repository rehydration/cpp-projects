/*
Name:
Date:

 */


#include <iostream>
#include <vector>
#include "room.h"
#include "item.h"

//move, changing the location of player
void move(std::vector<Room*> rooms, char direction, int& currentRoom) {
  currentRoom = rooms[currentRoom]->getExit(direction);
  return;
}

//if an item is in inventory, drop into current room
bool drop(std::vector<Room*> rooms, std::vector<char*>& inventory, char* item, int currentRoom) {
  for (auto it = inventory.begin(); it != inventory.end(); ++it) {
    if (strcmp(item, *it) == 0) {
      inventory.erase(it);
      rooms[currentRoom]->setItem(item);
      return true;
    }
  }
  return false;
}


int main() {
  std::vector<Room*> rooms;
  std::vector<char*> inventory;
  rooms.push_back(new Room(0, new char[20]{"The first room"}));
  rooms.push_back(new Room(1, new char[20]{"The second room"}));
  rooms.push_back(new Room(2, new char[20]{"The third room"}));
  rooms.push_back(new Room(3, new char[20]{""}));
  rooms.push_back(new Room(4, new char[20]{""}));
  rooms.push_back(new Room(5, new char[20]{"The third room"}));
  rooms.push_back(new Room(6, new char[20]{"The first room"}));
  rooms.push_back(new Room(7, new char[20]{"The second room"}));
  rooms.push_back(new Room(8, new char[20]{"The third room"}));
  rooms.push_back(new Room(9, new char[20]{"The first room"}));
  rooms.push_back(new Room(10, new char[20]{"The second room"}));
  rooms.push_back(new Room(11, new char[20]{"The third room"}));
  rooms.push_back(new Room(12, new char[20]{"The first room"}));
  rooms.push_back(new Room(13, new char[20]{"The second room"}));
  rooms.push_back(new Room(14, new char[20]{"The third room"}));
  rooms.push_back(new Room(15, new char[20]{"The first room"}));
  rooms.push_back(new Room(16, new char[20]{"The second room"}));
  rooms.push_back(new Room(17, new char[20]{"The third room"}));
  
  rooms[0]->setPath('N', 1);
  rooms[1]->setPath('S', 0);
  rooms[1]->setPath('E', 2);
  
  rooms[0]->setItem(new char[20]{"Torch"});
  

  inventory.push_back(new char[20]{"Test"});
  int currentRoom = 0;
  char input[20];
  
  bool playing = true;
  while (playing) {
    rooms[currentRoom]->displayDesc();
    rooms[currentRoom]->displayItems();
    rooms[currentRoom]->displayExits();
    std::cout << "Please enter a command:\n";
    std::cin >> input;

    //try to move
    if (strncmp(input, "go", 2) == 0) {
      char direction;
      std::cin >> direction;

      //check that there is an exit in the given direction, then move
      if (!rooms[currentRoom]->isExit(direction)) std::cout << "No exit exists there.\n";
      else move(rooms, direction, currentRoom);
    }

    //try to pick up an item
    if (strncmp(input, "get", 3) == 0) {
      char item[20];
      std::cin >> item;

      //check if item is present
      if (rooms[currentRoom]->getItem(item)) {
	inventory.push_back(item);
	std::cout << item << " was added to your inventory.\n";
      }
      else std::cout << "No such item was found.\n";
    }

    //try to drop an item from inventory into room
    if (strncmp(input, "drop", 4) == 0) {
      char item[20];
      std::cin >> item;
      
      if (drop(rooms, inventory, item, currentRoom)) std::cout << item << " was dropped.\n";
      else std::cout << "No " << item << " was found.\n";
    }
    
    if (strncmp(input, "quit", 4) == 0) {
      playing = false;
      break;
    }
  }

}
