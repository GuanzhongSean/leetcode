#include <cstring>
#include <iostream>

using namespace std;

class Solution {
 public:
  bool isMatch(string s, string p) {
    int n = s.length(), m = p.length();
    bool dp[n + 1][m + 1];
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;
    for (int i = 1; i <= m; i++)
      if (p[i - 1] == '*')
        dp[0][i] = true;
      else
        break;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        if (p[j - 1] == '*')
          dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
        else
          dp[i][j] =
              dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
    // print dynamic chart
    cout << "\\   ";
    for (char ch : p) cout << ch << ' ';
    cout << endl;
    for (int i = 0; i <= n; i++) {
      cout << (i == 0 ? ' ' : s[i - 1]) << ' ';
      for (int j = 0; j <= m; j++) cout << dp[i][j] << ' ';
      cout << endl;
    }
    return dp[n][m];
  }
};

int main() {
  auto result = Solution{}.isMatch("abcabczzzde", "*abc???de*");
  cout << "result: " << result << endl;
}
