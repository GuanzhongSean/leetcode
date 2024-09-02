#include "../q102/solution.cc"

#include <algorithm>

#include "TreeNode.h"

namespace q107 {

class Solution {
 public:
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> result = q102::Solution().levelOrder(root);
    reverse(result.begin(), result.end());
    return result;
  }
};

}  // namespace q107
