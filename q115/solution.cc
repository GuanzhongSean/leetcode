#include <cstring>
#include <string>

namespace q115 {

using namespace std;

class Solution0 {
 public:
  int numDistinct(string s, string t) {
    int n = s.size(), m = t.size();
    if (n < m) return 0;
    int count[58] = {0};
    for (char c : s) count[c - 'A']++;
    for (char c : t) {
      count[c - 'A']--;
      if (count[c - 'A'] < 0) return 0;
    }
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n; i++) dp[i][0] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= min(i, m); j++) {
        dp[i][j] = dp[i - 1][j];
        if (s[i - 1] == t[j - 1]) dp[i][j] += dp[i - 1][j - 1];
      }
    }
    return dp[n][m];
  }
};

class Solution {
  int n, m;
  int memo[1000][1000];
  int recursion(string& s, string& t, int id1, int id2) {
    if (id2 == m) return 1;
    if (n - id1 < m - id2) return 0;
    if (memo[id1][id2] != -1) return memo[id1][id2];
    int ans = recursion(s, t, id1 + 1, id2);
    if (s[id1] == t[id2]) ans += recursion(s, t, id1 + 1, id2 + 1);
    return memo[id1][id2] = ans;
  }

 public:
  int numDistinct(string s, string t) {
    n = s.size();
    m = t.size();
    if (n < m) return 0;
    int count[58] = {0};
    for (char c : s) count[c - 'A']++;
    for (char c : t) {
      count[c - 'A']--;
      if (count[c - 'A'] < 0) return 0;
    }
    memset(memo, -1, sizeof(memo));
    return recursion(s, t, 0, 0);
  }
};

}  // namespace q115
