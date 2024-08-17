#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int climbStairs(int n) {
    int p1 = 1, p2 = 1, tmp;
    for (int i = 2; i <= n; i++) {
      tmp = p1;
      p1 += p2;
      p2 = tmp;
    }
    return p1;
  }
};

class Solution2 {
 public:
  int climbStairs(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
  }
};

int main() { cout << Solution().climbStairs(6) << endl; }
