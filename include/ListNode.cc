#include "ListNode.h"

ListNode::ListNode(const vector<int> &from) {
  if (from.empty()) return;
  val = from[0];
  ListNode *cur = this;
  for (int i = 1; i < from.size(); i++) {
    cur->next = new ListNode(from[i]);
    cur = cur->next;
  }
}

void ListNode::print(ostream &os) const {
  os << val << " ";
  if (next)
    next->print();
  else
    os << endl;
}

ostream &operator<<(ostream &os, const ListNode *node) {
  if (node) node->print(os);
  return os;
}