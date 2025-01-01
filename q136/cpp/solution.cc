#include <vector>

namespace q136 {

class Solution {
 public:
  int singleNumber(std::vector<int>& nums) {
    int result(0);
    for (int i : nums) result ^= i;
    return result;
  }
};

}  // namespace q136
