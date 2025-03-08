#ifndef EXPTREE_H
#define EXPTREE_H

#include "Node.h"

//expression tree class header file
//by Tai Wong, March 7th

class ExpTree {
public:
  //root of the binary expression tree
  Node* root;
  //constructor
  ExpTree();
  //constructor with root
  ExpTree(Node* root);
  void infix(Node* node); //function to print in infix
  void prefix(Node* node); // function to print in prefix
  void postfix(Node* node); // function to print in postfix
};

#endif
