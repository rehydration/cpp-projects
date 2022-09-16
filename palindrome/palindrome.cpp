/*
Name: Nathan Zhou
Date: 9/16/22

A program that takes in up to 80 characters, removes all spaces and punctuation,
and determines whether the text is a palindrome.

*/


#include <iostream>
#include <cstring>
#include <ctype.h>


int main() {
  char str[81]; //original input
  std::cin.get(str, 80);
  std::cin.get();

  char newstr[81];
  int count = 0; //size of new string
  for (int i = 0; i < 80; ++i) { //clean the input, lowercase alphabet chars only
    if (isalpha(str[i])) {
      newstr[count] = tolower(str[i]);
      ++count;
    }
  }
  
  bool palindrome = true;
  int mid = count % 2 == 0 ? count/2 : (count-1)/2; //ignore middle element when odd number
  for (int i = 0; i < mid; ++i) { //check first & last, second & second-to-last, etc
    if (newstr[i] != newstr[count-i-1]) {
      palindrome = false;
      break;
    }
  }

  if (palindrome) std::cout << "Palindrome.\n";
  else std::cout << "Not a palindrome.\n";
  
  return 0;
}
