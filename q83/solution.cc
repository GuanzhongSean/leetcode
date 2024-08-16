#include "../include/ListNode.h"

using namespace std;

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while (curr) {
      if (prev && prev->val == curr->val) {
        prev->next = curr->next;
        curr->next = nullptr;
        delete curr;
      } else {
        prev = curr;
      }
      curr = prev->next;
    }
    return head;
  }
};

int main() {
  ListNode *head =
      new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3))));
  ListNode *result = Solution().deleteDuplicates(head);
  result->print();
  delete result;
}
