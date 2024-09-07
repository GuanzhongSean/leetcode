#include "solution.cc"
#include "utils.h"

int main() {
  Node* root = new Node({1, 2, 3, 4, 5, Node::null, 7});
  print(root);
  auto result = q117::Solution().connect(root);
  print(result);
  delete root;
}
