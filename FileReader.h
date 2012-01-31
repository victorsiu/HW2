/**
 * FileReader.h
 * 
 * Team: Reality Version 2
 * Authors: Adam Nieman
 * Date:    Jan, 29, 2012
 *
 * The file reader will take a filename, open that file and parse the words from
 * that file line by line. Bt default, all words will be stripped of their punctuation.
 * If constructed without a data file, a data file can be added, however, any words
 * held by the file reader from previous files will be deleted.
 *
 * Words pulled from a file, are then available as a vector of strings that can be pulled
 * from this class.
 *
 */

#include <vector>
#include <string>

using namespace std;

class FileReader
{
 public:
  FILE *file;
  vector<string> words;
  bool doLowerCase;

  FileReader();
  FileReader( string );
  void AddDataFile( string );
  vector<string> GetWords();

 private:
  void ParseLine( string );
  void CleanWord( string& );
};
