#include "solution.cc"
#include "utils.h"

int main() {
  TreeNode *root = new TreeNode({1, 2, 5, 3, 4, TreeNode::null, 6});
  print(root);
  q114::Solution().flatten(root);
  print(root);
  delete root;
}
