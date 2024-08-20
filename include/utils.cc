#include "utils.h"

template <typename T>
void print(vector<T> v) {
  for (T i : v) {
    cout << i << " ";
  }
  cout << endl;
}

template <typename T>
inline ostream &operator<<(ostream &os, vector<T> v) {
  for (T i : v) os << i << " ";
  return os << endl;
}