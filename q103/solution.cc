#include <queue>

#include "utils.h"

namespace q103 {

class Solution {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);
    bool left_to_right = true;
    while (!q.empty()) {
      int size = q.size();
      vector<int> level(size);
      for (int i = 0; i < size; i++) {
        TreeNode* node = q.front();
        q.pop();
        int index = left_to_right ? i : size - 1 - i;
        level[index] = node->val;
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
      result.push_back(level);
      left_to_right = !left_to_right;
    }
    return result;
  }
};

}  // namespace q103

int main() {
  TreeNode* root =
      new TreeNode({1, 2, 3, 4, TreeNode::null, TreeNode::null, 5});
  print(root);
  auto result = q103::Solution().zigzagLevelOrder(root);
  print(result);
  delete root;
}
