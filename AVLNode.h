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
  AVLNode(string data, AVLNode* left, AVLNode* right);
  ~AVLNode();
  AVLNode* parent; // do we need to initialize these before
  // setting them to what is passed in?
  AVLNode* leftChild;
  AVLNode* rightChild;
  string data;
  int height;
  int count;
};

#endif

