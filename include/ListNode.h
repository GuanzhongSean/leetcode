#ifndef _LIST_NODE_
#define _LIST_NODE_ 1

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val = 0;
  ListNode *next = nullptr;
  ListNode(int x) : val(x) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
  ListNode(vector<int> from);
  ~ListNode() { delete next; };
  void print();
};

ostream &operator<<(ostream &os, ListNode *node);

#endif
