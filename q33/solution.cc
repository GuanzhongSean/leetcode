#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int m = (l + r) / 2;
      if (nums[m] == target)
        return m;
      else if (nums[m] > target) {
        if (nums[m] >= nums[l] && nums[l] > target)
          l = m + 1;
        else
          r = m - 1;
      } else {
        if (nums[m] <= nums[r] && nums[r] < target)
          r = m - 1;
        else
          l = m + 1;
      }
    }
    return -1;
  }
};

int main() {
  Solution s;
  vector<int> nums{3, 1};
  cout << s.search(nums, 1) << endl;
}
