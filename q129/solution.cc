#include "TreeNode.h"

namespace q129 {

using namespace std;

class Solution {
  int sum{0};
  void helper(TreeNode* root, int cur) {
    if (!root) return;
    cur = cur * 10 + root->val;
    if (!root->left && !root->right) {
      sum += cur;
      return;
    }

    helper(root->left, cur);
    helper(root->right, cur);
  }

 public:
  int sumNumbers(TreeNode* root) {
    sum = 0;
    helper(root, 0);
    return sum;
  }
};

}  // namespace q129
