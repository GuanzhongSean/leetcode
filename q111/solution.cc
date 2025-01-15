#include "TreeNode.h"

namespace q111 {

class Solution {
   public:
	int minDepth(TreeNode* root) {
		if (!root) return 0;
		int left = minDepth(root->left);
		int right = minDepth(root->right);
		if (!right || !left) return std::max(left, right) + 1;
		return std::min(left, right) + 1;
	}
};

}  // namespace q111
