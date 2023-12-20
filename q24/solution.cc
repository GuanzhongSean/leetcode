#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    ~ListNode() {delete next;};
    void print() {
        cout << val << " ";
        if (next) next->print();
        else cout << endl;
    }
};

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
