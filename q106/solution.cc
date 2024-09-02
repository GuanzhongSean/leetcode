#include <stack>
#include <unordered_map>

#include "utils.h"

namespace q106 {

class Solution {
 public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int> map;
    stack<pair<int, TreeNode*>> stk;
    for (int i = 0; i < inorder.size(); i++) map[inorder[i]] = i;

    TreeNode* root = new TreeNode(postorder.back());
    TreeNode* parent = root;
    stk.push({map[postorder.back()], parent});
    for (int i = postorder.size() - 2; i >= 0; i--) {
      TreeNode* node = new TreeNode(postorder[i]);
      int index = map[postorder[i]];
      if (index > stk.top().first) {
        parent = stk.top().second;
        parent->right = node;
      } else {
        while (!stk.empty() && index < stk.top().first) {
          parent = stk.top().second;
          stk.pop();
        }
        parent->left = node;
      }
      stk.push({index, node});
    }
    return root;
  }
};

}  // namespace q106

int main() {
  vector<int> inorder{9, 3, 15, 20, 7};
  vector<int> postorder{9, 15, 7, 20, 3};
  auto result = q106::Solution().buildTree(inorder, postorder);
  print(result);
  delete result;
}
