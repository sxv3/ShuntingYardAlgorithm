#include "Stack.h"
#include <iostream>

//Stack class implementation
//Created by Tai Wong, March 6th

//constructor
Stack::Stack() {
  top = nullptr;
}

//push function code to add node to top of stack
void Stack::push(Node* node) {
  node->next = top;
  top = node;
}

//pop function to remove and return the top node of the stack
Node* Stack::pop() {
  if (isEmpty()) {
    return nullptr;
  }

  Node* temp = top;
  top = top->next;
  return temp;
}

//returns top node of stack
Node* Stack::peek() {
  if (isEmpty()) {
    return nullptr;
  } else {
    return top;
  }
}

//function to check if stack is empty
bool Stack::isEmpty() {
  return top == nullptr;
}
