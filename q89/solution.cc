#include <cmath>

#include "utils.h"

using namespace std;

class Solution {
 public:
  vector<int> grayCode(int n) {
    vector<int> result;
    int len = pow(2, n);
    for (int i = 0; i < len; i++) {
      result.push_back(i ^ (i >> 1));
    }
    return result;
  }
};

class Solution2 {
 public:
  vector<int> grayCode(int n) {
    vector<int> ans = {0};
    for (int i = 0; i < n; i++) {
      int sz = ans.size();
      for (int j = sz - 1; j >= 0; j--) {
        ans.push_back(ans[j] | (1 << i));
      }
    }
    return ans;
  }
};

char init = []() -> char {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << boolalpha;
  return '$';
}();

int main() {
  vector<int> result = Solution2().grayCode(4);
  print(result);
}
