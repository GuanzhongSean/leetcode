#include <gtest/gtest.h>

#include "Utils.h"
#include "solution.cc"

int main() {
  vector<int> v{4, 1, 0, 2, 3, 5, 6, 7, 8, 9};
  auto result = q135::Solution().candy(v);
  print(result);
  EXPECT_EQ(result, 41);
}
