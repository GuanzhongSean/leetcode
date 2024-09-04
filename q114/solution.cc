#include <stack>

#include "TreeNode.h"

namespace q114 {

class Solution {
 public:
  void flatten(TreeNode* root) {
    if (!root) return;

    TreeNode* cur = root;
    stack<TreeNode*> stk;
    if (root->right) stk.push(root->right);
    if (root->left) stk.push(root->left);
    while (!stk.empty()) {
      TreeNode* next = stk.top();
      stk.pop();
      cur->left = nullptr;
      cur->right = next;
      cur = next;

      if (next->right) stk.push(next->right);
      if (next->left) stk.push(next->left);
    }
  }
};

class Solution2 {
 private:
  TreeNode* prev;
  void flattenHelper(TreeNode* node) {
    if (!node) return;

    flattenHelper(node->right);
    flattenHelper(node->left);

    node->right = prev;
    node->left = nullptr;
    prev = node;
  }

 public:
  void flatten(TreeNode* root) {
    prev = nullptr;
    flattenHelper(root);
  }
};

}  // namespace q114
