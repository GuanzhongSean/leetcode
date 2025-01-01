#include <gtest/gtest.h>

#include "Utils.h"
#include "solution.cc"

int main() {
  vector<int> v{2, 2, 1};
  auto result = q136::Solution().singleNumber(v);
  print(result);
  EXPECT_EQ(result, 1);
}
