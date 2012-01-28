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
