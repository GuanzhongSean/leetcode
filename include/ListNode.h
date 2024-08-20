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
  ListNode(vector<int> from);
  ~ListNode() { delete next; };
  void print();
};

ostream &operator<<(ostream &os, ListNode *node);

#endif
