#include <cstring>
#include <iostream>
#include <string>

using namespace std;

class Solution0 {
 public:
  bool isScramble(string s1, string s2) {
    if (s1 == s2) return true;
    if (s1.size() != s2.size() || s1.size() == 1) return false;

    int n = s1.size();
    int count[26] = {0};
    for (int i = 0; i < n; i++) {
      count[s1[i] - 'a']++;
      count[s2[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
      if (count[i] != 0) return false;
    }
    for (int i = 1; i < n; i++) {
      if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
          isScramble(s1.substr(i), s2.substr(i)))
        return true;
      if (isScramble(s1.substr(0, i), s2.substr(n - i)) &&
          isScramble(s1.substr(i), s2.substr(0, n - i)))
        return true;
    }
    return false;
  }
};

class Solution {
 private:
  int dp[32][32][32];
  bool solve(string &s1, string &s2, int l1, int l2, int len) {
    if (len == 0) return dp[l1][l2][len] = true;
    if (dp[l1][l2][len] != -1) return dp[l1][l2][len];
    if (s1.substr(l1, len) == s2.substr(l2, len)) return dp[l1][l2][len] = true;

    int v[26] = {0};
    for (int i = l1, j = l2; i < len + l1; i++, j++) {
      v[s1[i] - 'a']++;
      v[s2[j] - 'a']--;
    }
    for (int x : v) {
      if (x) return dp[l1][l2][len] = false;
    }

    for (int i = 1; i < len; i++) {
      if (solve(s1, s2, l1, l2, i) && solve(s1, s2, l1 + i, l2 + i, len - i)) {
        return dp[l1][l2][len] = true;
      }

      if (solve(s1, s2, l1 + i, l2, len - i) &&
          solve(s1, s2, l1, l2 + (len - i), i)) {
        return dp[l1][l2][len] = true;
      }
    }
    return dp[l1][l2][len] = false;
  }

 public:
  bool isScramble(string s1, string s2) {
    memset(dp, -1, sizeof(dp));
    return solve(s1, s2, 0, 0, s1.size());
  }
};

auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << boolalpha;
  return '$';
}();

int main() {
  bool result = Solution().isScramble("great", "rgeat");
  cout << result << endl;
}
