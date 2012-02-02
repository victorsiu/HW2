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

  AVLTree* tree = new AVLTree();
  FileReader reader("AnotherTest.txt");
  tree->insertMany(reader.ProcessFile());
  Word_Count count(tree);
  int test = count.get_word_count("one");
  cout << test << endl;
  
  // Word_Count count2();
  // vector<string>* words = reader.ProcessFile()
  return 0;
}
