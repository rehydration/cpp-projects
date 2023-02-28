#include <iostream>
#include <fstream>
#include <random>

using namespace std;

int main() {
  ofstream myfile;
  myfile.open("nums.txt");
  for (int i = 0; i < 100; ++i) {
    myfile << (rand() % 100)+1 << " ";
  }
  myfile.close();
  return 0;
}
