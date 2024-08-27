#include "utils.h"

namespace q102 {

class Solution {
  vector<vector<int>> result;
  void levelOrder(TreeNode* root, int level) {
    if (!root) return;
    if (result.size() <= level) {
      result.push_back({});
    }
    result[level].push_back(root->val);
    levelOrder(root->left, level + 1);
    levelOrder(root->right, level + 1);
  }

 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    result.clear();
    levelOrder(root, 0);
    return result;
  }
};

}  // namespace q102

int main() {
  TreeNode* root =
      new TreeNode({3, 9, 20, TreeNode::null, TreeNode::null, 15, 7});
  print(root);
  auto result = q102::Solution().levelOrder(root);
  print(result);
  delete root;
}
