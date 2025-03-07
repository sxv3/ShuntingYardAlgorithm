#include "Queue.h"

//queue class implementation file
//by Tai Wong March 7th

Queue::Queue() {
  front = nullptr;
  rear = nullptr;
}

void Queue::enqueue(char data) {
  Node* newNode = new Node(data);
  if (rear == nullptr) {
    front = rear = newNode;
    return;
  }
  
  rear->next = newNode;
  rear = newNode;
}

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
  return data;
}

bool Queue::isEmpty() {
  return front == nullptr;
}
