#include <string>
using namespace std;

class AVLNode
{
 public:
  AVLNode(string* data);
  AVLNode(string* data, AVLNode* left, AVLNode* right);
  ~AVLNode();
  AVLNode* parent; // do we need to initialize these before
  // setting them to what is passed in?
  AVLNode* leftChild;
  AVLNode* rightChild;
  string* data;
  int height;
};

