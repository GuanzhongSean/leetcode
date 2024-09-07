#include <queue>

#include "Node.h"

namespace q117 {

using namespace std;

class Solution {
 public:
  Node* connect(Node* root) {
    if (root) {
      queue<Node*> q;
      q.push(root);
      while (!q.empty()) {
        Node* prev = nullptr;
        const int n = q.size();
        for (int i = 0; i < n; i++) {
          Node* cur = q.front();
          q.pop();
          if (prev) prev->next = cur;
          if (cur->left) q.push(cur->left);
          if (cur->right) q.push(cur->right);
          prev = cur;
        }
      }
    }
    return root;
  }
};

}  // namespace q117
