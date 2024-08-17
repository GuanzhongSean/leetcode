#ifndef _LIST_NODE_
#define _LIST_NODE_ 1

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
  ~ListNode() { delete next; };
  void print() {
    cout << val << " ";
    if (next)
      next->print();
    else
      cout << endl;
  }
};

inline ListNode *generateList(vector<int> from) {
  ListNode *head = nullptr, *cur = nullptr;
  for (int i : from) {
    if (!head) {
      head = new ListNode(i);
      cur = head;
      continue;
    }
    cur->next = new ListNode(i);
    cur = cur->next;
  }
  return head;
}

inline ostream &operator<<(ostream &os, ListNode *node) {
  if (node == nullptr) return os << "nullptr";
  return os << node->val << " " << node->next;
}

#endif
