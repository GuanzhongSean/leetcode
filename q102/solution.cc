#include "TreeNode.h"

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
