/**
 * Main.c
 *
 * Team: Reality Version 2
 * Authors: Adam Nieman & Victor Siu
 *
 * The main method for running the Docutment Analysis program. This program
 * accepts the following parameters:
 * '-d' :A flag to indicate that the next argument is a filename that is to be
 *       used as a base dictionary for the analysis.
 * '-n' :The next argument is the total number of 'n' most commonly used words in the analyzed document.
 * '-c' :The list of arguments following this flag are the filenames of documentsa we wish to
 *       spell-check and analyze. If this flag is missing, then there will be an error.
 */

#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <string>
#include <vector>
#include "Dictionary.h"
#include "Word_Count.h"
#include "FileWriter.h"
#include "FileReader.h"

using namespace std;

int
main( int arg_count, char* arg_list[] )
{
  bool CFlagExists = false;
  bool verbose = false;                 //The flag that allows debugging messages.
  string dictionaryFileName = "words";  //Default dictionary file name.
  vector<string> fileNamesToCheck;      //Empty list of file names to be checked / analyzed.
  int numberTopWords = 50;              //Default number of top words.

  //Loop through the list of srguments until we find one of the appropriate flags.
  for(uint i = 1; i < (uint)arg_count; i++)
    {
      string currentArg = arg_list[i];

      //Check for a flag.
      if( currentArg.compare( "-d" ) == 0 )
	{
	  //Add the next argument as the file name for the dictionary.
	  dictionaryFileName = arg_list[i + 1];
	  i++;
	}
      else if( currentArg.compare( "-c" ) == 0 )
	{
	  CFlagExists = true;
	  i++;

	  //Loop through the next few arguments for file names.
	  //Stop the loop at end of arg list or next flag.
	  for(uint j = i; j < (uint)arg_count; j++, i++)
	    {
	      currentArg = arg_list[j];

	      //If the current argument is a new flag, break the loop, move on.
	      if( (currentArg.compare( "-d" ) == 0) || (currentArg.compare( "-n" ) == 0) )
		break;

	      fileNamesToCheck.push_back( currentArg );
	    }
	}
      else if( currentArg.compare( "-n" ) == 0 )
	{
	  numberTopWords = atoi( arg_list[i + 1] );  //the "atoi" function will read the string (char array) as an int.
	  i++;
	}
      else if( currentArg.compare( "-v" ) == 0 )
	{
	  verbose = true;
	}
      else
	{
	  cout << "ERROR: Unknown option.\n" << endl;
	  cout << "Options include: '-d': dictionary filename. '-n': number of top words. '-c':documents to anaylze." << endl;
	  cout << "EXAMPLE: -d dictionary.txt -n 50 -c analyzeMe.txt analyzeMeToo.txt" << endl;
	  exit(0);
	}
    }

  if(!CFlagExists)
    {
      cout << "ERROR: The '-c' flag is necessary.\n" << endl;
      cout << "Options include: '-d': dictionary filename. '-n': number of top words. '-c':documents to anaylze." << endl;
      cout << "EXAMPLE: -d dictionary.txt -n 50 -c analyzeMe.txt analyzeMeToo.txt" << endl;
      exit(0);
    }

  if(verbose)
    {
      cout << endl;
      cout << "Dictionary File: " << dictionaryFileName << endl;
      cout << "Number of Top Words: " << numberTopWords << endl;
      for(uint i = 0; i < fileNamesToCheck.size(); i++)
	{
	  cout << "File Name to Analyze: " << fileNamesToCheck[i] << endl;
	}
    }

  //CREATE THE DICTIONARY
  Dictionary dictionary( dictionaryFileName );

  //CREATE THE WORD-COUNT OBJECT
  Word_Count wordCount;

  //CREATE THE WRITE-FILE
  FileWriter writeMe;

  //CREATE THE FILE-READER (to hold a file to analyze)
  //Loop through each file name given.
  for(uint i = 0; i < fileNamesToCheck.size(); i++)
    {
      FileReader currentFile( fileNamesToCheck[i] );
      int totalWordCount = 0;

      //Collection of words in the analyze file.
      vector<string> analyzeThis = *currentFile.ProcessFile();

      //INTERACT WITH WORD COUNT
      //Add each word to the word count.
      for(uint j = 0; j < analyzeThis.size(); j++)
	{
	  wordCount.add_word(analyzeThis[i]);
	}

      //COLLECT TOTAL WORDS IN FILE
      totalWordCount = analyzeThis.size();

      //COLLECT TOP-USED WORDS IN FILE
      vector<string> topUsedWords;    //To hold the words counted.
      vector<int> topUsedWordsCount;  //To hold the count for each top word.

      wordCount.get_top_words( topUsedWords, topUsedWordsCount, numberTopWords );

      //COLLECT SPELLING DATA
      vector<string> misspelledWords; //To hold the misspelled words data.
      
      for(int j = 0; j < totalWordCount; j++)
	{
	  //Find number of misspelled words.
	  if( !dictionary.spelled_correctly( analyzeThis[j] ) )
	    {
	      misspelledWords.push_back( analyzeThis[j] );
	    }
	}

      vector<string> *suggestions;
      suggestions = new vector<string>[misspelledWords.size()];

      //Collect sets of suggestions for each word.
      for(uint j = 0; j < suggestions->size(); j++)
	{
	  dictionary.best_matches( misspelledWords[j], suggestions[j], 5 );
	}

      //DEBUG CHECK
      if(verbose)
	{
	  cout << "FileNameChecked: \t\t" << fileNamesToCheck[i] << endl;
	  cout << "Total Word Count: \t\t" << totalWordCount << endl;
	  cout << "Number of Top Used Words: \t\t" << topUsedWords.size() << endl;
	  cout << "Number of Top Used Words Count: \t\t" << topUsedWordsCount.size() << endl;
	  cout << "Number of Misspelled Words: \t\t" << misspelledWords.size() << endl;
	}

      //LIST OF DATA WE HAVE COLLECTED:
      //fileNamesToCheck   (string)
      //totalWordCount     (int)
      //topUsedWords       (vector<string>)
      //topUsedWordsCount  (vector<int>)
      //misspelledWords    (vector<string>)
      //suggestions        (array vector<string>)

      //APPEND DATA TO FILE-WRITER
      //writeMe.append( fileNamesToCheck[i], totalWordCount, topUsedWords, topUsedWordsCount, misspelledWords, suggestions );
    }
}
