#include "solution.cc"
#include "utils.h"

int main() {
  vector<int> nums{-10, -3, 0, 5, 9};
  auto result = q108::Solution().sortedArrayToBST(nums);
  print(result);
  delete result;
}