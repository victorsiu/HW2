/**
 * Dictionary.C
 *
 * Team: Reality Version 2
 * Authors: Adam Nieman & Victor Siu & Sarah Spall & Theresa Krause
 * Date: Jan 30, 2012
 *
 * The dictionary represents a list of words. It is constructed with
 * a file name of a file that contains a list of words to be used for
 * the dictionary.
 *
 * Words can then be checked against the dictionary with the available
 * methods.
 */

#include "Dictionary.h"
#include <stdlib.h>

Dictionary::Dictionary(){}


/**
 * Constructor.
 * Takes in a file name, a list of words to be used as the basis
 * for the dictionary.
 */
Dictionary::Dictionary( string fileName )
{
  this->reader = new FileReader( fileName );
  vector<string>* wordList = reader->ProcessFile();
  BSTdictionary = new AVLTree(wordList);
  dictionary = new HashTable();
  SetDictionary(wordList);

}

/**
 * Takes a vector of strings (expected from reading a file of words)
 * and places each word in the vector into the hash table and BST
 * that represent the dictionary.
 */
void Dictionary::SetDictionary( vector<string>* wordList )
{
   for(uint i = 0; i < wordList->size(); i++)
     {
       dictionary->add( wordList->at(i) );
     }
}

/**
 * Takes in a string, and compares that string to the dictionary
 * list of words for spelling. Returns true if the word is found
 * as given, in the dictionary. Returns false otherwise.
 */
bool Dictionary::spelled_correctly( string givenWord )
{
  return dictionary->contains( givenWord );
}

/**
 * This takes in a given word, a vector for strings and a number. This will check the
 * spelling of the given word, and return true if it is spelled correctly. Otherwise,
 * this will find a number of similarly-spelled words (equal to the number given or 5
 * as a default), and will append those words to the end of the given vector list.
 * If words are appended to the end of the given vector, this will return false.
 */
bool Dictionary::best_matches( string givenWord, vector<string> &list, int count = 5 )
{
  if( spelled_correctly( givenWord ) )
    return true;

  //Then use the BST to find similar words. I don't have a clue how this is supposed to work.
  //Probably need some kind of "FindNearby" method in the BST that takes in a number.
  return false;
}
