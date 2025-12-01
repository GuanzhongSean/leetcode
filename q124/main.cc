#include "solution.cc"

constexpr auto null = TreeNode::null;

int main() {
	TreeNode* root = new TreeNode({-10,9,20,null,null,15,7});
	print(root);
	auto result = q124::Solution().maxPathSum(root);
	print(result);
	EXPECT_EQ(result, 42);
}
