#include "TreeNode.h"

TreeNode::TreeNode(vector<int> from) {
  if (from.empty()) return;
  val = from[0];
  queue<TreeNode *> nodeQueue;
  nodeQueue.push(this);

  int i = 1;
  while (i < from.size()) {
    TreeNode *current = nodeQueue.front();
    nodeQueue.pop();

    if (from[i] != TreeNode::null) {
      current->left = new TreeNode(from[i]);
      nodeQueue.push(current->left);
    }
    i++;

    if (i < from.size() && from[i] != TreeNode::null) {
      current->right = new TreeNode(from[i]);
      nodeQueue.push(current->right);
    }
    i++;
  }
}

void TreeNode::print(ostream &os, const string &prefix, bool isLeft) {
  if (right) right->print(os, prefix + (isLeft ? "│   " : "    "), false);
  os << prefix << (isLeft ? "└── " : "┌── ") << val << endl;
  if (left) left->print(os, prefix + (isLeft ? "    " : "│   "), true);
}

ostream &operator<<(ostream &os, TreeNode *node) {
  if (node) node->print(os);
  return os;
}
