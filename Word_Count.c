/*
 *Authors: Theresa Krause, Sarah Spall, Victor Siu, Adam Neiman
 *Date: February 2, 2012
 *
 *Populates an AVLTree with a set of string data and has methods to
 *get the word count of a specific string, as well as return a list of the
 *most frequently occuring words in the data set
 */


#include <stdlib.h>
#include "Word_Count.h"
#include "AVLTree.h"

/*
 *Creates a new empty AVLTree that can be populated on add_word
 */
Word_Count::Word_Count()
{
  tree = new AVLTree();
}
/*
 *Constructor that is given a populated AVLTree to use in the word count
 *processing
 */
Word_Count::Word_Count(AVLTree* t)
{
  this->tree = t;
}

/*
 *Adds a string to the AVLTree
 */
void Word_Count::add_word( string word )
{
  tree->insert(word);
}

/*
 *Returns the word count of the given string in the tree
 */
int  Word_Count::get_word_count( string word )
{
  AVLNode* node = tree->find(word);
  if(node == NULL)
    return 0;
  else
    {
      return node->count;
    }
}

/*
 *Returns the most frequently occuring words in the tree (as many as count specifies)
 */
void Word_Count::get_top_words(vector<string>& word_list, vector<int>& counts, int count)
{
  vector<AVLNode>* topWords = new vector<AVLNode>(count);
  tree->inOrderPrintOut(topWords);
  quicksort(topWords, 0, topWords->size() -1);
  for(int i = topWords->size()-1 ; i > -1; i --)
    {
      word_list.push_back(topWords->at(i).data);
      counts.push_back(topWords->at(i).count);
    }
}
/*
 *Quick Sort method to sort the nodes in descending order
 */
int Word_Count::partition(vector<AVLNode>* nodes, int left, int right,int  pivotIndex)
{
  int pivotValue = nodes->at(pivotIndex).count;
  AVLNode temp = nodes->at(pivotIndex);
  nodes->at(pivotIndex) = nodes->at(nodes->size()-1);
  nodes->at(nodes->size()-1) = temp;
  int storeIndex = left;
  for(int i = left; i < right; i ++)
    {
      if(nodes->at(i).count < pivotValue)
	{
	  temp = nodes->at(i);
	  nodes->at(i) = nodes->at(storeIndex);
	  nodes->at(storeIndex) = temp;
	}
      storeIndex ++;
    }
  temp = nodes->at(storeIndex);
  nodes->at(storeIndex) = nodes->at(right);
  nodes->at(right) = temp;
  return storeIndex;
}

/*
 *Classic quick sort algorithm to sort the nodes in descending order
 */
void Word_Count::quicksort(vector<AVLNode>* nodes, int left, int right)
{
  if(left < right)
    {
      int pivotIndex = (left + right) / 2;
      pivotIndex = partition(nodes, left, right, pivotIndex);
      quicksort(nodes, left, pivotIndex -1);
      quicksort(nodes, pivotIndex + 1, right);
    }
}
