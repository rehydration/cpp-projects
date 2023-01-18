#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "student.h"

using namespace std;

class Node {
public:
  	Node(Student*);
  	~Node(); 
  
  	void setStudent(Student*);
  	void setNext(Node*);
  
  	Student* getStudent();
  	Node* getNext();
private: 
  	Student* student;
  	Node* next;
};
#endif
