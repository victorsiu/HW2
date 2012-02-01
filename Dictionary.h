/**
 * Dictionary.h
 *
 * Team: Reality Version 2
 * Authors: Adam Nieman & Victor Siu
 * Date: Jan 30, 2012
 *
 * The dictionary represents a set of words that can be used as a reference
 * for checking the spelling of words in other documents. Creating the
 * dictionary requires a file name to a list of words.
 * 
 */

#include <vector>
#include <string>
#include "HashTable.h"
#include "FileReader.h"
#include "AVLTree.h"

using namespace std;

class Dictionary
{
 public:
  HashTable* dictionary;
  AVLTree* BSTdictionary;
  FileReader *reader;
  int totalWords;

  Dictionary();
  Dictionary( string );
  bool spelled_correctly( string );
  bool best_matches( string, vector<string>&, int );

 private:
  void SetDictionary( vector<string>* words );
};
