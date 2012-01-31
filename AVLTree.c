#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "AVLTree.h"

AVLTree::AVLTree()
{
  root = NULL;
}

AVLTree::AVLTree(vector<string*>* data)
{
  root = NULL;
  insertMany(data);
}

AVLTree::~AVLTree()
{

}

AVLNode* AVLTree::insert(AVLNode* current,string* data)
{
  if(root == NULL)
    {
      root = new AVLNode(data);
      return root;
    }
  if(current==NULL)
    {
      current = new AVLNode(data);
    }
  else if(strcmp((*data).c_str(),(*(current->data)).c_str())< 0)
    {
      current->leftChild = insert(current->leftChild, data);
      //check if the tree is unbalanced
      if(height(current->leftChild) - height(current->rightChild) == 2)
	{
	  if(strcmp((*data).c_str(),(*(current->leftChild->data)).c_str()) < 0)
	    current = rotateLeftChild(current);
	  else
	    current = doubleRotateLeftChild(current);
	}
    }
  else if(strcmp((*data).c_str(),(*(current->data)).c_str())>0)
    {
      current->rightChild = insert(current->rightChild, data);
      //check if the tree is unbalanced
      if(height(current->rightChild) - height(current->leftChild) == 2)
	{
	  if(strcmp((*data).c_str(),(*(current->rightChild->data)).c_str())>0)
	    current = rotateRightChild(current);
	  else
	    current = doubleRotateRightChild(current);
	}
    }
  if(height(current->leftChild) > height(current->rightChild))
    {
      current->height = height(current->leftChild);
    }
  else
    current->height = height(current->rightChild);

  return current;
}

void AVLTree::insertMany(vector<string*>* data)
{
  for(uint i = 0; i < data->size(); i ++)
      insert(root, data->at(i));
}

AVLNode* AVLTree::find(string* data)
{
  AVLNode* temp = root;
  while(temp != NULL)
    {
      if(strcmp((*data).c_str(),(*(temp->data)).c_str())<0)
	temp = temp->leftChild;
      else if(strcmp((*data).c_str(),(*(temp->data)).c_str())>0)
	temp = temp->rightChild;
      else
	return temp;
    }
  return NULL;
}

int AVLTree::height()
{
  return height(root);
}

int AVLTree::height(AVLNode* node)
{
  if(node == NULL) 
    return -1;
  else
    return node->height;
}

AVLNode* AVLTree::rotateLeftChild(AVLNode* node)
{
  AVLNode* node2 = node->leftChild;
  node->leftChild = node2->rightChild;
  node2->rightChild = node;

  //update heights
  node->height = max( height(node->leftChild), height(node->rightChild) );
  node2->height = max( height(node2->leftChild), height(node2->rightChild) );
  
  //return the new root
  return node2;
}

AVLNode* AVLTree::rotateRightChild(AVLNode* node)
{
  AVLNode* node2 = node->rightChild;
  node->rightChild = node2->leftChild;
  node2->leftChild = node;

  //update heights
  node->height = max( height(node->leftChild), height(node->rightChild) );
  node2->height = max( height(node2->leftChild), height(node2->rightChild) );

  //return the new root node
  return node2;
}

AVLNode* AVLTree::doubleRotateLeftChild(AVLNode* node)
{
  //rotate the left child using the right child rotate
  node->leftChild = rotateRightChild(node->leftChild);

  //rotate again for the double rotation
  return rotateLeftChild(node);
}

AVLNode* AVLTree::doubleRotateRightChild(AVLNode* node)
{
  //rotate the right child with the left child rotate
  node->rightChild = rotateLeftChild(node->rightChild);

  //rotate again for the double rotation
  return rotateRightChild(node);

}

void AVLTree::inOrderPrintOut()
{
  inOrderPrintOut(this->root);
}
void AVLTree::inOrderPrintOut(AVLNode* node)
{
  if(node == NULL)
    return;
  inOrderPrintOut(node->leftChild);
  cout<< *(node->data) << endl;
  inOrderPrintOut(node->rightChild);
}


