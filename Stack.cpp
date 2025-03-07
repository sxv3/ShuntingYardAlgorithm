#include "Stack.h"
#include <iostream>

//Stack class implementation
//Created by Tai Wong, March 6th

Stack::Stack() {
  top = nullptr;
}

void Stack::push(Node* node) {
  node->next = top;
  top = node;
}

Node* Stack::pop() {
  if (isEmpty()) {
    return nullptr;
  }

  Node* temp = top;
  top = top->next;
  return temp;
}

Node* Stack::peek() {
  if (isEmpty()) {
    return nullptr;
  } else {
    return top;
  }
}

bool Stack::isEmpty() {
  return top == nullptr;
}
