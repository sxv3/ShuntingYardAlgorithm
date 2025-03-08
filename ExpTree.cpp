#include "ExpTree.h"
#include <iostream>

using namespace std;

//expression tree implementation file
//by Tai Wong, March 7th

//constructs an empty tree
ExpTree::ExpTree() {
  root = nullptr;
}
//constructs a tree with a root node
ExpTree::ExpTree(Node* root) {
  this->root = root;
}

//function to print in infix 
void ExpTree::infix(Node* node) {
  if (node) {
    //checks if it is an valid operator
    bool isOperator = (node->data == '+' || node->data == '-' || 
                           node->data == '*' || node->data == '/' || node->data == '^');

    if (isOperator) {
      cout << "("; //prints opening parenthesis for infix
    }
    //recursively call function
    infix(node->left);
    //add space
    if (node->left) {
      cout << " ";
    }
    //prints current node data
    cout << node->data;
    //also adds space
    if (node->right) {
      cout << " ";
    }
    //recursively call function
    infix(node->right);
    //if it is an operator then add the closing parenthesis
    if (isOperator) {
      cout << ")";
    }
  }
}

//recursive prefix notation function
void ExpTree::prefix(Node* node) {
  if (node) {
    cout << node->data << " "; //print current node data
    prefix(node->left); // print left subtree
    prefix(node->right); //print right subtree
  }
}

//recursive postix function
void ExpTree::postfix(Node* node) {
  if (node) {
    postfix(node->left);//print left subtree
    postfix(node->right);//print right subtree
    cout << node->data << " "; // print current node data
  }
}
