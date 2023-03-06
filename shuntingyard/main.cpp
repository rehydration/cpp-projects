/*

 */

#include <iostream>
#include <cstring>
#include <cctype>


struct Node {
  char data = '\t';
  Node* next = NULL;
};

//stack functions

void push(Node*& head, char t) {
  if (head->data != '\t') {
    Node* newh = new Node;
    newh->data = t;
    newh->next = head;
    head = newh;
    //std::cout << t << "\n";
  }
  else {
    Node* h;
    h->data = t;
    head = h;
    std::cout << t << "\n";
  }
}

char pop(Node*& head) {
  Node* temp = head;
  char value = temp->data;
  head = head->next;
  delete temp;
  return value;
}

Node* peek(Node*& head) {
  return head;
}


//queue functions

void enqueue(Node*& queue_head, Node*& queue_end, char t) {
  if (queue_end->data != ' ') {
    Node* newn = new Node;
    newn->data = t;
    queue_end->next = newn;
    queue_end = newn;
  }
  else {
    Node* newn;
    newn->data = t;
    queue_end = newn;
    queue_head = newn;
  }
}

char dequeue(Node* queue_head) {
  Node* temp = queue_head;
  char value = temp->data;
  queue_head = queue_head->next;
  delete temp;
  return value;
}


int main() {
  Node* stack_head;
  Node* queue_head;
  Node* queue_end;

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
  //std::cout << stack_head
  Node* h = stack_head;
  while (h->next != NULL) {
    std::cout << h->data << "\n";
    h = h->next;
  }

  while (queue_head->next != NULL) dequeue(queue_head);

  
  return 0;
}
