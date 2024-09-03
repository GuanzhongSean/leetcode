#include "solution.cc"
#include "utils.h"

int main() {
  TreeNode *root = new TreeNode({2, TreeNode::null, 3, TreeNode::null, 4,
                                 TreeNode::null, 5, TreeNode::null, 6});
  print(root);
  auto result = q111::Solution().minDepth(root);
  print(result);
  delete root;
}