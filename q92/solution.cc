#include "utils.h"

namespace q92 {

class Solution {
 public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    if (left == right) return head;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *pre = dummy;
    for (int i = 0; i < left - 1; i++) pre = pre->next;
    ListNode *cur = pre->next;
    for (int i = 0; i < right - left; i++) {
      ListNode *temp = pre->next;
      pre->next = cur->next;
      cur->next = cur->next->next;
      pre->next->next = temp;
    }
    ListNode *result = dummy->next;
    dummy->next = nullptr;
    delete dummy;
    return result;
  }
};

}  // namespace q92

int main() {
  ListNode *head = new ListNode({1, 2, 3, 4, 5});
  auto result = q92::Solution().reverseBetween(head, 2, 4);
  print(result);
  delete head;
}
