/*
 *Authors: Theresa Krause, Sarah Spall, Victor Siu, Adam Neiman
 *Date: February 2, 2012
 *
 *header for a class that represents a node on an AVL Tree, 
 *and stores information concerning that node
 */

#ifndef AVLNODE_H
#define AVLNODE_H
#include <string>
using namespace std;

class AVLNode
{
 public:
  AVLNode();
  /*
   *Constructor that takes in the data to be contained in the node
   */
  AVLNode(string data);
  /*
   *Constructor that takes in the data to be contained in the node
   *and the left and right chlidren of the node
   */
  AVLNode(string data, AVLNode* left, AVLNode* right);
  /*
   *Destructor for the AVLNode
   */
  ~AVLNode();

  //left subchild of the current node
  AVLNode* leftChild;
  //right subchild of the current node
  AVLNode* rightChild;
  //the data content of the node
  string data;
  //the node's current height
  int height;
  //keeps track of how many times this specific piece of data would appear in the tree
  //(although duplicates are not actually added)
  int count;
};

#endif

