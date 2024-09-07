#include <cstring>
#include <vector>

namespace q120 {

using namespace std;

class Solution {
  int memo[200][200];
  bool visited[200][200];
  int solve(vector<vector<int>>& triangle, int i, int j) {
    if (i == triangle.size() - 1) return triangle[i][j];
    if (visited[i][j]) return memo[i][j];
    memo[i][j] = triangle[i][j] +
                 min(solve(triangle, i + 1, j), solve(triangle, i + 1, j + 1));
    visited[i][j] = true;
    return memo[i][j];
  }

 public:
  int minimumTotal(vector<vector<int>>& triangle) {
    memset(visited, false, sizeof(visited));
    return solve(triangle, 0, 0);
  }
};

class Solution2 {
 public:
  int minimumTotal(vector<vector<int>>& triangle) {
    int dp[200][200];
    memset(dp, 0, sizeof(dp));
    int n = triangle.size();
    for (int i = 0; i < triangle[n - 1].size(); i++)
      dp[n - 1][i] = triangle[n - 1][i];

    for (int i = n - 2; i >= 0; i--)
      for (int j = 0; j < triangle[i].size(); j++)
        dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
    return dp[0][0];
  }
};

}  // namespace q120
