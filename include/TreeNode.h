#ifndef _TREE_NODE_
#define _TREE_NODE_ 1

#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
  int val = 0;
  TreeNode *left = nullptr;
  TreeNode *right = nullptr;

  enum Sentinel { null = INT_MIN };

  TreeNode() : val(0) {}
  TreeNode(int x) : val(x) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
  TreeNode(vector<int> from);
  ~TreeNode() {
    delete left;
    delete right;
  };
  void print(ostream &os = cout, const string &prefix = "", bool isLeft = true);
  bool equals(TreeNode *other) {
    return this == other ||
           (other && val == other->val && left->equals(other->left) &&
            right->equals(other->right));
  }
};

ostream &operator<<(ostream &os, TreeNode *node);

#endif
