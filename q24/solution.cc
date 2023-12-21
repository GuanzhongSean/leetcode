#include "../include/ListNode.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* cur = head;
        ListNode* prev = nullptr;
        head = head->next;
        while (cur && cur ->next) {
            ListNode* tmp = cur->next->next;
            if (prev) prev->next = cur->next;
            cur->next->next = cur;
            cur->next = tmp;
            prev = cur;
            cur = tmp;
        }
        return head;
    }
};

int main() {
    Solution s;
    auto head = new ListNode{1, new ListNode{2, new ListNode{3, new ListNode{4}}}};
    auto result = s.swapPairs(head);
    if (result) result->print();
    delete result;
}
