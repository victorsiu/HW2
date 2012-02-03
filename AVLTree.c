/*
 *Authors: Theresa Krause, Sarah Spall, Victor Siu, Adam Neiman
 *Date: February 2, 2012
 *
 *Creates an AVLTree (self balancing binary search tree) with insert capabilities,
 *and find capabilities.
 *Also includes methods to find similar word suggestions (for use in HW2 CS3505)
 *and to get a word count for the number of times a word appears in the tree
 */


#include <sstream>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "AVLTree.h"

/*
 *Constructs an empty tree
 */
AVLTree::AVLTree()
{
  root = NULL;
}

/*
 *Constructs a tree that inserts all of the given data (from a vector)
 */
AVLTree::AVLTree(vector<string>* data)
{
  root = NULL;
  insertMany(data);
}

/*
 *AVLTree Desructor
 */
AVLTree::~AVLTree()
{

}

/*
 *(Driver method) Inserts a node into the tree with the given string as it's data
 */
void AVLTree::insert(string data)
{
  insert(root, data);
}
/*
 *Recursively inserts into the tree, if the root does not exist it creates a new one with the first piece of data
 *Data less than goes to the left, and greater than goes to the right down the tree.
 *Checks if balanced by the definition of an AVLTree on every insert
 */
AVLNode* AVLTree::insert(AVLNode* current,string data)
{
  //creates a new root if one does not already exist
  if(root == NULL)
    {
      root = new AVLNode(data);
      return root;
    }
  if(current==NULL)
    {
      current = new AVLNode(data);
    }
  //if the data is less than the current node, move to the left and try to insert
  else if(strcmp(data.c_str(),current->data.c_str())< 0)
    {
      current->leftChild = insert(current->leftChild, data);
      //check if the tree is unbalanced
      if(height(current->leftChild) - height(current->rightChild) == 2)
	{
	  if(strcmp(data.c_str(),current->leftChild->data.c_str()) < 0)
	    current = rotateLeftChild(current);
	  else
	    current = doubleRotateLeftChild(current);
	}
    }
  //if the data is greater than the current node, move to the right and try to insert
  else if(strcmp(data.c_str(),current->data.c_str())>0)
    {
      current->rightChild = insert(current->rightChild, data);
      //check if the tree is unbalanced
      if(height(current->rightChild) - height(current->leftChild) == 2)
	{
	  if(strcmp(data.c_str(),current->rightChild->data.c_str())>0)
	    current = rotateRightChild(current);
	  else
	    current = doubleRotateRightChild(current);
	}
    }

  //the data is equal, so the word already appeared in the tree, increment the count 
  else if(strcmp(data.c_str(), current->data.c_str()) == 0)
    {
      current->count++;
    }

  //reset the height of the tree
  if(height(current->leftChild) > height(current->rightChild))
    {
      current->height = height(current->leftChild);
    }
  else
    current->height = height(current->rightChild);

  return current;
}

/*
 *Inserts as many new nodes into the tree as there are values in the vector
 *Inserts by calling the insert method
 */
void AVLTree::insertMany(vector<string>* data)
{
  for(uint i = 0; i < data->size(); i ++)
      insert(root, data->at(i));
}

/*
 *Finds and returns a node in the tree with matching data to the given data
 *if no match is found, NULL is returned
 */
AVLNode* AVLTree::find(string data)
{
  AVLNode* temp = root;
  while(temp != NULL)
    {
      //searches left
      if(strcmp(data.c_str(),temp->data.c_str())<0)
	temp = temp->leftChild;
      //searches right
      else if(strcmp(data.c_str(),temp->data.c_str())>0)
	temp = temp->rightChild;
      else
	return temp;
    }
  //if none found, return NULL
  return NULL;
}

/*
 *Recursively get the height of the tree, starting at the root node
 *If height if returned as -1, the tree is empty
 */
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

/*
 *Case 1 rotate for an AVLTree to maintain balance
 */
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

/*
 *Case 2 rotate for an AVLTree to maintain balance
 */
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

/*
 *Case 3 rotate for an AVLTree to maintain balance
 */
AVLNode* AVLTree::doubleRotateLeftChild(AVLNode* node)
{
  //rotate the left child using the right child rotate
  node->leftChild = rotateRightChild(node->leftChild);

  //rotate again for the double rotation
  return rotateLeftChild(node);
}

/*
 *Case 4 rotate for an AVLTree to maintain balance
 */
AVLNode* AVLTree::doubleRotateRightChild(AVLNode* node)
{
  //rotate the right child with the left child rotate
  node->rightChild = rotateLeftChild(node->rightChild);

  //rotate again for the double rotation
  return rotateRightChild(node);

}

/*
 *(Driver method) recursively traverse the tree and find the top
 *occurring words in the tree
 */
void AVLTree::inOrderPrintOut(vector<AVLNode>* topWords)
{
  inOrderPrintOut(this->root, topWords);
}
void AVLTree::inOrderPrintOut(AVLNode* node, vector<AVLNode>* topWords)
{
  if(node == NULL)
    return;
  inOrderPrintOut(node->leftChild, topWords);
  if(topWords->size() < topWords->capacity())
    topWords->push_back(*node);
  else
    {
      int smallest = 0;
      for(uint i = 1; i < topWords->size(); i ++)
	{
	  if(topWords->at(i).count < topWords->at(smallest).count)
	    smallest = i;
	}
      if(topWords->at(smallest).count < node->count)
	topWords->at(smallest) = *node;
    }
  inOrderPrintOut(node->rightChild, topWords);
}

//Driver Method for searching
vector<string>*  AVLTree::SearchForSuggestions(string word)
{
  AVLNode* currentNode = root;

  if(currentNode == NULL)
    return NULL;

  vector<string> * suggestions = new vector<string>();

  SearchForSuggestions(word, suggestions, currentNode);
  
  return suggestions;

}

void AVLTree::SearchForSuggestions(string word, vector<string>* suggestions, AVLNode* currentNode)
{
  double LIKENESS_THRESHOLD = 0.70; //70%  Change as necessary.  Searches for words that are 70% alike.

  
  if(currentNode == NULL)
    return;

  double sameLetters = 0; //Use a double for ease of conversion
  for(uint i = 0; i < currentNode->data.size(); i++)
    {
      //Account for duplicate letters later
      char letter = word[i];
      if(currentNode->data.find(letter,0) != string::npos)//If it can find the letter
	{
	  sameLetters++;
	}
    }

  double likeness = (  sameLetters / (double)(currentNode->data.length())  );

  if(likeness >= LIKENESS_THRESHOLD)//If its enough alike, add it to the suggestions
    {
      suggestions-> push_back(currentNode->data);
    }

  SearchForSuggestions(word, suggestions, currentNode->leftChild);
  SearchForSuggestions(word, suggestions, currentNode->rightChild);
}
