/**
 *
 *Node.h
 *
 *Authors: Adam Nieman & Victor Siu
 * 
 * 
 *Comments:
 *
 */

#ifndef NODE_H
#define NODE_H


#include<string>

using namespace std;

Class Node
{
 public:

  string data;
  Node * next;
  Node * previous;
  
  Node();
  Node(string);
};

#endif
