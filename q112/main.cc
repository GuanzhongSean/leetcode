#include "solution.cc"
#include "utils.h"

int main() {
  TreeNode *root =
      new TreeNode({5, 4, 8, 11, TreeNode::null, 13, 4, 7, 2, TreeNode::null,
                    TreeNode::null, TreeNode::null, 1});
  print(root);
  auto result = q112::Solution().hasPathSum(root, 22);
  print(result);
  delete root;
}
