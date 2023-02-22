#include <iostream>
#include <fstream>
#include <cstring>

void insert(int* tree, int node, int size) {
  tree[size] = node;
  int index = size;
  while (tree[index/2] < node) { //swap parent and node
    tree[index] = tree[index/2];
    tree[index/2] = node;
    index /= 2;
  }
}

//output the heap
void display(const int* tree) {
  for (int i = 0; i < 100; ++i) {
    std::cout << tree[i] << " ";
  }
  std::cout << "\n";
}


int main() {
  int tree[101];
  char input[20];
  bool running = true;

  for (int i = 0; i < 100; ++i) tree[i] = 0;

  int size = 0;
  int num;
  int n;
  std::cout << "Enter size\n";
  std::cin >> num;
  std::cout << "Enter nodes\n";
  for (int i = 0; i < num; ++i) {
    std::cin >> n;
    insert(tree, n, size);
    std::cout << n << " " << size << "\n";
    ++size;
  }
  display(tree);
  
  
  /*while (running) {
    std::cout << "Enter a command:\n";
    std::cin >> input;
    
    if (strncmp(input, "insert", 6) == 0) {
      int n;
      while (std::cin >> n) { //take in all input
	std::cout << n << "\n";
      }
      std::cin.clear(); //clear
    }

    if (strncmp(input, "delete-max", 10) == 0) {
      std::cout << "t\n";
    }

    if (strncmp(input, "quit", 4) == 0) {
      running = false;
    }
    }*/
  

  return 0;
}
