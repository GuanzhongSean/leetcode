#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans{-1, -1};
    int l = 0, r = nums.size() - 1;
    if (r == -1 || nums[l] > target || nums[r] < target) return ans;
    while (l <= r) {
      int m = (l + r) / 2;
      if (nums[m] == target) {
        int m0 = m, m1 = m;
        while (l <= m0) {
          m = (l + m0) / 2;
          if (nums[m] == target && (m == 0 || nums[m - 1] != target)) {
            ans[0] = m;
            break;
          } else if (nums[m] < target)
            l = m + 1;
          else
            m0 = m - 1;
        }
        while (m1 <= r) {
          m = (m1 + r) / 2;
          if (nums[m] == target &&
              (m == nums.size() - 1 || nums[m + 1] != target)) {
            ans[1] = m;
            break;
          } else if (nums[m] > target)
            r = m - 1;
          else
            m1 = m + 1;
        }
        break;
      } else if (nums[m] < target) {
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    return ans;
  }
};

class Solution2 {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int i = 0, j = nums.size() - 1;
    vector<int> ans{-1, -1};
    while (i <= j) {
      if (nums[i] == target && nums[j] == target) {
        ans[0] = i;
        ans[1] = j;
        break;
      } else if (nums[i] != target)
        i++;
      else if (nums[j] != target)
        j--;
    }
    return ans;
  }
};

int main() {
  Solution s;
  vector<int> nums{5, 7, 7, 8, 8, 8, 10};
  auto result = s.searchRange(nums, 6);
  for (int i : result) {
    cout << i << " ";
  }
  cout << endl;
}
