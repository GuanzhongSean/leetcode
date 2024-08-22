#include "ListNode.h"

ListNode::ListNode(vector<int> from) {
  if (from.empty()) return;
  val = from[0];
  ListNode *cur = this;
  for (int i = 1; i < from.size(); i++) {
    cur->next = new ListNode(from[i]);
    cur = cur->next;
  }
}

void ListNode::print() {
  cout << val << " ";
  if (next)
    next->print();
  else
    cout << endl;
}

ostream &operator<<(ostream &os, ListNode *node) {
  if (!node) return os << endl;
  return os << node->val << " " << node->next;
}