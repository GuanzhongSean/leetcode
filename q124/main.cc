#include <gtest/gtest.h>

#include "solution.cc"

constexpr auto null = TreeNode::null;

int main() {
  TreeNode* root = new TreeNode(-3);
  auto result = q124::Solution().maxPathSum(root);
  print(result);
  EXPECT_EQ(result, -3);
}
