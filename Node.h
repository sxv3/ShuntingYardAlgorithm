#ifndef NODE_H
#define NODE_H

//Header file for node class
//Created by Tai Wong

class Node {
public:
  //stores the character inputtd by user for expression tree
  char data;
  //nodes for linked list
  Node* next;
  Node* left;
  Node* right;
  //constructor
  Node(char data);
  
};

#endif
  
