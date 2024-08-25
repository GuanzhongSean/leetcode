#include <cstring>

#include "utils.h"

namespace q97 {

class Solution1 {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    int m = s1.length(), n = s2.length(), l = s3.length();
    if (m + n != l) return false;

    if (m < n) return isInterleave(s2, s1, s3);

    vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (int j = 1; j <= n; ++j) {
      dp[j] = dp[j - 1] && s2[j - 1] == s3[j - 1];
    }

    for (int i = 1; i <= m; ++i) {
      dp[0] = dp[0] && s1[i - 1] == s3[i - 1];
      for (int j = 1; j <= n; ++j) {
        dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) ||
                (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
      }
    }

    return dp[n];
  }
};

class Solution {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
    if (n1 + n2 != n3) return false;

    int count[26] = {0};
    for (char c : s3) count[c - 'a']++;
    for (char c : s1) count[c - 'a']--;
    for (char c : s2) count[c - 'a']--;
    for (int i = 0; i < 26; i++) {
      if (count[i]) return false;
    }

    bool dp[n1 + 1][n2 + 1];
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;
    for (int i = 1; i <= n1; i++)
      dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];

    for (int i = 1; i <= n2; i++)
      dp[0][i] = dp[0][i - 1] && s2[i - 1] == s3[i - 1];

    for (int i = 1; i <= n1; i++)
      for (int j = 1; j <= n2; j++)
        dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                   (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
    return dp[n1][n2];
  }
};

}  // namespace q97

int main() {
  string s1 =
      "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaa"
      "bababbbaabababababbbaaababaa";
  string s2 =
      "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbb"
      "bbbbbbbbabaaabbababbabbabaab";
  string s3 =
      "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaababab"
      "baaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaab"
      "aababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab";
  auto result = q97::Solution().isInterleave(s1, s2, s3);
  print(result);
}
