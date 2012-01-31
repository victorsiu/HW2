#include <iostream>
#include <stdlib.h>
#include <vector>
#include "AVLTree.h"
#include "FileReader.h"

using namespace std;

int main(int argCount, char* args[])
{
   vector<string>* testing = new vector<string>();
   FileReader reader("dummy.txt");
   testing = reader.ProcessFile();
   for(uint i = 0; i < testing->size(); i ++)
     {
       cout << testing->at(i) << endl;
     }
  vector<string*>* tester = new vector<string*>();
  tester->push_back(new string("test"));
  tester->push_back(new string("hello"));
  tester->push_back(new string("right"));
  tester->push_back(new string("left"));
  tester->push_back(new string("high"));
  tester->push_back(new string("weed"));
  tester->push_back(new string("foot"));
  tester->push_back(new string("prostitute"));
  tester->push_back(new string("tar"));
  tester->push_back(new string("apple"));
  tester->push_back(new string("alphabet"));

  // AVLTree tree(tester);
  // tree.inOrderPrintOut();

  return 0;
}
