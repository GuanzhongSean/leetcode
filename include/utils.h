#ifndef _MY_UTILS_
#define _MY_UTILS_ 1

#include "ListNode.h"

void print(ListNode *head);

template <typename T>
void print(const T &arg, string delimiter = " ") {
  cout << arg << delimiter;
}

template <typename T, typename... Args>
void print(const T &first, const Args &...args) {
  print(first);
  print(args...);
  if constexpr (sizeof...(args) == 1) cout << endl;
}

template <typename T>
void print(vector<T> v) {
  cout << "[";
  for (T i : v) print(i);
  cout << "]" << endl;
}

template <typename T>
ostream &operator<<(ostream &os, vector<T> v) {
  for (T i : v) os << i << " ";
  return os << endl;
}

#endif
