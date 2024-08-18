#include "../include/ListNode.h"

using namespace std;

class Solution {
 public:
  ListNode* partition(ListNode* head, int x) {
    ListNode* left = new ListNode(0);
    ListNode* right = new ListNode(0);
    ListNode* left_head = left;
    ListNode* right_head = right;
    while (head) {
      if (head->val < x) {
        left->next = head;
        left = left->next;
      } else {
        right->next = head;
        right = right->next;
      }
      head = head->next;
    }
    right->next = nullptr;
    left->next = right_head->next;
    ListNode* result = left_head->next;

    left_head->next = nullptr;
    delete left_head;
    right_head->next = nullptr;
    delete right_head;

    return result;
  }
};

int main() {
  ListNode* head = new ListNode(
      1, new ListNode(
             4, new ListNode(
                    3, new ListNode(2, new ListNode(5, new ListNode(2))))));
  ListNode* result = Solution().partition(head, 3);
  result->print();
  delete head;
}
