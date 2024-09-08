#include <climits>
#include <vector>

namespace q121 {

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int cur = INT_MAX, profit = 0;
    for (int x : prices) {
      if (x < cur)
        cur = x;
      else
        profit = max(profit, x - cur);
    }
    return profit;
  }
};

}  // namespace q121
