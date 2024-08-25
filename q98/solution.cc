#include "utils.h"

namespace q98 {

class Solution {
  bool isValidBST(TreeNode* root, TreeNode* min, TreeNode* max) {
    if (!root) return true;
    if ((min && root->val <= min->val) || (max && root->val >= max->val))
      return false;
    return isValidBST(root->left, min, root) &&
           isValidBST(root->right, root, max);
  }

 public:
  bool isValidBST(TreeNode* root) { return isValidBST(root, nullptr, nullptr); }
};

}  // namespace q98

int main() {
  TreeNode* root =
      new TreeNode({5, 4, 6, TreeNode::null, TreeNode::null, 3, 7});
  print(root);
  auto result = q98::Solution().isValidBST(root);
  print(result);
  delete root;
}
