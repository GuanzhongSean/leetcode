#include <vector>

#include "../include/ListNode.h"

class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (k == 1) return head;
    ListNode* result = head;
    ListNode* prev = nullptr;
    vector<ListNode*> group{};
    while (head) {
      group.emplace_back(head);
      head = head->next;
      if (group.size() == k) {
        int l = 0, r = k - 1;
        if (prev)
          prev->next = group[r];
        else
          result = group[r];
        prev = group[0];
        group[0]->next = head;
        for (int i = 1; i < k; i++) {
          group[i]->next = group[i - 1];
        }
        group.clear();
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  auto head = generateList(vector<int>{1, 2, 3, 4, 5, 6, 7});
  auto result = s.reverseKGroup(head, 3);
  if (result) result->print();
  delete result;
}
