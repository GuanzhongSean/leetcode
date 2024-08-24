#include <cstring>

#include "utils.h"

namespace q96 {

class Solution {
 public:
  int numTrees(int n) {
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
      for (int j = 0; j < i; j++) {
        dp[i] += dp[j] * dp[i - j - 1];
      }
    }
    return dp[n];
  }
};

}  // namespace q96

int main() {
  auto result = q96::Solution().numTrees(3);
  print(result);
}
