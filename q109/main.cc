#include "solution.cc"
#include "utils.h"

int main() {
  ListNode *head = new ListNode({-10, -3, 0, 5, 9});
  auto result = q109::Solution().sortedListToBST(head);
  print(result);
  delete result;
  delete head;
}