/**
 *
 *FileWriter.h
 *
 *
 *Authors: Adam Nieman & Victor Siu
 *
 *Comments:
 */


#ifndef FILEWRITER_H
#define FILEWRITER_H


#include <string>
#include <vector>

using namespace std;


class FileWriter
{
 public:
   void OutputHTML( string fileName, vector<string> topWords, vector<string> misspelledWords );

 void OutputHTML( vector<string> topWords, vector<string> misspelledWords );
};

#endif
