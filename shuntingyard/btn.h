//binary tree node

#ifndef BTN_H
#define BTN_H

class BTNode {
public:
  BTNode();
  BTNode(char, bool);
  bool is_oper();
  bool is_empty();
  void set_empty();
  void set_left(BTNode*);
  void set_right(BTNode*);
  BTNode* get_left();
  BTNode* get_right();
  char get_value();
  ~BTNode();
private:
  BTNode* left;
  BTNode* right;
  bool oper;
  bool empty = true;
  char value;
};




#endif
