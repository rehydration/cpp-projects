#include "student.h"
#include "node.h"

int main() {
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
  
  return 0;
}
