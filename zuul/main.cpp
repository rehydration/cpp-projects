#include <iostream>
#include <vector>
#include "room.h"

struct Item {
  char description[100];
};

bool move(char direction, Room* room) {


}
  
int main() {
  Room* startRoom = new Room();
  Room* room1 = new Room();
  Room* room2 = new Room();

  startRoom->setPath('N', room1);

  startRoom->setItem("Torch");
  
  std::vector<char*> inventory;
  Room* currentRoom = startRoom;
  
  bool playing = true;
  while (playing) {
    char input[10];
    currentRoom->displayItems();
    currentRoom->displayExits();
    std::cin >> input;

    if (strncmp(input, "go", 2) == 0) {
    }

    if (strncmp(input, "get", 3) == 0) {
    }

    if (strncmp(input, "drop", 4) == 0) {
    }
    
    if (strncmp(input, "quit", 4) == 0) {
      playing = false;
      break;
    }
  }

}
