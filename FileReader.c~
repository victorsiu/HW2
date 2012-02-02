#include <string>
#include <stdlib.h>
#include <string.h>
#include "FileReader.h"

FileReader::FileReader(string filename)
{
  this->filename = filename;
}

vector<string>* FileReader::ProcessFile()
{
  ifstream in(filename.c_str());
  vector<string>* words = new vector<string>();
  string word;
  while(in >> word)
    {
      ProcessWord(&word);
      words->push_back(word);
    }
  in.close();
  return words;
}

void FileReader::ProcessWord(string* word)
{
  string::iterator iter;
  string::iterator end = word->end();
  for(iter = word->begin(); iter != end; iter++)
    {
      if((*iter) == '.' || (*iter) == ',' || (*iter) == '?' || (*iter) == '!'
	 || (*iter) == '\'' || (*iter) == '"' || (*iter) == '(' || (*iter) == ')')
	{
	  iter = word->erase(iter);
	}
    }
  // string temp = "stop here...";
}

