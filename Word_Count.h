/*
 *Authors: Theresa Krause, Sarah Spall, Victor Siu, Adam Neiman
 *Date: February 2, 2012
 *
 *Gets the most occuring words from a set of string data, the word count for a specific word
 *in an AVLTree
 */

#include <string>
#include <vector>
#include "AVLTree.h"

using namespace std;

class Word_Count
{
 public:
  /*
   *Constructor that takes in a pre-populated AVLTree
   */
  Word_Count(AVLTree* t);
  /*
   *Constructor that creates a new, empty AVLTree
   */
  Word_Count();
  /*
   *Adds a word to the word count tree (used if the tree was initially empty)
   *i.e. the second constructor
   */
  void add_word(string word);
  /*
   *Returns the number of times a word appears in the set of data
   */
  int get_word_count(string word);
  /*
   *Gets the most frequently occuring words in a set of data
   */
  void get_top_words(vector<string> &word_list, vector<int> &counts, int count=50);
 private:
  //the AVLTree used to hold the data
  AVLTree* tree;
  //quicksort methods to sort the top words data
  int partition(vector<AVLNode>* nodes, int left, int right, int pivotIndex);
  void quicksort(vector<AVLNode>* nodes, int left, int right);
};
