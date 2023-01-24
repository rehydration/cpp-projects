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
    head = newn; //new first
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
    newn->setNext(current->getNext());
    current->setNext(newn);
    return;
  }
  addStudent(head, current->getNext(), newn);
}

//print all students in the list
void print(Node* current) {
  current->getStudent()->display();
  if (current->getNext() != NULL) {
    print(current->getNext());
  }
}

//delete a student given their student id
void deleteStudent(Node*& head, Node* current, int id) {
  //first node should be deleted
  if (current->getStudent()->getID() == id) {
    head = head->getNext();
    delete current;
  }
  else if (current->getNext() != NULL) {
    //next node should be deleted
    if (current->getNext()->getStudent()->getID() == id) {
      Node* next = current->getNext();
      current->setNext(next->getNext());
      delete next;
    }
    //continue in list
    else {
      deleteStudent(head, current->getNext(), id);
    }
  }
}

//calculates the average GPA of all students in the list
float average(Node* current, float sum, int count) {
  sum += current->getStudent()->getGPA();
  ++count;
  if (current->getNext() != NULL) {
    sum = average(current->getNext(), sum, count);
  }
  else { //end of list, divide total sum of GPAs by number of students
    sum /= count;
  }
  return sum;
}


int main() {
  char input[10];
  bool running = true;
  Node* head = NULL;
  
  while (running) {
    std::cout << "Enter a command: (ADD, DELETE, PRINT, AVERAGE, QUIT)\n";
    std::cin >> input;

    if (strncmp(input, "QUIT", 4) == 0) {
      //delete all remaining nodes
      Node* current = head;
      Node* prev;
      while (current->getNext() != NULL) {
	prev = current;
	current = current->getNext();
	delete prev;
      }
      running = false;
    }
    
    if (strncmp(input, "ADD", 3) == 0) {
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
    }

    if (strncmp(input, "AVERAGE", 7) == 0) {
      std::cout << "The average GPA is " << std::fixed << std::setprecision(2) << average(head, 0, 0) << "\n";
    }

  }
  
  return 0;
}
