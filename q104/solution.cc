#include "utils.h"

namespace q104 {

class Solution {
 public:
  int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }
};

}  // namespace q104

int main() {
  TreeNode* root =
      new TreeNode({3, 9, 20, TreeNode::null, TreeNode::null, 15, 7});
  print(root);
  auto result = q104::Solution().maxDepth(root);
  print(result);
  delete root;
}
