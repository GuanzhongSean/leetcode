#include "Utils.h"
#include "solution.cc"

int main() {
  ListNode *head = new ListNode({-10, -3, 0, 5, 9});
  auto result = q109::Solution().sortedListToBST(head);
  print(result);
  delete result;
  delete head;
}