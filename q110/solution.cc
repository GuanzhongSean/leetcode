#include "TreeNode.h"

namespace q110 {

class Solution {
  bool ans;
  int solve(TreeNode* root) {
    if (!root) return 0;
    int l = solve(root->left);
    int r = solve(root->right);
    if (abs(l - r) > 1) ans = false;
    return max(l, r) + 1;
  }

 public:
  bool isBalanced(TreeNode* root) {
    ans = true;
    solve(root);
    return ans;
  }
};

}  // namespace q110
