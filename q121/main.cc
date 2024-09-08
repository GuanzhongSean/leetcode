#include "solution.cc"
#include "utils.h"

int main() {
  vector<int> prices{7, 1, 5, 3, 6, 4};
  auto result = q121::Solution().maxProfit(prices);
  print(result);
}
