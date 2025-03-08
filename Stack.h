#ifndef STACK_H
#define STACK_H

#include "Node.h"

//Stack class header file
//Created by Tai Wong, March 6th

//stack via linked list structure
class Stack {
public:
  Node* top; // pointer to top of the stack
  
  //constructor
  Stack();
  void push(Node* node);//adds node to top of stack
  Node* pop(); // removes and returns top of the stack
  Node* peek(); //returns top node of stack without deleting it
  bool isEmpty(); //checks if stack is empty
};

#endif
