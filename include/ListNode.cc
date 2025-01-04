#include "ListNode.h"

ListNode::ListNode(const std::vector<int> &from) {
    if (from.empty()) return;
    val = from[0];
    ListNode *cur = this;
    for (int i = 1; i < from.size(); i++) {
        cur->next = new ListNode(from[i]);
        cur = cur->next;
    }
}

void ListNode::print(std::ostream &os) const {
    os << "[ (ListNode): " << val << " ";
    ListNode *cur = next;
    while (cur) {
        os << "-> " << cur->val << " ";
        cur = cur->next;
    }
    os << "]" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const ListNode *node) {
    if (node) node->print(os);
    return os;
}