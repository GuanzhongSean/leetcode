#include "solution.cc"
#include "utils.h"

int main() {
  Node* root = new Node({1, 2, 3, 4, 5, 6, 7, 8, 9});
  print(root);
  auto result = q116::Solution().connect(root);
  print(result);
  delete root;
}
