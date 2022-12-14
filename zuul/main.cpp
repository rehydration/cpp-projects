/*
Name: Nathan Zhou
Date:

Plays the text based adventure game Zuul. The player can move between rooms and drop/pick up items.

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
bool drop(std::vector<Room*> rooms, std::vector<Item>& inventory, char* item, int currentRoom) {
  for (auto it = inventory.begin(); it != inventory.end(); ++it) {
    if (strcmp(item, (*it).name) == 0) {
      rooms[currentRoom]->setItem(*it);
      inventory.erase(it);
      return true;
    }
  }
  return false;
}

//search the player inventory for an item
bool held(std::vector<Item> inventory, char* item) {
  for (auto it : inventory) {
    if (strcmp(item, it.name) == 0) return true;
  }
  return false;
}

int main() {
  std::vector<Room*> rooms;
  std::vector<Item> inventory;
  
  rooms.push_back(new Room(0, new char[80]{"a dimly lit room. The entrance behind has sealed shut."}, false));
  rooms.push_back(new Room(1, new char[80]{"another dark room. "}, false));
  rooms.push_back(new Room(2, new char[80]{"a dark room part of "}, false));
  rooms.push_back(new Room(3, new char[80]{"another dark room"}, true));
  rooms.push_back(new Room(4, new char[80]{"another dark room"}, false));
  rooms.push_back(new Room(5, new char[80]{"w5"}, false));
  rooms.push_back(new Room(6, new char[80]{"6some sort of heating room."}, false));
  rooms.push_back(new Room(7, new char[80]{"7another dark room."}, false));
  rooms.push_back(new Room(8, new char[80]{"8another dark room."}, false));
  rooms.push_back(new Room(9, new char[80]{"9another da"}, false));
  rooms.push_back(new Room(10, new char[80]{"10another dark room."}, false));
  rooms.push_back(new Room(11, new char[80]{"11another dark room."}, false));
  rooms.push_back(new Room(12, new char[80]{"12a storage ro"}, false));
  rooms.push_back(new Room(13, new char[80]{"13an unfamiliar exit"}, false));
  rooms.push_back(new Room(14, new char[80]{"14The third room"}, false));
  rooms.push_back(new Room(15, new char[80]{"15The first room"}, false));
  rooms.push_back(new Room(16, new char[80]{"The second room"}, false));
  rooms.push_back(new Room(17, new char[80]{"The third room"}, false));
  
  rooms[0]->setPath('N', 1);
  rooms[0]->setPath('E', 5);
  rooms[1]->setPath('S', 0);
  rooms[1]->setPath('N', 2);
  rooms[2]->setPath('S', 1);
  rooms[2]->setPath('N', 3);
  rooms[3]->setPath('S', 2);
  rooms[3]->setPath('E', 4);
  rooms[4]->setPath('W', 3);
  rooms[5]->setPath('W', 0);
  rooms[5]->setPath('E', 6);
  rooms[6]->setPath('W', 5);
  rooms[6]->setPath('S', 7);
  rooms[7]->setPath('N', 6);
  rooms[7]->setPath('S', 8);
  rooms[8]->setPath('N', 7);
  rooms[8]->setPath('E', 9);
  rooms[8]->setPath('W', 10);
  rooms[10]->setPath('E', 8);
  rooms[10]->setPath('S', 11);
  rooms[11]->setPath('N', 10);
  rooms[11]->setPath('W', 12);
  rooms[12]->setPath('E', 11);
  rooms[9]->setPath('W', 8);
  rooms[9]->setPath('E', 13);
  rooms[13]->setPath('W', 9);
  rooms[13]->setPath('N', 14);
  rooms[14]->setPath('S', 13);
  rooms[14]->setPath('N', 15);
  
  //item initializations
  char torchName[20] = {"Torch"};
  Item torch;
  strcpy(torch.name, torchName);
  char rockName[20] = {"Rock"};
  Item rock;
  strcpy(rock.name, rockName);
  char coalName[20] = {"Coal"};
  Item coal;
  strcpy(coal.name, coalName);
  char keyName[20] = {"Key"};
  Item key;
  strcpy(key.name, keyName);
  char waterName[20] = {"Water"};
  Item water;
  strcpy(water.name, waterName);

  
  Item test;
  rooms[0]->setItem(torch);
  rooms[1]->setItem(rock);
  rooms[1]->setItem(coal);
  rooms[1]->setItem(key);
  inventory.push_back(test);
  int currentRoom = 0;
  char input[20];
  
  bool playing = true;
  bool newroom = true;
  
  while (playing) {
    if (newroom) {
      std::cout << "\nYou are in ";
      rooms[currentRoom]->displayDesc();
      rooms[currentRoom]->displayItems();
      rooms[currentRoom]->displayExits();
    }
    std::cout << "\nPlease enter a command ('help' for help):\n";
    std::cin >> input;
    newroom = false;
    
    //try to move
    if (strncmp(input, "go", 2) == 0) {
      char direction;
      std::cin >> direction;

      //check that there is an exit in the given direction, then move
      if (!rooms[currentRoom]->isExit(direction)) {
	std::cout << "No exit exists there.\n";
	continue;
      }
      //check if the next room is locked
      if (rooms[rooms[currentRoom]->getExit(direction)]->isLocked() && !held(inventory, keyName)) {
	std::cout << "The door is locked. A key is required to continue.\n";
	continue;
      }
      move(rooms, direction, currentRoom);
      newroom = true;
    }

    //try to pick up an item
    if (strncmp(input, "get", 3) == 0) {
      char itemName[20];
      std::cin >> itemName;
      //check if item is present and take
      if (rooms[currentRoom]->getItem(itemName)) {
	Item i;
	strcpy(i.name, itemName);
	inventory.push_back(i);
	std::cout << itemName << " was added to your inventory.\n";
      }
      else std::cout << "No such item was found.\n";
    }

    //try to drop an item from inventory into room
    if (strncmp(input, "drop", 4) == 0) {
      char itemName[20];
      std::cin >> itemName;
      //check if item is present and drop
      if (drop(rooms, inventory, itemName, currentRoom)) std::cout << itemName << " was dropped.\n";
      else std::cout << "No " << itemName << " was found.\n";
    }

    //print possible commands
    if (strncmp(input, "help", 4) == 0) {
      std::cout << "\nCommands:\n";
      std::cout << "go {direction} (N, E, S, W)\n";
      std::cout << "get {item name}\n";
      std::cout << "drop {item name}\n";
      std::cout << "quit\n";
    }
    
    
    if (strncmp(input, "quit", 4) == 0) {
      playing = false;
    }
  }

}
