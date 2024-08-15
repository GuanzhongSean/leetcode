#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool search(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target) {
        return true;
      }
      if (nums[left] == nums[mid]) {
        left++;
        continue;
      }
      if (nums[left] < nums[mid]) {
        if (nums[left] <= target && target < nums[mid]) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      } else {
        if (nums[mid] < target && target <= nums[right]) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
    }
    return false;
  }
};

class Solution2 {
public:
  bool search(vector<int> &nums, int target) {
    for (int itr : nums) {
      if (itr == target) {
        return true;
      }
    }
    return false;
  }
};

int main() {
  vector<int> nums{2, 5, 6, 0, 0, 1, 2};
  bool result = Solution().search(nums, 0);
  cout << result << endl;
}
