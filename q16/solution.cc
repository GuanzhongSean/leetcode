#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    int result = nums[0] + nums[1] + nums[2];
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i++) {
      if (nums[i] > target && nums[i] > 0) break;
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      int low = i + 1, high = nums.size() - 1;
      while (low < high) {
        int sum = nums[i] + nums[low] + nums[high];
        if (abs(target - sum) < abs(target - result)) result = sum;
        if (sum > target) {
          high--;
        } else if (sum < target) {
          low++;
        } else {
          return target;
        }
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  vector<int> nums{-100, -98, -2, -1};
  auto result = s.threeSumClosest(nums, -101);
  cout << result << endl;
}
