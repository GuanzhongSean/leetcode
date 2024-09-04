#include "solution.cc"
#include "utils.h"

int main() {
  TreeNode *root = new TreeNode({5, 4, 8, 11, TreeNode::null, 13, 4, 7, 2,
                                 TreeNode::null, TreeNode::null, 5, 1});
  print(root);
  auto result = q113::Solution().pathSum(root, 22);
  print(result);
  delete root;
}
