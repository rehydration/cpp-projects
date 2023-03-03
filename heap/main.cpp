/*

Nathan Zhou
3/3/23

Max heap that can use manual or file input

 */


#include <iostream>
#include <fstream>
#include <cstring>


//insert node at given index
void insert(int* tree, int node, int index) {
  tree[index] = node;
  while (index/2 && tree[index/2] < node) { //swap parent and node
    tree[index] = tree[index/2];
    tree[index/2] = node;
    index /= 2;
  }
}


//remove largest
void remove(int* tree) {
  int node = 1;
  std::cout << tree[node] << "\n";

  do { //sift up elements
    if (tree[2*node] > tree[2*node+1] && 2*node <= 100) { //left
      tree[node] = tree[2*node];
      node = 2*node;
      tree[node] = 0;
    }
    else if (2*node+1 <= 100) { //right
      tree[node] = tree[2*node+1];
      node = 2*node+1;
      tree[node] = 0;
    }
  } while ((tree[2*node] || tree[2*node+1]) && 2*node <= 100); //check bounds
}

//remove all elements from heap
void remove_all(int* tree) {
  while (tree[1]) { //first element exists
    remove(tree);
  }
}

//output the heap sideways
void display(const int* tree, int ind, int depth) {
  if (2*ind+1 <= 100 && tree[2*ind+1]) { //right node
    display(tree, 2*ind+1, depth+1);
  }

  //current node
  for (int i = 0; i < depth; ++i) std::cout << '\t';
  std::cout << tree[ind] << "\n";

  if (2*ind <= 100 && tree[2*ind]) { //left node
    display(tree, 2*ind, depth+1);
  }
  
}


int main() {
  int tree[102];
  char input[20];
  bool running = true;

  int num; //input size
  int n; //placeholder


  for (int i = 1; i <= 100; ++i) {
    tree[i] = 0;
  }

  //initialize tree
  std::cout << "Choose input method ('1' for manual entry; '2' for file):\n";
  std::cin >> input;
  std::cout << "Enter the input size (1 - 100):\n";
  std::cin >> num;
  
  if (input[0] == '1') { //take from input stream
    std::cout << "Enter the series of numbers:\n";
    for (int i = 1; i <= num; ++i) {
      std::cin >> n;
      insert(tree, n, i);
    }
  }

  if (input[0] == '2') { //take from file
    std::cout << "Enter the file name:\n";
    std::cin >> input;
    
    std::ifstream ifs;
    ifs.open(std::strcat(input, ".txt"));
    for (int i = 1; i <= num; ++i) {
      ifs >> n;
      insert(tree, n, i);
    }
    ifs.close();
  }

  while (running) {
    std::cout << "Enter a command (remove, remove-all, print, quit):\n";
    std::cin >> input;

    if (strncmp(input, "remove", 6) == 0) {
      remove(tree);
    }
    if (strncmp(input, "remove-all", 10) == 0) {
      remove_all(tree);
      running = false;
    }
    if (strncmp(input, "print", 6) == 0) {
      display(tree, 1, 0);
    }
    if (strncmp(input, "quit", 4) == 0) {
      running = false;
    }
  }
  
  return 0;
}
