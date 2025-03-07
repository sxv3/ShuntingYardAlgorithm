#include "Node.h"
#include <iostream>

//node class implementation
//Created by Tai Wong, March 6th

Node::Node(char data) {
  this->data = data;
  this->next = nullptr;
  this->left = nullptr;
  this-> right = nullptr;
}
