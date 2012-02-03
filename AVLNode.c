#include "AVLNode.h"

// string* data
// AVLNode* leftChild
// AVLNode* rightChild

/*
 *Constructor that takes no parameters
 *
 */
AVLNode::AVLNode()
{
  this->count = 0; // count is zero because there is no word
  this->leftChild = NULL; 
  this->rightChild = NULL;
  this->height = 0;
}
/*
 *Constructor which takes in the data for a Node as a string
 *and initializes all variables
 */
AVLNode::AVLNode(string data)
{
  this->data = data;
  this->count = 1;
  this->leftChild = NULL;
  this->rightChild = NULL;
  this->height = 0;
}

AVLNode::AVLNode(string data, AVLNode* left, AVLNode* right)
{
  this->data = data;
  this->leftChild = left;
  this->rightChild = right;
}

AVLNode::~AVLNode()
{

}


