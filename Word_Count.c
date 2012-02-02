#include <stdlib.h>
#include "Word_Count.h"
#include "AVLTree.h"

Word_Count::Word_Count()
{
  tree = new AVLTree();
}
Word_Count::Word_Count(AVLTree* t)
{
  //this->filename = filename;
  //tree = new AVLTree();
  
  //FileReader reader(filename);
  //tree->insertMany(reader.ProcessFile());
  this->tree = t;
}

void Word_Count::add_word( string word )
{
  tree->insert(word);
}

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

void Word_Count::get_top_words(vector<string>& word_list, vector<int>& counts, int count)
{
  vector<AVLNode>* topWords = new vector<AVLNode>();
  tree->inOrderPrintOut(topWords);
}

int Word_Count::partition(vector<AVLNode>* nodes, int left, int right,int  pivotIndex)
{
  int pivotValue = nodes->at(pivotIndex).count;
  AVLNode temp = nodes->at(pivotIndex);
  nodes->at(pivotIndex) = nodes->at(nodes->size());
  nodes->at(nodes->size()) = temp;
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
