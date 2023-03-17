/*

Nathan Zhou
3/17/23

Shunting yard program to convert between prefix, postfix, and infix

 */

#include <iostream>
#include <cstring>
#include <cctype>
#include "btn.h"


//node for linked list stack/queue
struct Node {
  char data;
  BTNode* tree;
  Node* next = nullptr;
};

//stack functions

//add new node to front
void push(Node*& head, Node*& newh) {
  if (head != nullptr) newh->next = head;
  head = newh;
}

//delete top node and return value
char pop(Node*& head) {
  Node* temp = head;
  char value = temp->data;
  head = head->next; //set new head
  delete temp;
  return value;
}

//delete top node and return binary tree node
BTNode* pop_node(Node*& head) {
  Node* temp = head;
  BTNode* tree = new BTNode;
  tree = head->tree;
  head = head->next;
  delete temp;
  return tree;
}

//return top node's value if it exists
char peek(Node*& head){
  char c = (head == nullptr ? ' ' : head->data);
  return c;
}


//queue functions

//add new node to back of queue
void enqueue(Node*& head, Node*& end, char t) {

  Node* newn = new Node;
  newn->data = t;
  
  if (head == nullptr) { //first node to be added
    head = newn;
  }
  else end->next = newn;
  end = newn;
}

//delete top node and return value
char dequeue(Node*& head) {
  Node* temp = head;
  char value = temp->data;
  head = head->next;

  delete temp;
  return value;
}


//binary expression tree transversal

//in order transversal
void infix(BTNode* node) {
  if (node->is_oper()) { //parens around every expression
    std::cout << "( ";
  }

  if (!node->is_empty()) infix(node->get_left()); //further nodes exist
  std::cout << node->get_value() << " ";
  if (!node->is_empty()) infix(node->get_right());
  if (node->is_oper()) {
    std::cout << ") ";
  }
}

//post order transversal
void postfix(BTNode* node) {
  if (!node->is_empty()) {
    postfix(node->get_left());
    postfix(node->get_right());
  }
  std::cout << node->get_value() << " ";
}

//pre order transversal
void prefix(BTNode* node) {
  std::cout << node->get_value() << " ";
  if (!node->is_empty()) {
    prefix(node->get_left());
    prefix(node->get_right());
  }
}


int main() {
  Node* stack_head = nullptr;
  Node* queue_head = nullptr;
  Node* queue_end = nullptr;

  char token;
  std::cout << "Enter an expression: (end with '.')\n";
  while (true) {
    std::cin >> token;

    if (token == '.') break;

    if (std::isdigit(token)) { //push numbers to output queue
      enqueue(queue_head, queue_end, token);
    }
    else { //push parenthesis and operators to stack
      
      switch (token) {
      case '(': //add
	{
	  Node* newn = new Node;
	  newn->data = token;
	  push(stack_head, newn);
	  break;
	}
      case ')':
	{
	  char c;
	  while (stack_head != nullptr) { //pop stack until right paren
	    c = pop(stack_head);
	    if (c == '(') break;
	    enqueue(queue_head, queue_end, c);
	  }
	  break;
	}
      case '+':
	{
	  while (peek(stack_head) == '-' || peek(stack_head) == '*'
		 || peek(stack_head) == '/' || peek(stack_head) == '^') { //pop higher power operators to queue
	    enqueue(queue_head, queue_end, pop(stack_head));
	  }
	  //add
	  Node* newn = new Node;
	  newn->data = token;
	  push(stack_head, newn);
	  break;
	}
      case '-':
	{
	  while (peek(stack_head) == '+' || peek(stack_head) == '*'
		 || peek(stack_head) == '/' || peek(stack_head) == '^') {
	    enqueue(queue_head, queue_end, pop(stack_head));
	  }
	  Node* newn = new Node;
	  newn->data = token;
	  push(stack_head, newn);
	  break;
	}
      case '*':
	{
	  while (peek(stack_head) == '/' || peek(stack_head) == '^') {
	    enqueue(queue_head, queue_end, pop(stack_head));
	  }
	  Node* newn = new Node;
	  newn->data = token;
	  push(stack_head, newn);
	  break;
	}
      case '/':
	{
	  while (peek(stack_head) == '*' || peek(stack_head) == '^') {
	    enqueue(queue_head, queue_end, pop(stack_head));
	  }
	  Node* newn = new Node;
	  newn->data = token;
	  push(stack_head, newn);
	  break;
	}
      case '^':
	{
	  Node* newn = new Node;
	  newn->data = token;
	  push(stack_head, newn);
	  break;
	}
      }
    }
  }
  while (stack_head != nullptr) { //add remaining operators to output queue for postfix notation
    enqueue(queue_head, queue_end, pop(stack_head));
  }

  std::cout << "Postfix: ";
  //build binary expression tree
  while (queue_head != nullptr) {
    char symbol = dequeue(queue_head);

    //output the postfix expression
    std::cout << symbol << " ";
    
    if (std::isdigit(symbol)) { //operand
      BTNode* newt = new BTNode(symbol, false);
      Node* newn = new Node;
      newn->tree = newt;
      push(stack_head, newn);
    }
    else { //operator
      BTNode* newt = new BTNode(symbol, true);
      //left and right children are last nodes on stack
      newt->set_right(pop_node(stack_head));
      newt->set_left(pop_node(stack_head));
      newt->set_empty();

      //readd to stack
      Node* newn = new Node;
      newn->tree = newt;
      push(stack_head, newn);
    }
  }
  BTNode* tree = stack_head->tree;
  char input[10];
  
  while (true) {
    std::cout << "\nEnter a command (prefix, infix, postfix, quit):\n";
    std::cin >> input;

    if (!strncmp(input, "quit", 4)) break;
    if (!strncmp(input, "prefix", 6)) prefix(tree);
    if (!strncmp(input, "infix", 5)) infix(tree);
    if (!strncmp(input, "postfix", 7)) postfix(tree);
  }

}
