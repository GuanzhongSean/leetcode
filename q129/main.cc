#include <gtest/gtest.h>

#include "solution.cc"
#include "utils.h"

constexpr auto null = TreeNode::null;

int main() {
  TreeNode* root = new TreeNode({4,9,0,5,1});
  print(root);
  auto result = q129::Solution().sumNumbers(root);
  print(result);
  EXPECT_EQ(result, 1026);
}
