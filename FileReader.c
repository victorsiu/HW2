/*
 *Authors: Theresa Krause, Sarah Spall, Victor Siu, Adam Neiman
 *Date: February 2, 2012
 *
 *Reads in a file and returns all of the words (sans normal punctuation: !,.?'")
 *in a vector
 */

#include <string>
#include <stdlib.h>
#include <string.h>
#include "FileReader.h"

/*
 *Constructor which initializes the reader to read from the given filename (text document)
 */
FileReader::FileReader(string filename)
{
  this->filename = filename;
}

/*
 *Breaks down the file into words and sends each word to ProcessWord
 *returns a vector of all the words
 */
vector<string>* FileReader::ProcessFile()
{
  //file reader stream
  ifstream in(filename.c_str());
  //the words to be returned (sans punctuation)
  vector<string>* words = new vector<string>();
  //placeholder word to hold each word read in
  string word;
  while(in >> word)
    {
      //remove punctuation
      ProcessWord(&word);
      //add the word to the vector to be returned
      words->push_back(word);
    }
  in.close();
  return words;
}

/*
 *Remove normal puctuation from the word passed in
 */
void FileReader::ProcessWord(string* word)
{
  string::iterator iter;
  string::iterator end = word->end();
  //iterate through each character in the word and check if it is any of the listed punctuation
  for(iter = word->begin(); iter != end; iter++)
    {
      if((*iter) == '.' || (*iter) == ',' || (*iter) == '?' || (*iter) == '!'
	 || (*iter) == '\'' || (*iter) == '"' || (*iter) == '(' || (*iter) == ')')
	{
	  //if it is punctuation, erase the character
	  iter = word->erase(iter);
	}
    }
}

