#include "TreeNode.h"

namespace q111 {

class Solution {
 public:
  int minDepth(TreeNode* root) {
    if (!root) return 0;
    int left = minDepth(root->left);
    int right = minDepth(root->right);
    if (!right || !left) return max(left, right) + 1;
    return min(left, right) + 1;
  }
};

}  // namespace q111
