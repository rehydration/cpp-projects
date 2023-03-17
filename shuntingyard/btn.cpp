#include "btn.h"

BTNode::BTNode() {
}

//constructor
BTNode::BTNode(char newvalue, bool isoper) {
  value = newvalue;
  oper = isoper;
}

//return if operator
bool BTNode::is_oper() {
  return oper;
}

//return if node has children
bool BTNode::is_empty() {
  return empty;
}

//has children
void BTNode::set_empty() {
  empty = false;
}

//left and right children

void BTNode::set_left(BTNode* newleft) {
  left = newleft;
}

void BTNode::set_right(BTNode* newright) {
  right = newright;
}

BTNode* BTNode::get_left() {
  return left;
}

BTNode* BTNode::get_right() {
  return right;
}

//return char
char BTNode::get_value() {
  return value;
}

//destructor
BTNode::~BTNode() {
  delete left;
  delete right;
}
