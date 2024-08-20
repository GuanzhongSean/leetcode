#include "utils.h"

using namespace std;

class Solution {
 public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (!head) return NULL;
    int l = 1;
    ListNode *curr = head;
    while (curr->next) {
      curr = curr->next;
      l++;
    }

    curr->next = head;
    k = k % l;
    int x = l - k;
    while (curr->next && x--) curr = curr->next;
    head = curr->next;
    curr->next = NULL;
    return head;
  }
};

int main() {
  ListNode *ln = new ListNode{0, new ListNode{1, new ListNode{2}}};
  cout << Solution().rotateRight(ln, 2) << endl;
}
