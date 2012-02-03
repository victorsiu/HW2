/*
 *Authors: Theresa Krause, Sarah Spall, Victor Siu, Adam Neiman
 *Date: February 2, 2012
 *
 *header file for the file reader class which reads in data from a text file
 *and creates a list of the words in the file
 */

#ifndef FILEREADER_H
#define FILEREADER_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class FileReader
{
 public:
  /*
   *Constructor which takes in a filename
   */
  FileReader(string filename);
  /*
   *Processes the file and creates a list of words in the file
   */
  vector<string>* ProcessFile();
 private:
  //the name of the text file to be read in
  string filename;
  /*
   *Removes punctuation from the word passed into it
   */
  void ProcessWord(string* word);

};

#endif
