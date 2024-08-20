#include "ListNode.h"

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, bool plus_one = false) {
    if (!l1 && !l2) {
      if (plus_one) {
        return new ListNode(1);
      } else {
        return nullptr;
      }
    }
    unsigned short digit;
    ListNode *next_l1, *next_l2;
    if (!l1) {
      digit = l2->val + plus_one;
      next_l1 = nullptr;
      next_l2 = l2->next;
    } else if (!l2) {
      digit = l1->val + plus_one;
      next_l1 = l1->next;
      next_l2 = nullptr;
    } else {
      digit = l1->val + l2->val + plus_one;
      next_l1 = l1->next;
      next_l2 = l2->next;
    }
    if (digit >= 10) {
      return new ListNode(digit - 10, addTwoNumbers(next_l1, next_l2, true));
    } else {
      return new ListNode(digit, addTwoNumbers(next_l1, next_l2));
    }
  }
};

int main() {
  // ListNode* l1 = new ListNode{2, new ListNode{4, new ListNode{3}}};
  // ListNode* l1 = new ListNode{0};
  ListNode* l1 = new ListNode{9, new ListNode{9, new ListNode{9}}};
  // ListNode* l2 = new ListNode{5, new ListNode{6, new ListNode{4}}};
  // ListNode* l2 = new ListNode{0};
  ListNode* l2 = new ListNode{9, new ListNode{9}};
  Solution s;
  ListNode* result = s.addTwoNumbers(l1, l2);
  result->print();
  delete l1;
  delete l2;
  delete result;
}
