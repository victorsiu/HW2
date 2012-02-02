#include <string>

using namespace std;

class Word
{
 private:
  int count; //how many times the word appears in the book
 public:
  Word(string data); //constructor
  void incrementCount(); //increment the count
  string data; //the actual word
};
