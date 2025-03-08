#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"

//queue header file for the queue class
//Created by Tai Wong, March 7th

class Queue {
public:
  Node* front; // points to first element
  Node* rear; // points to last element

  Queue(); // constructor
  void enqueue(char data); //adds element to end of the queue
  char dequeue(); // removes and return the front element of queue
  bool isEmpty(); // checks if queue is empty
};

#endif
