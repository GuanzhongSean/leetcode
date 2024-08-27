#include "utils.h"

namespace q101 {

class Solution {
  bool isSymmetric(TreeNode* left, TreeNode* right) {
    if (!left && !right) return true;
    if (!left || !right) return false;
    return left->val == right->val && isSymmetric(left->left, right->right) &&
           isSymmetric(left->right, right->left);
  }

 public:
  bool isSymmetric(TreeNode* root) {
    return !root || isSymmetric(root->left, root->right);
  }
};

}  // namespace q101

int main() {
  TreeNode* root = new TreeNode({1, 2, 2, 3, 4, 4, 3});
  print(root);
  auto result = q101::Solution().isSymmetric(root);
  print(result);
  delete root;
}
