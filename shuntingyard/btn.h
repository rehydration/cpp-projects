//binary tree node

#ifndef BTN_H
#define BTN_H

class BTNode {
public:
  BTNode();
  int get_value();
  ~BTNode();
private:
  BTNode left, right;
  bool oper;
  char value;
};




#endif
