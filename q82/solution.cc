#include "../include/ListNode.h"
#include <map>

using namespace std;

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *prev = nullptr;
    ListNode *curr = head;
    ListNode *new_head = nullptr;
    while (curr) {
      if (curr->next && curr->val == curr->next->val) {
        while (curr->next && curr->val == curr->next->val) {
          curr = curr->next;
        }
        if (prev) {
          prev->next = curr->next;
        }
      } else {
        if (new_head == nullptr) {
          new_head = curr;
        }
        prev = curr;
      }
      curr = curr->next;
    }
    return new_head;
  }
};

class Solution2 {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    map<int, int> umap;
    for (auto curr = head; curr; curr = curr->next)
      umap[curr->val]++;

    if (umap.size() == 0)
      return nullptr;

    ListNode dummy = ListNode(101);
    ListNode *d = &dummy;
    for (auto [val, count] : umap) {
      if (count == 1) {
        ListNode *node = new ListNode(val);
        d->next = node;
        d = node;
      }
    }

    ListNode *result = dummy.next;
    dummy.next = nullptr;
    return result;
  }
};

int main() {
  ListNode *head = new ListNode(
      1,
      new ListNode(
          1,
          new ListNode(
              3, new ListNode(
                     3, new ListNode(4, new ListNode(4, new ListNode(5)))))));
  ListNode *result = Solution().deleteDuplicates(head);
  result->print();
  delete head;
}
