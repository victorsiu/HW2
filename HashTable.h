/**
 * HashTable.h
 * 
 * Team: Reality Version 2
 * Authors: Adam Nieman & Victor Siu
 *
 * The hash table is a data structure for holding a set of elements. Specifically
 * this hash table is designed to hold string objects. Use of this hash table will
 * revolve around adding and searching for elements, with a built-in method for hashing
 * string objects.
 */


#ifndef HASHTABLE_H
#define HASHTABLE_H


#include <vector>
#include <string>

using namespace std;

class HashTable
{

 public:
  // size: the number of items in the hash table.
  int size;

  HashTable();
  ~HashTable();
  bool contains( string );
  bool add( string );
  bool add( vector<string> );
  int getCapacity();

 private:
  // loadFactor: the number of items in any one bucket of the hash table.
  //             The table will re-hash if this is ever more than 3.
  // capacity: The total capacity of the hash table.
  //           doubles with each re-hash.
  // hashTable: Pointer to an array of vector<string> objects.
  int loadFactor, capacity;
  vector<string> * hashTable;

  string stringToLower( string );
  int getHash( string );
  void reHash();

};

#endif
