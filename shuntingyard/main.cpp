/*

 */

#include <iostream>
#include <cstring>
#include <cctype>
#include "btnode.h"


struct Node {
  char data;
  bool empty;
  Node* next = nullptr;
};

//stack functions

void push(Node*& head, char t) {
  
  Node* newh = new Node;
  newh->data = t;
  newh->empty = false;
  if (head != nullptr) newh->next = head;
  head = newh;

  //std::cout << head->data << " " << head->empty << " " << (head->next == nullptr) << "\n";

}

char pop(Node*& head) {
  //if (head->empty) std::cout << "No items remaining\n";
  
  Node* temp = head;
  char value = temp->data;
  head = head->next;
  //if (head == nullptr) head->empty = true;

  delete temp;
  return value;
}

Node* peek(Node*& head) {
  return head;
}


//queue functions

void enqueue(Node*& head, Node*& end, char t) {

  Node* newn = new Node;
  newn->data = t;
  newn->empty = false;
  
  if (head == nullptr) { //first node
    head = newn;
  }
  else end->next = newn;
  end = newn;
}

char dequeue(Node*& head) {
  Node* temp = head;
  char value = temp->data;
  head = head->next;

  delete temp;
  return value;
}


int main() {
  Node* stack_head = nullptr;
  Node* queue_head = nullptr;
  Node* queue_end = nullptr;
  //BTNode* tree_head;
  
  /*stack_head->empty = true;
  queue_head->empty = true;
  queue_end->empty = true;
  */
  //bool running = true;
  
  std::cout << "Enter an expression: (end with 'x')\n";
  while (true) {
    char token;
    std::cin >> token;

    if (token == 'x') break;

    if (std::isdigit(token)) { //push numbers to output queue
      enqueue(queue_head, queue_end, token);
      //std::cout << token << " " << queue_head->data << "\n";
    }
    else { //push operators to stack
      push(stack_head, token);
    }

  }
  //std::cout << pop(stack_head);
  //std::cout << stack_head->data << " " << stack_head->next->data;
  
  while (stack_head != nullptr) {
    std::cout << pop(stack_head) << "\n";
    //h = h->next;
  }
  
  //std::cout << queue_head->data << "\n";
  while (queue_head != nullptr) std::cout << dequeue(queue_head) << "\n";
  
  
  return 0;
}
