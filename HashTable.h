/**
 *HashTable.h
 * 
 *Authors: Adam Nieman & Victor Siu
 *
 *Comments:
 */


#ifndef HASHTABLE_H
#define HASHTABLE_H


#include <vector>
#include <string>

class HashTable
{

 public:
  // int capacity;  Since we're using a vector, we shouldn't need the capacity
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
