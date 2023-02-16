/*

 */

#include "student.h"
#include "node.h"
#include <fstream>
#include <random>

//add a student to the given slot h
void addStudent(Node** hashTable, Node* newn, int size, int h, bool& atLimit) {
  //slot is empty
  if (hashTable[h] == NULL) {
    hashTable[h] = newn;
  }
  //collision, add to end of linked list
  else {
    int count = 0; //check if there are more than 3 collisions
    Node* current = hashTable[h];
    while (current->getNext() != NULL) {
      ++count;
      current = current->getNext();
    }
    current->setNext(newn);

    if (count > 2) atLimit = true;
  }
}

//print all students in the list
void print(Node** hashTable, int size) {
  for (int i = 0; i < size; ++i) {
    if (hashTable[i] != NULL) { //slot is not empty
      std::cout << i << "\n";

      
      Node* current = hashTable[i];
      
      while (current->getNext() != NULL) {
	current->getStudent()->display();
	current = current->getNext();
      }

      //last node
      if (current->getNext() == NULL) {
	current->getStudent()->display();
      }
    }
  }
}

//delete a student given their student id
void deleteStudent(Node** hashTable, int id, int size) {
  for (int i = 0; i < size; ++i) {
    Node* current = hashTable[i];
    Node* prev = NULL;
    while (current != NULL) { //check chain in current array slot
      if (current->getStudent()->getID() == id) { //match
	if (prev != NULL) prev->setNext(current->getNext());
	else hashTable[i] = current->getNext(); //new first node in slot
	delete current;
	return;
      }
      else {
	prev = current;
	current = current->getNext();
      }
    }	

  }
}

//hash string of first name into a number up to size
int hash(char* name, int size) {
  unsigned int h = 0;
  unsigned int factor = 53;
  unsigned int factorpow = 1;
  unsigned int mod = 1e9 + 9;

  //string length
  int len = (sizeof(name))/(sizeof(name[0]));
			     
  
  for (int i = 0; i < len; ++i) {
    h = (h + (name[i] - 'a' + 1)*factorpow) % mod; //polynomial hash
    factorpow = (factorpow*factor) % mod;
  }

  //adjust to array size
  std::cout << h % size << "\n";
  return h % size;
}



//randomly generate the given number of students
void generate(Node** hashTable, int num, int id, int size, bool& atLimit) {
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

    //generate random gpa from 1 to 4
    std::random_device rd;
    std::default_random_engine gen(rd());
    std::uniform_real_distribution<> distribution(1.0, 4.0);
    double gpa = distribution(gen);

    //hash
    int index = hash(fname, size);

    Student* news = new Student(fname, lname, id++, gpa);
    Node* newn = new Node(news);

    addStudent(hashTable, newn, size, index, atLimit);

  }
}


  



int main() {
  srand(time(NULL));
  
  char input[10];
  int id = 1;
  int size = 200;
  bool atLimit = false;

  Node** hashTable = new Node*[size];
  for (int i = 0; i < size; ++i)
    hashTable[i] = NULL;
  

  
  
  while (true) {
    //need to increase array size to double
    if (atLimit) {      
      for (int i = 0; i < size; ++i) {
	Node* current = hashTable[i];

      }

      size *= 2;
     


      delete [] hashTable;
      hashTable = new Node*[size];
      for (int i = 0; i < size; ++i) hashTable[i] = NULL;
      atLimit = false;
    }

    
    std::cout << "Enter a command: (ADD, DELETE, PRINT, GEN, QUIT)\n";
    std::cin >> input;

    if (strncmp(input, "QUIT", 4) == 0) {
      //delete all remaining nodes if list isn't empty
      
      break;
    }

    if (strncmp(input, "GEN", 3) == 0) {
      int num;
      std::cout << "Enter the number of students to be generated:\n";
      std::cin >> num;
      generate(hashTable, num, id, size, atLimit);
      id += num;
      
      for (int i = 0; i < size; ++i) {
	if (hashTable[i] != NULL) {
	  std::cout << i << " ";hashTable[i]->getStudent()->display();
	}
      }
    }
    if (strncmp(input, "ADD", 3) == 0) {
      //get student info
      char fname[20], lname[20];
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
      int index = hash(fname, size);

      addStudent(hashTable, newn, size, index, atLimit);
    }

    if (strncmp(input, "DELETE", 6) == 0) {
      int id;
      std::cout << "Enter the id of the student to be deleted:\n";
      std::cin >> id;
      deleteStudent(hashTable, id, size);
      std::cout << "Student " << id << " has been removed from the list.\n";
    }

    if (strncmp(input, "PRINT", 5) == 0) {
      print(hashTable, size);
    }
  }
  
  return 0;
}
