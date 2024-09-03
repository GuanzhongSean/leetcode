#include "solution.cc"
#include "utils.h"

int main() {
  TreeNode *root =
      new TreeNode({3, 9, 20, TreeNode::null, TreeNode::null, 15, 7});
  print(root);
  auto result = q110::Solution().isBalanced(root);
  print(result);
  delete root;
}