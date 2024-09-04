#include "TreeNode.h"

namespace q113 {

class Solution {
  vector<vector<int>> result;
  vector<int> cur;
  void solve(TreeNode* root, int targetSum) {
    if (!root) return;
    cur.push_back(root->val);
    if (!root->left && !root->right && targetSum == root->val) {
      result.push_back(cur);
    } else {
      solve(root->left, targetSum - root->val);
      solve(root->right, targetSum - root->val);
    }
    cur.pop_back();
  }

 public:
  vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    result.clear();
    cur.clear();
    solve(root, targetSum);
    return result;
  }
};

}  // namespace q113
