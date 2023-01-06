#include "node.h"

Node::Node() {
}

Node::Node(Student* newstudent) {
  student = newstudent;
}

Node* Node::getNext() {
  return next;
}

Student* Node::getStudent() {
  return student;
}

void Node::setNext(Node* newnext) {
  next = newnext;
}

Node::~Node() {
  next = NULL;
}
