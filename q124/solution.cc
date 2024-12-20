#include <algorithm>

#include "TreeNode.h"
#include "utils.h"

namespace q124 {

using namespace std;

class Solution {
  pair<int, int> dfs(TreeNode* root) {
    if (!root) {
      return {0, INT_MIN};
    }
    auto [leftMax, leftMaxPath] = dfs(root->left);
    auto [rightMax, rightMaxPath] = dfs(root->right);

    int maxPathThroughRoot = leftMax + rightMax + root->val;
    int maxPath = max({leftMaxPath, rightMaxPath, maxPathThroughRoot, root->val});
    int maxSum = max(0, max(leftMax, rightMax) + root->val);
    return {maxSum, maxPath};
  }

 public:
  int maxPathSum(TreeNode* root) { return dfs(root).second; }
};

}  // namespace q124
