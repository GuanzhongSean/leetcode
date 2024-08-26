#include "utils.h"

namespace q99 {

class Solution0 {
 public:
  void recoverTree(TreeNode* root) {
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;
    TreeNode* cur = root;
    while (cur) {
      if (!cur->left) {
        if (prev && prev->val > cur->val) {
          if (!first) {
            first = prev;
          }
          second = cur;
        }
        prev = cur;
        cur = cur->right;
      } else {
        TreeNode* pred = cur->left;
        while (pred->right && pred->right != cur) {
          pred = pred->right;
        }
        if (!pred->right) {
          pred->right = cur;
          cur = cur->left;
        } else {
          pred->right = nullptr;
          if (prev && prev->val > cur->val) {
            if (!first) {
              first = prev;
            }
            second = cur;
          }
          prev = cur;
          cur = cur->right;
        }
      }
    }
    if (first && second) {
      swap(first->val, second->val);
    }
  }
};

class Solution {
 public:
  TreeNode* first;
  TreeNode* second;
  TreeNode* pre;

  void recoverTree(TreeNode* root) {
    first = nullptr;
    second = nullptr;
    pre = new TreeNode(INT_MIN);
    TreeNode* tmp = pre;
    inorder(root);
    if (first && second) swap(first->val, second->val);
    delete tmp;
  }

  void inorder(TreeNode* root) {
    if (root == nullptr) return;

    inorder(root->left);

    if (!first && root->val < pre->val) first = pre;
    if (first && root->val < pre->val) second = root;
    pre = root;

    inorder(root->right);
  }
};

}  // namespace q99

int main() {
  TreeNode* root = new TreeNode({1, 3, TreeNode::null, TreeNode::null, 2});
  print(root);
  q99::Solution().recoverTree(root);
  print(root);
  delete root;
}
