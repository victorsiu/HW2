/*
 *Authors: Theresa Krause, Sarah Spall, Victor Siu, Adam Neiman
 *Date: February 2, 2012
 *
 *Constructs a new node for an AVL Tree which stores its data(string),
 *and it's left and right subchildren in the tree.
 */

#include "AVLNode.h"

// Member variables:
// string* data
// AVLNode* leftChild
// AVLNode* rightChild
// int height
// int count

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
  this->data = data;  //the node's data
  this->count = 1;  //count is initialized to 1, because the word appears at least once on creation
  this->leftChild = NULL; //NULL until set and created
  this->rightChild = NULL; //NULL until set and created
  this->height = 0; //the height of 1 node is 0
}

/*
 *Alternative constructor that takes in a left and right node reference to keep 
 *track of the left and right subchildren
 */
AVLNode::AVLNode(string data, AVLNode* left, AVLNode* right)
{
  this->data = data;
  this->leftChild = left;
  this->rightChild = right;
}

/*
 *Destructor for the AVLNode
 */
AVLNode::~AVLNode()
{

}


