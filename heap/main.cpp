#include <iostream>
#include <fstream>
#include <cstring>

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

  while (true) {
    
    if (tree[2*node] > tree[2*node+1]) {
      tree[node] = tree[2*node];
      node = 2*node;
      tree[node] = 0;
    }
    else {
      tree[node] = tree[2*node+1];
      node = 2*node+1;
      tree[node] = 0;
    }

    if (!tree[2*node] && !tree[2*node+1]) return;
  }
}

void remove_all(int* tree) {
  while (tree[1] != 0) {
    remove(tree);
  }
}

//output the heap
void display(const int* tree, int* layer, int l) {
  std::cout << l << ": ";
  int* newlayer = new int[101];
  int cnt = 0;
  for (int i = 0; i <= 100; ++i) newlayer[i] = 0;

  bool valid = false; //next layer has nonzero
  for (int i = 0; i < 100; ++i) {
    if ((layer[i] || tree[layer[i]])) { //index and value both valid
      std::cout << tree[layer[i]] << "\t";


      newlayer[cnt] = 2*layer[i];
      ++cnt;
      if (tree[2*layer[i]] > 0) { //child 1
	
	valid = true;
      }

      
      newlayer[cnt] = 2*layer[i]+1;
      ++cnt;
      if (tree[2*layer[i]+1] > 0) { //child 2
	valid = true;
      }
    }
      
    else break;
  }
  std::cout << "\n";
  layer = newlayer;
  if (valid) display(tree, layer, ++l);
}


int main() {
  int tree[101];
  bool vis[101];
  char input[20];
  bool running = true;

  for (int i = 1; i <= 100; ++i) {
    tree[i] = 0;
    vis[i] = false;
  }

  int size = 1;
  int num;
  int n;
  std::cout << "Enter size\n";
  std::cin >> num;
  std::cout << "Enter nodes\n";

  
  std::ifstream ifs;
  ifs.open("nums.txt");
  for (int i = 1; i <= num; ++i) {
    //std::cin >> n;
    ifs >> n;
    insert(tree, n, size);
    ++size;
  }
  ifs.close();

  int* h = new int[101];
  for (int i = 0; i < 100; ++i) h[i] = 0;
  h[0] = 1;
  display(tree, h, 1);
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
