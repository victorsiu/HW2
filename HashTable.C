/**
 *HashTable.C
 *
 * Team: Reality Version 2
 * Authors: Adam Nieman & Victor Siu
 *
 * The hash table will hold string objects only, and contains a built-in hash function.
 * This is a seperate chaining hash table, that will use a basic linked list in each bucket.
 * Upon creation the hash table is empty. If any bucket contains a linked list of 3 or more
 * elements, the table will re-hash, doubling its capacity.
 *
 */

#include "HashTable.h"
#include <stdlib.h>
#include <ctype.h>


/**
 * Constructor for HashTable.
 * Sets the size and load factor to 0, and the initial capacity to 10.
 */
HashTable::HashTable()
{
  this->size = 0;
  this->capacity = 10;
  this->loadFactor = 0;
  this->hashTable = new vector<string>[capacity];
}

/**
 * Destructor for HashTable.
 * Deletes the pointer that holds the hash table.
 * THIS DESTRUCTOR SEGFAULTS
 */
HashTable::~HashTable()
{
  //delete hashTable;
}


/**
 * Takes in a string and returns a copy of that string with only
 * lower-case letters.
 */
string HashTable::stringToLower( string item )
{
  for(uint i = 0; i < item.length(); i++)
    {
      item[i] = tolower( item[i] );
    }

  return item;
}



/**
 * Takes a string object and converts it into an index value
 * that fits within the current capacity of the hash table.
 * Returns that index value.
 *
 * Intends to create a preferably unique value for each unique string.
 * All upper-case letters are converted to lower-case for purpose of
 * ensuring words are not unique based on letter-case.
 */
int HashTable::getHash( string element )
{
  element = stringToLower( element );

  int result = 3 * capacity + 333;
  int count = 13;
  int letter = 0;

  for(uint i = 0; i < element.length(); i++)
    {
      letter = element[i];
      result = result + ( letter * count );
      count += 7;
    }

  result = (result % capacity );

  return abs(result);
}



/**
 * This method is called when the hash table needs to be re-sized
 * for a larger capacity. Such capacity is doubled.
 *
 * This should only be called when the hash table load factor
 * exceeds 3.
 */
void HashTable::reHash()
{
  //Set the load factor, and size back to zero.
  //They will go up, as re-hashed items are added again.
  loadFactor = 0;
  size = 0;
  uint searchSize = (uint) capacity;
  capacity = capacity * 2;

  //Create a temporary pointer to the hashTable.
  vector<string> *temp = hashTable;

  //Give the global pointer a new array for the new hash table.
  hashTable = new vector<string>[capacity];

  //Loop through the origianl table (currently pointed to by temp)
  for(uint i = 0; i < searchSize; i++)
    {
      //For each item that exists...
      if( temp[i].size() > 0 )
	{
	  //Loop through the vector to...
	  for(uint j = 0; j < temp[i].size(); j++)
	    {
	      add( temp[i].at(j) );  //Add each element to the new hash table.
	    }
	}
    }

  //Delete the temp pointer, just in case.
  delete [] temp;
}



/**
 * Takes in a string and outputs a boolean TRUE, if the given
 * string is contained within the hash table, and FALSE
 * otherwise. Strings are compared as all-lower-case versions.
 */
bool HashTable::contains( string element )
{
  int hashIndex = getHash( element );

  //Go to the proper location in the table where the element should be found.
  //If there are items there...
  if( hashTable[hashIndex].size() > 0 )
    {
      //Loop through each item...
      for(uint i = 0; i < hashTable[hashIndex].size(); i++)
	{
	  //Make the stored item lower-case for comparison.
	  string tempItem = stringToLower( hashTable[hashIndex].at(i) );

	  //Compare the item string with the element string, and return true if they match.
	  if( tempItem.compare( stringToLower( element ) ) == 0 )
	    return true;
	}
    }

  //Otherwise return false.
  return false;
}



/**
 * Adds a new string element to the hash table.
 * Hashes the string and adds it to the proper index.
 * Returns true if the element is successfully added,
 * false otherwise (usually if it is already there).
 */
bool HashTable::add(string element)
{
  //If the table contains the word, it is not added, and return false.
  if( contains( element ))
    return false;

  int hashIndex = getHash( element );

  hashTable[ hashIndex ].push_back( element );

  size++;

  //Set new loadFactor if higher.
  if( hashTable[ hashIndex ].size() > (uint) loadFactor )
    loadFactor = hashTable[ hashIndex ].size();

  //If the loadFactor is higher than 3, we re-hash the table.
  if( loadFactor > 3 )
    reHash();

  return true;
}



/**
 * An overload for add().
 * Takes a vector of strings and adds each string in the vector individually.
 * Returns true if all elements given in the vector were successfully added,
 * false otherwise.
 */
bool HashTable::add( vector<string> elements )
{
  int successfulCount = 0;

  for(uint i = 0; i < elements.size(); i++)
    {
      if( add( elements[i] ) )
	successfulCount++;
    }

  if( successfulCount != (int) elements.size() )
    return false;
  else
    return true;
}

int HashTable::getCapacity()
{
  return capacity;
}
