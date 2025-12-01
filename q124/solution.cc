#include "Utils.h"

namespace q124 {

using namespace std;

namespace V1 {
class Solution {
	pair<int, int> dfs(TreeNode* root) {
		if (!root) return {0, INT_MIN};
		auto [leftMax, leftMaxPath] = dfs(root->left);
		auto [rightMax, rightMaxPath] = dfs(root->right);

		int maxPathThroughRoot = leftMax + rightMax + root->val;
		int maxPath = max({leftMaxPath, rightMaxPath, maxPathThroughRoot});
		int maxSum = max(0, max(leftMax, rightMax) + root->val);
		return {maxSum, maxPath};
	}

   public:
	int maxPathSum(TreeNode* root) { return dfs(root).second; }
};
}  // namespace V1

inline namespace V2 {
class Solution {
	int maxPath = INT_MIN;
	int dfs(TreeNode* root) {
		if (!root) return 0;
		int leftMax = dfs(root->left);
		int rightMax = dfs(root->right);

		int maxPathThroughRoot = leftMax + rightMax + root->val;
		maxPath = max(maxPath, maxPathThroughRoot);
		return max(0, max(leftMax, rightMax) + root->val);
	}

   public:
	int maxPathSum(TreeNode* root) {
		dfs(root);
		return maxPath;
	}
};
}  // namespace V2

}  // namespace q124
