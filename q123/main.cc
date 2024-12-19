#include <gtest/gtest.h>

#include "solution.cc"

int main() {
  vector<int> prices{3, 3, 5, 0, 0, 3, 1, 4};
  auto result = q123::Solution().maxProfit(prices);
  print(result);
  EXPECT_EQ(result, 6);
}
