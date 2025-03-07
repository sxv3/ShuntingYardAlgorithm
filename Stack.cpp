#include "Stack.h"

//Stack class implementation
//Created by Tai Wong, March 6th

Stack::Stack() {
  top = NULL;
}

void Stack::push(char data) {
  Node* newNode = new Node(data);
  newNode->next = top;
  top = newNode;
}

char Stack::pop() {
  if (isEmpty()) {
    return '\0'; //null character if stack is empty
  }

  Node* temp = top;
  char data = temp->data;
  top = top->next;
  delete temp;
  return data;
}

char Stack::peek() {
  if (isEmpty()) {
    return '\0';
  } else {
    return top->data;
  }
}

bool Stack::isEmpty() {
  return top == NULL;
}
