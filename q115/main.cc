#include "Utils.h"
#include "solution.cc"

int main() {
  auto result = q115::Solution().numDistinct("babgbag", "bag");
  print(result);
}
