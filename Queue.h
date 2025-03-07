#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"

//queue header file for the queue class
//Created by Tai Wong, March 7th

class Queue {
public:
  Node* front;
  Node* rear;

  Queue();
  void enqueue(char data);
  char dequeue();
  bool isEmpty();
};

#endif
