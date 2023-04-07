/* 
Nathan Zhou
4/7/23

Binary search tree implementation with parent nodes, based on Wikipedia
*/

#include <iostream>
#include <fstream>
#include <cstring>

struct BTNode {
  BTNode* left;
  BTNode* right;
  BTNode* parent;
  int value;
};

//insert a new node into tree
void insert(BTNode*& root, BTNode* n) {
  BTNode* prev = nullptr;
  BTNode* curr = root;
  while (curr != nullptr) {
    prev = curr;
    if (n->value > curr->value)
      curr = curr->right; //larger values on right, smaller on left
    else curr = curr->left;
  }
  n->parent = prev;
  if (prev == nullptr) root = n; //first node, set root
  else if (n->value > prev->value) prev->right = n;
  else prev->left = n;
}

//find an element in tree
BTNode* search(BTNode*& root, int value) {
  BTNode* current = root;
  while (current != nullptr && current->value != value) {
    if (current->value > value) current = current->left;
    else current = current->right;
  }
  return current;
}

//replace node and set position of new node
void shift(BTNode*& root, BTNode* del, BTNode* rep) {
  if (rep != nullptr) rep->parent = del->parent;
  
  if (del->parent == nullptr) { //deleting root
    root = rep;
    return;
  }
  
  if (del == (del->parent->left)) del->parent->left = rep; //deleted node is left
  if (del == del->parent->right) del->parent->right = rep; //deleted node is right
}

//remove a specific node
void remove(BTNode*& root, BTNode* node) {

  if (node->left == nullptr) { //right child exists or leaf node
    shift(root, node, node->right);
  }
  else if (node->right == nullptr) { //left child only
    shift(root, node, node->left);
  }

  else { //node has two children
    BTNode* successor = node->right; //find smallest node greater than node to be deleted
    while (successor->left != nullptr) successor = successor->left;
    if (successor->parent != node) { //successor is not immediate right child
      shift(root, successor, successor->right);
      successor->right = node->right;
      successor->right->parent = successor;
    }
    //immediate right child
    shift(root, node, successor);
    successor->left = node->left;
    successor->left->parent = successor;
  }
  delete node;
}

//print out the tree
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
      std::cout << "Enter the number to be added:\n";
      std::cin >> n;
      BTNode* newn = new BTNode();
      newn->value = n;
      insert(root, newn);
      std::cout << n << " added to tree\n";
    }
    if (strncmp(input, "remove", 6) == 0) {
      std::cout << "Enter the number to be removed:\n";
      std::cin >> n;
      remove(root, search(root, n));
      std::cout << n << " removed from tree\n";
    }
    if (strncmp(input, "search", 6) == 0) {
      std::cout << "Enter the number you are looking for:\n";
      std::cin >> n;
      if (!search(root, n)) std::cout << n << " is not in the tree\n";
      else std::cout << n << " is in the tree\n";
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
