/*
 *Authors: Theresa Krause, Sarah Spall, Victor Siu, Adam Neiman
 *Date: February 2, 2012
 *
 *header file for an AVLTree, which creates a self balancing tree structure
 */

#ifndef AVLTREE_H
#define AVLTREE_H
#include <vector>
#include "AVLNode.h"

class AVLTree
{
 public:
  /*
   *Constructor that takes no paramters, nodes must be added later in this case
   *creates an empty tree
   */
  AVLTree();
  /*
   *Constructor that takes in the data that is to populate the tree
   */
  AVLTree(vector<string>* data);
  /*
   *Destructor for the AVLTree
   */
  ~AVLTree();
  /*
   *Driver for insert
   *Inserts a new node into the tree with the specified data
   *does not insert if that data already exists in the tree
   */
  void insert(string data);
  AVLNode* insert(AVLNode* current, string data);
  /*
   *Inserts many nodes into the tree at once using the list of data provided
   */
  void insertMany(vector<string>* data);
  /*
   *Finds and returns a specific node in the tree based on the data provided
   */
  AVLNode* find(string data);
  /*
   *Method used traverse the tree for a histogram (inOrder Traversal)
   */
  void inOrderPrintOut(vector<AVLNode>* topWords);
  /*
   *returns a vector of suggestions or related words to the given word from the data already in the tree
   */
  vector<string>* SearchForSuggestions(string word);

 private:
  //root of the tree
  AVLNode* root;
  //height of the tree
  int height();
  //height of the tree at a specific node
  int height(AVLNode* node);
  /*
   *Performs a single left rotation for Case 1 of an AVLTree
   */
  AVLNode* rotateLeftChild(AVLNode* node);
  /*
   *Performs a single right rotation for Case 2 of an AVLTree
   */
  AVLNode* rotateRightChild(AVLNode* node);
  /*
   *Performs a double left rotation for case 3 of an AVLTree
   */
  AVLNode* doubleRotateLeftChild(AVLNode* node);
  /*
   *Performs a double right rotation for case 4 of an AVLTree
   */
  AVLNode* doubleRotateRightChild(AVLNode* node);
  /*
   *Private function to recursively traverse the tree (used for the histogram)
   */
  void inOrderPrintOut(AVLNode* node, vector<AVLNode>* topWords);
  /*
   *Private function to find the suggestions similar to the input word based on the current contents of the tree
   */
  void SearchForSuggestions(string word, vector<string>* suggestions,AVLNode * parent);
};
#endif
