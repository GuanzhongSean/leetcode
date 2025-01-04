#ifndef _LIST_NODE_
#define _LIST_NODE_ 1

#include <iostream>
#include <vector>

struct ListNode {
  int val = 0;
  ListNode *next = nullptr;
  ListNode() = default;
  ListNode(int x) : val(x) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
  ListNode(const std::vector<int> &from);
  ~ListNode() { delete next; };
  virtual void print(std::ostream &os = std::cout) const;
};

std::ostream &operator<<(std::ostream &os, const ListNode *node);

#endif
