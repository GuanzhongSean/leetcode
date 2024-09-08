#include "solution.cc"
#include "utils.h"

int main() {
  vector<int> prices{1,2,3,4,5};
  auto result = q122::Solution().maxProfit(prices);
  print(result);
}
