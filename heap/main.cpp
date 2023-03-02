/*
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
    
    if (tree[2*node] > tree[2*node+1]) { //left
      tree[node] = tree[2*node];
      node = 2*node;
      tree[node] = 0;
    }
    else { //right
      tree[node] = tree[2*node+1];
      node = 2*node+1;
      tree[node] = 0;
    }
  } while (tree[2*node] || tree[2*node+1]);
}

//remove all elements from heap
void remove_all(int* tree) {
  while (tree[1] != 0) {
    remove(tree);
  }
}

//output the heap
void display(const int* tree, int ind, int depth) {
  if (tree[2*ind+1]) { //right node
    display(tree, 2*ind+1, depth+1);
  }
  
  for (int i = 0; i < depth; ++i) std::cout << '\t';
  std::cout << tree[ind] << "\n";

  if (tree[2*ind]) { //left node
    display(tree, 2*ind, depth+1);
  }
  
}


int main() {
  int tree[102];
  char input[20];
  bool running = true;

  for (int i = 1; i <= 100; ++i) {
    tree[i] = 0;
  }

  int size = 1;
  int num;
  int n;
  std::cout << "Enter size\n";
  std::cin >> num;
  std::cout << "Enter nodes\n";

  std::cout << "Choose input method ('1' for manual entry; '2' for file)\n";
  
  char file_name[20] = "nums2";
  
  std::ifstream ifs;
  ifs.open(std::strcat(file_name, ".txt"));
  for (int i = 1; i <= num; ++i) {
    //std::cin >> n;
    ifs >> n;
    insert(tree, n, size);
    ++size;
  }
  ifs.close();

  for (int i = 1; i <= 100; ++i) std::cout << tree[i] << " ";

  
  display(tree, 1, 0);
  //remove(tree);
  //display(tree, h, 1);

  std::cout << "\n";
  remove_all(tree);
  
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
