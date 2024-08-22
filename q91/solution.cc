#include "utils.h"

class Solution {
 public:
  int numDecodings(string s) {
    int n = s.length();
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        if (i == 0 || (s[i - 1] != '1' && s[i - 1] != '2')) return 0;
      }
    }
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
      if (s[i - 1] != '0') dp[i] += dp[i - 1];
      if (i > 1 && s[i - 2] != '0' &&
          (s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26) {
        dp[i] += dp[i - 2];
      }
    }
    return dp[n];
  }
};

char init = []() -> char {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << boolalpha;
  return '$';
}();

int main() {
  auto result = Solution().numDecodings("226");
  print(result);
}
