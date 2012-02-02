#include <string>
#include <vector>
#include "AVLTree.h"

using namespace std;

class Word_Count
{
 public:
  Word_Count(AVLTree* t);
  Word_Count();
  void add_word(string word);
  int get_word_count(string word);
  void get_top_words(vector<string> &word_list, vector<int> &counts, int count=50);
 private:
  AVLTree* tree;
  int partition(vector<AVLNode>* nodes, int left, int right, int pivotIndex);
  void quicksort(vector<AVLNode>* nodes, int left, int right);
};
