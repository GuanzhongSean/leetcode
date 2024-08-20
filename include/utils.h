#ifndef _MY_UTILS_
#define _MY_UTILS_ 1

#include "ListNode.h"

template <typename T>
void print(vector<T> v) {
  for (T i : v) cout << i << " ";
  cout << endl;
}

void print(ListNode *head);

template <typename T>
inline ostream &operator<<(ostream &os, vector<T> v) {
  for (T i : v) os << i << " ";
  return os << endl;
}

#endif
