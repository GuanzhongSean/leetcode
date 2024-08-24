#ifndef _MY_UTILS_
#define _MY_UTILS_ 1

#include "ListNode.h"
#include "TreeNode.h"

inline void print(ListNode *head) {
  if (head) head->print();
}

inline void print(TreeNode *root) {
  if (root) root->print();
}

template <typename T, typename... Args>
void print(const T &first, const Args &...args) {
  if constexpr (sizeof...(args) > 0) {
    cout << first << " ";
    print(args...);
  } else {
    cout << first << endl;
  }
}

template <typename T>
ostream &operator<<(ostream &os, vector<T> v) {
  os << "[";
  for (int i = 0; i < v.size(); i++)
    os << v[i] << (i == v.size() - 1 ? "" : " ");
  return os << "]" << endl;
}

template <typename T>
inline void print(vector<T> v) {
  cout << v;
}

#endif
