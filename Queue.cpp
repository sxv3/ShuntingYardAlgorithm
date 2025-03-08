#include "Queue.h"
#include <iostream>

//queue class implementation file
//by Tai Wong March 7th

//constructor
Queue::Queue() {
  front = nullptr;
  rear = nullptr;
}

//adds element to the rear of the queue
void Queue::enqueue(char data) {
  Node* newNode = new Node(data);
  if (rear == nullptr) {
    front = rear = newNode;
    return;
  }
  
  rear->next = newNode;
  rear = newNode;
}

//removes front element of queue
char Queue::dequeue() {
  if (isEmpty()) {
    return '\0'; // returns  null character if queue is empty
  }
  
  Node* temp = front;
  char data = temp->data;
  front = front->next;
  if (front == nullptr) {
    rear = nullptr;
  }
  delete temp;
  //returns the character of the front element of the queue
  return data;
}

//checks if queue is empty
bool Queue::isEmpty() {
  return front == nullptr;
}
