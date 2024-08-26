#include "utils.h"

namespace q100 {

class Solution {
 public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    return p == q ||
           (p && q && p->val == q->val && isSameTree(p->left, q->left) &&
            isSameTree(p->right, q->right));
  }
};

class Solution0 {
 public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    return p == q || (p && p->equals(q));
  }
};

}  // namespace q100

int main() {
  TreeNode* p = new TreeNode({1, 2, 3});
  TreeNode* q = new TreeNode({1, 2, 3});
  auto result = q100::Solution().isSameTree(p, q);
  print(result);
  delete p;
  delete q;
}
