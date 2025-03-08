#include <iostream>
#include <cstring>
#include "Stack.h"
#include "Queue.h"
#include "ExpTree.h"

using namespace std;

//main file with shunting yard algorithm
//by Tai Wong, March 7th

//function prototypes
int precedence(char op);
char* convertToPostfix(const char* expression);
ExpTree* buildExpressionTree(const char* postfix);

//determines the order of operators
int precedence(char op) {
  if (op == '+' || op == '-') return 1;
  if (op == '*' || op == '/') return 2;
  if (op == '^') return 3;
  return 0;
}

//convert infix to postfix using shunting yard algorithm
char* convertToPostfix(const char* expression) {
  Stack operators;
  Queue output;
  static char result[100]; // buffer for postfix output
  
  int index = 0;
  
  for (int i = 0; expression[i] != '\0'; i++) {
    char token = expression[i];
    //if token is a digit, add it directly to output
    if (token >= '0' && token <= '9') {
      output.enqueue(token);
      output.enqueue(' ');
    } else if (token == '(') { // if token is opening parenthesis, push it to stack
      operators.push(new Node(token));
    } else if (token == ')') { // if it is a closing parenthesis, pop operators until ( is found
      while (!operators.isEmpty() && operators.peek()->data != '(') {
	output.enqueue(operators.pop()->data);
	output.enqueue(' ');
      }
      operators.pop(); // remove '(' from stack
    } else if (token == '+' || token == '-' || token == '*' || token == '/' || token == '^') { //if operator, handles precedence
      while (!operators.isEmpty() && precedence(operators.peek()->data) >= precedence(token)) {
	output.enqueue(operators.pop()->data);
	output.enqueue(' ');
      }
      operators.push(new Node(token));
    }
  }
  //pop remaining operators into output
  while (!operators.isEmpty()) {
    output.enqueue(operators.pop()->data);
    output.enqueue(' ');
  }
  
  // dequeue everything into result array
  while (!output.isEmpty()) {
    result[index] = output.dequeue();
    index++;
  }
  result[index] = '\0';
  return result;
}

//build expression tree from postfix
ExpTree* buildExpressionTree(const char* postfix) {
  Stack treeStack;
  for (int i = 0; postfix[i] != '\0'; i++) {
    char token = postfix[i];
    if (token == ' ') {
      continue;
    }
    Node* newNode = new Node(token);
    if (token >= '0' && token <= '9') {
      treeStack.push(newNode);
    } else {
      //if it is an operator then it pops 2 nodes and makes them children
      Node* rightNode = treeStack.pop();
      Node* leftNode = treeStack.pop();
      newNode->right = rightNode;
      newNode->left = leftNode;
      treeStack.push(newNode);
    }
  }
  Node* rootNode = treeStack.pop();
  return new ExpTree(rootNode);
}


int main() {
  
  char expression[100];
  cout << "enter an infix expression with spaces between tokens: ";
  cin.getline(expression, 100);

  //convert infix to postfix
  char* postfix = convertToPostfix(expression);
  cout << "postfix expression: " << postfix << endl;

  //build the exp tree from postfix
  ExpTree* tree = buildExpressionTree(postfix);

  //output in different notations
  cout << "infix expression: ";
  tree->infix(tree->root);
  cout << endl;
  
  cout << "prefix expression: ";
  tree->prefix(tree->root);
  cout << endl;
    
  cout << "postfix expression: ";
  tree->postfix(tree->root);
  cout << endl;
  
  delete tree;
  return 0;
}
