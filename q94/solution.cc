#include "utils.h"

namespace q94 {

class Solution {
  void inorderTraversal(TreeNode *root, vector<int> &result) {
    if (!root) return;
    inorderTraversal(root->left, result);
    result.push_back(root->val);
    inorderTraversal(root->right, result);
  }

 public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> result;
    inorderTraversal(root, result);
    return result;
  }
};

}  // namespace q94

int main() {
  TreeNode *root = new TreeNode({1, 2, 3, 4, 5, TreeNode::null, 6});
  print(root);
  auto result = q94::Solution().inorderTraversal(root);
  print(result);
  delete root;
}
