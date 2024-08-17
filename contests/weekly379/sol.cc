#include <climits>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int findPermutationDifference(string s, string t) {
    int dict[26];
    memset(dict, -1, sizeof(dict));
    int n = s.size();
    for (int i = 0; i < n; i++) dict[s[i] - 'a'] = i;
    int ans = 0;
    for (int i = 0; i < n; i++) ans += abs(dict[t[i] - 'a'] - i);
    return ans;
  }
  int maximumEnergy(vector<int> &energy, int k) {
    int n = energy.size();
    vector<int> dp(n, 0);
    int ans = INT_MIN;
    for (int i = n - 1; i >= 0; i--) {
      dp[i] = energy[i];
      if (i < n - k) dp[i] += dp[i + k];
      ans = max(ans, dp[i]);
    }
    return ans;
  }
  int maxScore(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, INT_MIN));

    for (int i = m - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        dp[i][j] = grid[i][j];
        if (i < m - 1) dp[i][j] = max(dp[i][j], dp[i + 1][j]);
        if (j < n - 1) dp[i][j] = max(dp[i][j], dp[i][j + 1]);
      }
    }

    int ans = INT_MIN;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i < m - 1) ans = max(ans, dp[i + 1][j] - grid[i][j]);
        if (j < n - 1) ans = max(ans, dp[i][j + 1] - grid[i][j]);
      }
    }

    return ans;
  }
};

int main() {
  vector<int> energy = {5, 2, -10, -5, 1};
  vector<vector<int>> grid{{4, 3, 2}, {3, 2, 1}};  // 9
  vector<vector<int>> grid2{
      {9, 5, 7, 3}, {8, 9, 6, 1}, {6, 7, 14, 3}, {2, 5, 3, 1}};            // -1
  vector<vector<int>> grid3{{6, 5, 1}, {5, 7, 9}, {6, 7, 4}, {6, 10, 5}};  // 8
  cout << Solution().maxScore(grid3) << endl;
}
