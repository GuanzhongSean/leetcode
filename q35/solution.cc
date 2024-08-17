#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    if (r == -1 || nums[l] >= target)
      return 0;
    else if (nums[r] < target)
      return r + 1;
    while (l <= r) {
      int m = (l + r) / 2;
      if (nums[m] == target)
        return m;
      else if (nums[m] > target)
        r = m - 1;
      else
        l = m + 1;
    }
    return l;
  }
};

int main() {
  Solution s;
  vector<int> nums{5, 7, 7, 8, 8, 8, 10};
  auto result = s.searchInsert(nums, 6);
  cout << result << endl;
}
