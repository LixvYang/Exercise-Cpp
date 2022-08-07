#ifndef BIN_STR_TREE
#define BIN_STR_TREE

#include "tree.h"
#include <string>
using std::string;

class BinStrTree
{
public:
  BinStrTree() : root(new TreeNode()) {}
  BinStrTree(const BinStrTree &bst) : root(new TreeNode(*bst.root)) {}
  BinStrTree& operator=(const BinStrTree &bst);
  ~BinStrTree() {delete root;}
    
private:
  TreeNode *root;
};

BinStrTree& BinStrTree::operator=(const BinStrTree &bst)
{
  TreeNode *new_root = new TreeNode(*bst.root);
  delete root;
  root = new_root;
  return *this;
}

#endif
