#include <gtest/gtest.h>

#include "Utils.h"
#include "solution.cc"

constexpr auto null = TreeNode::null;

int main() {
	TreeNode* root = new TreeNode({4, 9, 0, 5, 1});
	print(root);
	auto result = q129::Solution().sumNumbers(root);
	print(result);
	EXPECT_EQ(result, 1026);
	delete root;
}
