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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(), * temp = head;
        while(list1 && list2){
            if(list1->val < list2->val){
                head->next = list1;
                list1 = list1->next;
            }
            else {
                head->next = list2;
                list2 = list2->next;                
            }
            head = head->next;
        }
        if(list1)
            head->next = list1;
        if(list2)
            head->next = list2;
        head = temp;
        temp = temp->next;
        head->next = nullptr;
        delete head;
        return temp;
    }
};

int main() {
    Solution s;
    ListNode* ln1 = new ListNode{5};
    ListNode* ln2 = new ListNode{-1, new ListNode{2, new ListNode{4, new ListNode{4}}}};
    auto result = s.mergeTwoLists(ln1, ln2);
    result->print();
    delete result;
}
