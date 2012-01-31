/**
 * FileReader.C
 *
 * Team: Reality Version 2
 * Authors: Adam Nieman
 *
 * Comments.
 *
 */

#include "FileReader.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>


using namespace std;

/**
 * Constructor. Default.
 * The AddDataFile() method must be called to perform any work on a file
 * only the default constructor is used.
 */
FileReader::FileReader(){}



/**
 * Constructor.
 * Takes the string name (or pathname) of a file from this same folder.
 * It will open this file and parse out the words, in the same way as
 * if AddDataFile() was called.
 *
 * The toLowerCase flag defaults to false. However, if it is set to true
 * then any words read by the file reader will be stored only as lower case.
 */
FileReader::FileReader( string fileName )
{
  this->doLowerCase = false;

  AddDataFile( fileName );
}

/**
 * This takes in a word, then loops through each char in that word,
 * stripping out punctuation.
 */
void FileReader::CleanWord( string &word )
{
  //Using ASCII code 65-90 (capital letters), and 97-122 (lower case letters).
  //We will keep such letters, and remove all others.
  string temp;

  for(uint i = 0; i < word.length(); i++)
    {
      if( (word[i] >= 65 && word[i] <= 90) || (word[i] >= 97 && word[i] <= 122) )
	{
	  if( doLowerCase == true )
	    {
	      temp.push_back( (char)tolower(word[i]) );
	    }
	  else
	    {
	      temp.push_back( word[i] );
	    }
	}
    }

  //Replace the word with the newly-built temp word.
  word = temp;
}

/**
 * Takes in a string, then using whitespace, it parses each token
 * between whitespace as a word. Words are sent to be cleaned (or
 * in other words, stripped of punctuation), then stored in a vector.
 */
void FileReader::ParseLine ( string line )
{
  //Prepare marks for the start and end of each word
  //separated by whitespace.
  size_t start = 0;
  size_t end = line.find( " ", start);

  string currentWord;

  //While the end value is not the npos (end of line) value...
  while( end != string::npos )
    {
      //Take the word, and send it to be cleaned.
      currentWord = line.substr( start, end );

      CleanWord( currentWord );

      words.push_back( currentWord );

      //Increment to next word.
      start = end + 1;
      end = line.find( " ", start);

      //At the end of file, end of string, we take the word from the next start position to the end of string(npos).
      if(end == string::npos)
	{
	  currentWord =  line.substr( start, end );
	  CleanWord( currentWord );
	  words.push_back( currentWord );
	}
    }

}

/**
 * Takes in a string file name. Opens that file or prints an error.
 * proceeds to read the file line by line to extract the words in the
 * file.
 */
void FileReader::AddDataFile( string fileName )
{
  file = fopen( fileName.c_str(), "r" );

  //Check if file exists, or is found.
  if( file == NULL)
    {
    perror( "ERROR: file not found." );
    exit (1);
    }
  //Read file line by line.
  else
    {
      while( !feof(file) )   //While not end of file.
	{
	  char line[1000];
	  if( fgets(line, 1000, file) != NULL)  //Pull out upto 1000 chars from file and put in line.
	    {
	      ParseLine( line );
	    }
	}
    }
  //Close file.
  fclose( file );
}

/**
 * Simple getter for the list of words parsed by the reader.
 */
vector<string> FileReader::GetWords()
{
  return words;
}
