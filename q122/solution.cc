#include <vector>

namespace q122 {

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int prev = prices[0], profit = 0, in = prev, i = 1;
    bool bought = false;
    while (i < prices.size()) {
      if (bought && prices[i] < prev) {
        profit += prev - in;
        bought = false;
      }
      if (!bought && prices[i] > prev) {
        in = prev;
        bought = true;
      }
      prev = prices[i];
      i++;
    }
    if (bought && in < prices.back()) profit += prices.back() - in;
    return profit;
  }
};

}  // namespace q122
