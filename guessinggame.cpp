/*
Name: Nathan Zhou
Date: 9/14/22

Plays a guessing game where the user must guess the randomly generated number between 1 and 100, inclusive. 
Tells user the number of guesses and allows them to play again after winning.


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
      //finish if equal, otherwise, indicate whether the guess was larger/smaller 
    }

    std::cout << "Correct! You used " << guesses_taken << " guesses.\nPlay again? (y/n)\n";
    char response; //user must answer 'y' to play again
    std::cin >> response;
    if (response != 'y') playing = false;
  }
  return 0;
}
