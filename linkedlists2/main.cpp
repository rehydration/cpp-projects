/*
Name:
Date:

Linked list

 */

#include "student.h"
#include "node.h"


//add a student based on student id in ascending order
void addStudent(Node*& head, Node* current, Node* newn) {
  //new student's id is smaller than current smallest
  if (current->getStudent()->getID() > newn->getStudent()->getID()) {
    newn->setNext(current);
    head = NULL;
    head = newn;
    return;
  }
  //reached end of list, new student id is largest
  if (current->getNext() == NULL) {
    current->setNext(newn);
    return;
  }
  //correct nodes to be between
  if (current->getStudent()->getID() < newn->getStudent()->getID() &&
      current->getNext()->getStudent()->getID() >= newn->getStudent()->getID()) {
    //Node* temp = current->getNext;
    newn->setNext(current->getNext());
    current->setNext(newn);
    return;
  }
  addStudent(head, current->getNext(), newn);
}

//print all students in the list
void print(Node* current) {
  //std::cout << current->getStudent->display() << "\n";
  current->getStudent()->display();
  if (current->getNext() != NULL) {
    print(current->getNext());
  }
}

//delete a student given their student id
void deleteStudent(Node* current, int id) {
  //is node to be deleted
  if (current->getStudent()->getID() == id) {
    Node* place;
  }
  else {
    if (current->getNext() != NULL) deleteStudent(current->getNext(), id);
  }
}

//calculates the average GPA of all students in the list
float average(Node* current, float sum, int count) {
  //sum += current->getStudent()->getGPA();
  ++count;
  if (current->getNext() != NULL) {
    average(current->getNext(), sum, count);
  }
  else {
    sum /= count;
    return sum;
  }
}


int main() {
  char input[10];
  bool running = true;
  Node* head = NULL;
  
  while (running) {
    std::cin >> input;
    
    if (strncmp(input, "ADD", 3) == 0) {
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
      Student* news = new Student(fname, lname, id, gpa);
      Node* newn = new Node(news);
      
      if (head == NULL) head = newn;
      else addStudent(head, head, newn);
    }

    if (strncmp(input, "PRINT", 5) == 0) {
      if (head == NULL) std::cout << "There are no students.\n";
      else print(head);
    }

    if (strncmp(input, "DELETE", 6) == 0) {
      int id;
      std::cout << "Enter the id of the student to be deleted:\n";
      std::cin >> id;
      deleteStudent(head, id);
    }

    if (strncmp(input, "AVERAGE", 7) == 0) {
      if (head == NULL) std::cout << "There are no students.\n";
      else average(head, 0, 0);
    }

    if (strncmp(input, "QUIT", 4) == 0) {
      running = false;
    }
  }

  /*
  char name1[20] = "Bob";
  char name2[20] = "John";
  char name3[20] = "Johnson";
  char name4[20] = "Smith";
  Student* a = new Student(name1, name3, 12, 3.95);
  Student* b = new Student(name1, name4, 19, 2.60);
  Student* c = new Student(name2, name3, 29, 3.33);
  
  
  Node* first = new Node(a);
  Node* second = new Node(b);
  Node* third = new Node(c);

  first->setNext(second);
  second->setNext(third);

  Node* current = first;
  while(current != NULL) {
    current->getStudent()->display();
    current = current->getNext();
  }
  delete first;
  delete second;
  delete third;
  delete a;
  delete b;
  delete c;
  */
  
  return 0;
}
