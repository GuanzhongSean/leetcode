#include "../include/utils.h"

using namespace std;

class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    if (k == 0 || n < k)
      return {};
    if (n == k) {
      vector<int> v{};
      for (int i = 1; i <= n; i++)
        v.push_back(i);
      return {v};
    }
    if (k == 1) {
      vector<vector<int>> v{};
      for (int i = 1; i <= n; i++) {
        vector<int> t{i};
        v.push_back(t);
      }
      return v;
    }
    vector<vector<int>> one = combine(n - 1, k);
    vector<vector<int>> two = combine(n - 1, k - 1);
    for (auto &v : two)
      v.push_back(n);
    one.insert(one.end(), two.begin(), two.end());
    return one;
  }
};

class Solution2 {
public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> start;
    for (int i = 0; i < k; i++)
      start.push_back(i + 1);

    int idx = 0;
    while (true) {
      if (start[idx] > n - k + idx + 1) {
        if (idx == 0)
          break;
        idx--;
        start[idx]++;
        for (int i = idx; i < k - 1; i++)
          start[i + 1] = start[i] + 1;
      } else if (idx < k - 1) {
        idx++;
      } else {
        result.push_back(start);
        start[idx]++;
      }
    }
    return result;
  }
};

int main() { cout << Solution2().combine(4, 3); }
