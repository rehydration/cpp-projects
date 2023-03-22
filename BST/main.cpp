

#include <iostream>
#include <fstream>
#include <cstring>

struct BTNode {
  BTNode* left;
  BTNode* right;
  BTNode* parent;
  int value;
};

void insert(BTNode*& root, BTNode* n) {
  BTNode* prev = nullptr;
  BTNode* curr = root;
  while (curr != nullptr) {
    prev = curr;
    if (n->value > curr->value)
      curr = curr->right;
    else curr = curr->left;
  }
  n->parent = prev;
  if (prev == nullptr) root = n;
  else if (n->value > prev->value) prev->right = n;
  else prev->left = n;
}

void remove(BTNode*& root) {

  //if (!n->left && !n->right) { //leaf node
    
  //}
 
}

bool search(BTNode*& root, int value) {
  BTNode* current = root;
  while (current != nullptr && current->value != value) {
    if (current->value > value) current = current->left;
    else current = current->right;
  }
  return current->value == value;
}

void display(BTNode* current, int depth) {
  if (current->right != nullptr) display(current->right, depth+1);
  else {
    for (int i = 0; i <= depth; ++i) std::cout << '\t';
    std::cout << 'X' << "\n";
  }
  
  for (int i = 0; i < depth; ++i) std::cout << '\t';
  std::cout << current->value << "\n";

  if (current->left != nullptr) display(current->left, depth+1);
  else {
    for (int i = 0; i <= depth; ++i) std::cout << '\t';
    std::cout << 'X' << "\n";
  }
}

int main() {
  BTNode* root = nullptr;

  char input[10];
  int num;
  int n;

  std::cout << "Choose input method ('1' for manual entry; '2' for file):\n";
  std::cin >> input;
  std::cout << "Enter the input size (1 - 100):\n";
  std::cin >> num;
  
  if (input[0] == '1') { //take from input stream
    std::cout << "Enter the series of numbers:\n";
    for (int i = 1; i <= num; ++i) {
      std::cin >> n;
      BTNode* newn = new BTNode();
      newn->value = n;
      insert(root, newn);
    }
  }

  if (input[0] == '2') { //take from file
    std::cout << "Enter the file name:\n";
    std::cin >> input;
    
    std::ifstream ifs;
    ifs.open(std::strcat(input, ".txt"));
    for (int i = 1; i <= num; ++i) {
      ifs >> n;
      BTNode* newn = new BTNode();
      newn->value = n;
      insert(root, newn);
    }
    ifs.close();
  }

  bool running = true;
  while (running) {
    std::cout << "Enter a command (add, remove, search, print, quit):\n";
    std::cin >> input;

    if (strncmp(input, "add", 3) == 0) {

    }
    if (strncmp(input, "remove", 6) == 0) {
      //remove(tree);
    }
    if (strncmp(input, "search", 6) == 0) {
      std::cout << "Enter the number you are looking for:\n";
      std::cin >> n;
      std::cout << search(root, n) << "\n";
    }
    if (strncmp(input, "print", 6) == 0) {
      display(root, 0);
    }
    if (strncmp(input, "quit", 4) == 0) {
      running = false;
    }
  }
  
  return 0;


}
