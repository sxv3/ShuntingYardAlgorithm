#ifndef STACK_H
#define STACK_H

#include "Node.h"

//Stack class header file
//Created by Tai Wong, March 6th

class Stack {
public:
  Node* top;
  
  Stack();
  void push(char data);
  char pop();
  char peek();
  bool isEmpty();
};

#endif
