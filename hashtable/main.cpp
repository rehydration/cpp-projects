/*

 */

#include "student.h"
#include "node.h"
#include <fstream>
#include <random>

//add a student
void addStudent(Node** hashTable, Node* newn, int size, int h) {
  //hash
  if (hashTable[h] == NULL) {
    hashTable[h] = newn;
  }
  else {
    Node* current = hashTable[h];
    while (current->getNext() != NULL) {
      current = current->getNext();
    }
    current->setNext(newn);
  }
}

//print all students in the list
void print(Node** hashTable, int size) {
  int count = 0;

  
  for (int i = 0; i < size; ++i) {
    if (hashTable[i] != NULL) {
      std::cout << i << "\n";

      
      Node* current = hashTable[i];
      
      while (current->getNext() != NULL) {
	current->getStudent()->display();
	current = current->getNext();
	++count;
      }

      if (current->getNext() == NULL) {
	current->getStudent()->display();
	++count;
      }
    }
  }
  std::cout << count << "\n";
}

//delete a student given their student id
void deleteStudent() {
  
}

//hash string of first name into a number up to size
int hash(char* name, int size) {
  unsigned int h = 0;
  unsigned int factor = 53;
  unsigned int factorpow = 1;
  unsigned int mod = 1e9 + 9;

  int len = (sizeof(name))/(sizeof(name[0]));
			     
  
  for (int i = 0; i < len; ++i) {
    h = (h + (name[i] - 'a' + 1)*factorpow) % mod;
    factorpow = (factorpow*factor) % mod;
  }
  std::cout << h % size << "\n";
  return h % size;
}



//randomly generate the given number of students
int generate(Node** hashTable, int num, int id) {
  for (int i = 0; i < num; ++i) {
    char fname[20], lname[20];

    //generate random line numbers
    int fnameLine = (rand() % 10000);
    int lnameLine = (rand() % 48000);

    std::ifstream ifs;

    //get first name
    ifs.open("fnames.txt");
    for (int j = 0; j < fnameLine-1; ++j) { //continue until reaching fnameLine
      ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    ifs >> fname;
    ifs.close();

    //get last name
    ifs.open("lnames.txt");
    for (int j = 0; j < lnameLine-1; ++j) {
      ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    ifs >> lname;
    ifs.close();
    //int gpa = std::uniform_real_distribution<> dis(0, 4);

    std::cout << fname << " " << lname << "\n";
    int index = hash(fname, 200);


    Student* news = new Student(fname, lname, id++, 4);
    Node* newn = new Node(news);

    addStudent(hashTable, newn, 200, index);

  }
  
  for (int i = 0; i < 200; ++i) {
    std::cout << (hashTable[i] != NULL) << " ";
    if (i % 20 == 0 && i) std::cout << "\n";
  }
  std::cout << "\n";

  return id;
}


  



int main() {
  srand(time(NULL));
  
  char input[10];
  Node* head = NULL;

  Node* hashTable[200];
  for (int i = 0; i < 200; ++i)
    hashTable[i] = NULL;
  
  int id = 1;

  
  while (true) {
    std::cout << "Enter a command: (ADD, DELETE, PRINT, GEN, QUIT)\n";
    std::cin >> input;

    if (strncmp(input, "QUIT", 4) == 0) {
      //delete all remaining nodes if list isn't empty
      if (head != NULL) {
	Node* current = head;
	Node* prev;
	while (current->getNext() != NULL) {
	  prev = current;
	  current = current->getNext();
	  delete prev;
	}
	delete current;
      }
      
      break;
    }

    if (strncmp(input, "GEN", 3) == 0) {
      int num;
      std::cout << "Enter the number of students to be generated:\n";
      std::cin >> num;
      id = generate(hashTable, num, id);

      for (int i = 0; i < 200; ++i) {
	if (hashTable[i] != NULL) {
	  std::cout << i << " ";hashTable[i]->getStudent()->display();
	}
      }
    }
    /*if (strncmp(input, "ADD", 3) == 0) {
      //get student info
      char fname[10], lname[10];
      int id;
      float gpa;
      std::cout << "Enter the student's first name:\n";
      std::cin >> fname;
      std::cout << "Enter the student's last name:\n";
      std::cin >> lname;
      std::cout << "Enter the student's id number:\n";
      std::cin >> id;
      std::cout << "Enter the student's GPA:\n";
      std::cin >> gpa;

      //initialize student and node
      Student* news = new Student(fname, lname, id, gpa);
      Node* newn = new Node(news);
      
      //first node to be added
      if (head == NULL) head = newn;
      //add normally
      else addStudent(head, head, newn);
      std::cout << "Student " << id << " has been added to the list.\n";
    }
    else if (head == NULL) {
      std::cout << "No students could be found.\n";
      continue;
    }

    if (strncmp(input, "PRINT", 5) == 0) {
      print(head);
    }

    if (strncmp(input, "DELETE", 6) == 0) {
      int id;
      std::cout << "Enter the id of the student to be deleted:\n";
      std::cin >> id;
      deleteStudent(head, head, id);
      std::cout << "Student " << id << " has been removed from the list.\n";
      }*/

    if (strncmp(input, "PRINT", 5) == 0) {
      print(hashTable, 200);
    }
  }
  
  return 0;
}
