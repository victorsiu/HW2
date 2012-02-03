#include <iostream>
#include <stdlib.h>
#include <vector>
#include "AVLTree.h"
#include "Dictionary.h"
#include "Word_Count.h"

using namespace std;

int main(int argCount, char* args[])
{  
  //Dictionary dictionary("TestDictionary.txt");
  // cout << dictionary.spelled_correctly("zebra") << endl;
  //cout << dictionary.spelled_correctly("tpain")<< endl;
  // vector<string>* answers = dictionary.BSTdictionary->SearchForSuggestions("then");
  //for(uint i = 0; i < answers->size(); i ++)
  //cout << answers->at(i) << endl;

  vector<string> word_list; 
  vector<int> counts; 
  vector<int> &count_ = counts;
  vector<string> &words = word_list;
  AVLTree* tree = new AVLTree();
  FileReader reader("AnotherTest.txt");
  tree->insertMany(reader.ProcessFile());
  Word_Count count(tree);
  int test = count.get_word_count("one");
  cout << test << endl;
  count.get_top_words(words,count_, 2);
  for(uint i = 0; i < word_list.size(); i ++)
    {
      cout << word_list.at(i) << endl;
      cout << counts.at(i) << endl;
    }
// Word_Count count2();
  // vector<string>* words = reader.ProcessFile()
  return 0;
}
