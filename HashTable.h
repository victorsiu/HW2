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

class HashTable
{

 public:
  // int capacity;  Since we're using a vector, we shouldn't need the capacity
  // The hash table should be based on a basic array rather than a vector
  int size;

  HashTable();
  bool contains(string item);
  void add(string*  item);
  void add(vector<string> items);
  int get_hash(string item);
  bool remove(string item);


 private:
  vector<string> hashTable;

};

#endif
