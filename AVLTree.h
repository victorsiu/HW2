#ifndef AVLTREE_H
#define AVLTREE_H
#include <vector>
#include "AVLNode.h"

class AVLTree
{
 public:
  AVLTree();
  AVLTree(vector<string>* data);
  ~AVLTree();
  void insert(string data);
  AVLNode* insert(AVLNode* current, string data);
  void insertMany(vector<string>* data);
  AVLNode* find(string data); // do we want this to be a pointer or don't we? the t
  void inOrderPrintOut(vector<AVLNode>* topWords);
  vector<string>* SearchForSuggestions(string word);

 private:
  AVLNode* root;
  int height();
  int height(AVLNode* node);
  AVLNode* rotateLeftChild(AVLNode* node);
  AVLNode* rotateRightChild(AVLNode* node);
  AVLNode* doubleRotateLeftChild(AVLNode* node);
  AVLNode* doubleRotateRightChild(AVLNode* node);
  void inOrderPrintOut(AVLNode* node, vector<AVLNode>* topWords);
  void SearchForSuggestions(string word, vector<string>* suggestions,AVLNode * parent);
};
#endif
