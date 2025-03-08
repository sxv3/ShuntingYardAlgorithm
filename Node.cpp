#include "Node.h"
#include <iostream>

//node class implementation
//Created by Tai Wong, March 6th

//constructor for node class, sets Node to the given character then rest is nullptr
Node::Node(char data) {
  this->data = data;
  this->next = nullptr;
  this->left = nullptr;
  this-> right = nullptr;
}
