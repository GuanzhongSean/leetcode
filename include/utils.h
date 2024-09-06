#ifndef _MY_UTILS_
#define _MY_UTILS_ 1

#include <type_traits>

#include "ListNode.h"
#include "TreeNode.h"
#include "Node.h"

struct NodeHash {
  size_t operator()(const pair<int, int> &pair) const {
    return hash<int>()(pair.first) ^ (hash<int>()(pair.second) << 1);
  }
  size_t operator()(const pair<double, double> &pair) const {
    return hash<double>()(pair.first) ^ (hash<double>()(pair.second) << 1);
  }
};

inline void print(ListNode *head) {
  if (head) head->print();
}

inline void print(TreeNode *root) {
  if (root) root->print();
}

inline void print(Node *root) {
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
  string delimiter = is_fundamental<T>::value ? " " : "\n";
  os << "[" << delimiter;
  for (T i : v) os << i << delimiter;
  return os << "]";
}

template <typename T>
inline void print(vector<T> v) {
  cout << v << endl;
}

#endif
