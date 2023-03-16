#include "btn.h"

BTNode::BTNode() {
}

BTNode::BTNode(char newvalue, bool isoper) {
  value = newvalue;
  oper = isoper;
}

bool BTNode::is_oper() {
  return oper;
}

bool BTNode::is_empty() {
  return empty;
}

void BTNode::set_empty() {
  empty = false;
}

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

char BTNode::get_value() {
  return value;
}

BTNode::~BTNode() {
  delete left;
  delete right;
}
