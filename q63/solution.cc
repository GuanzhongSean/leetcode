#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    int dp[m][n];
    memset(dp, 0, sizeof(dp));
    if (obstacleGrid[0][0] == 1) return 0;
    dp[0][0] = 1;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (obstacleGrid[i][j] == 1) continue;
        if (i > 0) dp[i][j] += dp[i - 1][j];
        if (j > 0) dp[i][j] += dp[i][j - 1];
      }
    }
    return dp[m - 1][n - 1];
  }
};

int main() {
  vector<vector<int>> grid{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  cout << Solution().uniquePathsWithObstacles(grid) << endl;
}
