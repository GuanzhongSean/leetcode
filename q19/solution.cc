#include <stack>
#include "../include/ListNode.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<int> container;
        while (head) {
          container.push(head->val);
          head = head->next;
        }
        int sz = container.size();
        while (container.size()) {
          if (container.size() + n - 1 != sz)
            head = new ListNode{container.top(), head};
          container.pop();
        }
        return head;
    }
};

int main() {
    Solution s;
    ListNode* ln = new ListNode{1, new ListNode{3, new ListNode{4}}};
    auto result = s.removeNthFromEnd(ln, 1);
    result->print();
    delete ln;
    delete result;
}
