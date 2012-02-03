/**
 * FileReader.h
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
  FileReader(string filename);
  vector<string>* ProcessFile();
 private:
  string filename;
  void ProcessWord(string* word);

};

#endif
