#include <iostream>
#include <stdlib.h>
#include <vector>
#include "AVLTree.h"
#include "Dictionary.h"

using namespace std;

int main(int argCount, char* args[])
{
  
  Dictionary dictionary("TestDictionary.txt");
  // cout << dictionary.spelled_correctly("zebra") << endl;
  //cout << dictionary.spelled_correctly("tpain")<< endl;
  vector<string>* answers = dictionary.BSTdictionary->SearchForSuggestions("then");
  for(uint i = 0; i < answers->size(); i ++)
    cout << answers->at(i) << endl;
  return 0;
}
