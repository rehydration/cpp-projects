/*
Name: Nathan Zhou
Project: Guessing Game
Date: 9/14/22


1. No global variables
2. No strings
3. Use iostream instead of stdio

*/

#include <iostream>
#include <cstdlib>


int main() {
  srand(time(NULL));
  int random_num, guesses_taken, guess;
  bool playing = true;
  while (playing) { //begin a game
    random_num = (rand() % 100) + 1; //generate the number: modulo to define range 1-100 (cplusplus.com)
    guesses_taken = 0;
    while (guess != random_num) {
      std::cout << "Enter a guess from 1 to 100:\n";
      std::cin >> guess; //user's guess
      ++guesses_taken;
      if (guess > random_num) std::cout << "Too large.\n";
      if (guess < random_num) std::cout << "Too small.\n";
      //finish if equal 
    }
    std::cout << "Correct! You used " << guesses_taken << " guesses.\nPlay again? (y/n)\n";
    char ans;
    std::cin >> ans;
    if (ans != 'y') playing = false;
  }
  return 0;
}
