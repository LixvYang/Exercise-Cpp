#ifndef TREE
#define TREE
#include <string>
using std::string;

class TreeNode
{
public:
  explicit TreeNode(): value(string()), count(new int(1)), left(nullptr), right(nullptr) {}
  TreeNode(const TreeNode& rhs): value(rhs.value), count(rhs.count), left(rhs.left), right(rhs.right) {++*count;}
  TreeNode& operator=(const TreeNode& rhs);
  ~TreeNode()
  {
    if (--*count == 0)
    {
      if (left)
      {
        delete left;
        left = nullptr;
      }
      if (right)
      {
        delete right;
        right = nullptr;
      }
      delete count;
      count = nullptr;
    }
  };

private:
  std::string value;
  int *count;
  TreeNode *left;
  TreeNode *right;
};

TreeNode& TreeNode::operator=(const TreeNode &rhs)
{
  ++*rhs.count;
  if(--*count == 0)
  {
    if (left)
    {
      delete left;
    }
    if (right)
    {
      delete right;
    }
    delete count;
  }
  value = rhs.value;
  left = rhs.left;
  right = rhs.right;
  count = rhs.count;
  return *this;
}



#endif
