#include "Utils.h"
#include "solution.cc"

int main() {
  TreeNode* root = new TreeNode({3, 9, 20, TreeNode::null, TreeNode::null, 15, 7});
  print(root);
  auto result = q107::Solution().levelOrderBottom(root);
  print(result);
  delete root;
}