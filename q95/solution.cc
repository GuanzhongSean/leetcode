#include <unordered_map>

#include "utils.h"

namespace q95 {

class Solution {
  unordered_map<pair<int, int>, vector<TreeNode*>, NodeHash> umap;
  vector<TreeNode*> generateTrees(int start, int end) {
    if (start > end) return {nullptr};
    if (umap.find({start, end}) != umap.end()) return umap[{start, end}];

    vector<TreeNode*> result;
    for (int i = start; i <= end; i++) {
      vector<TreeNode*> left = generateTrees(start, i - 1);
      vector<TreeNode*> right = generateTrees(i + 1, end);
      for (TreeNode* l : left) {
        for (TreeNode* r : right) {
          TreeNode* root = new TreeNode(i);
          root->left = l;
          root->right = r;
          result.push_back(root);
        }
      }
    }

    umap[{start, end}] = result;
    return result;
  }

 public:
  vector<TreeNode*> generateTrees(int n) {
    if (n == 0) return {};
    return generateTrees(1, n);
  }
};

}  // namespace q95

int main() {
  auto result = q95::Solution().generateTrees(3);
  print(result);
  for (TreeNode* tree : result) delete tree;
}
