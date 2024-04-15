#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int max_sum = nums[0], prev = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      prev = max(nums[i], prev + nums[i]);
      max_sum = max(max_sum, prev);
    }
    return max_sum;
  }
};

int main() {
  vector<int> v{-2, 1, -3, 4, -1, 2, 1, -5, 4};
  cout << Solution().maxSubArray(v) << endl;
}
