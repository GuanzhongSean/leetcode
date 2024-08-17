#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> answer;
    size_t n = nums.size();
    if (n < 3) return answer;
    for (int i = 0; i < n - 3; ++i) {
      if (nums[i] > 0 && nums[i] >= target) break;
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      for (int j = i + 1; j < n - 2; j++) {
        if (nums[j] > 0 && nums[j] >= target - nums[i]) break;
        if (j > i + 1 && nums[j] == nums[j - 1]) continue;
        int low = j + 1, high = n - 1;
        long newTarget = (long)target - (long)nums[i] - (long)nums[j];
        while (low < high) {
          if (nums[low] + nums[high] > newTarget) {
            high--;
          } else if (nums[low] + nums[high] < newTarget) {
            low++;
          } else {
            answer.push_back({nums[i], nums[j], nums[low], nums[high]});
            int last_low = nums[low], last_high = nums[high];
            while (low < high && nums[low] == last_low) low++;
            while (low < high && nums[high] == last_high) high--;
          }
        }
      }
    }
    return answer;
  }
  vector<vector<int>> fourSum1(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    vector<int> path;
    sort(nums.begin(), nums.end());
    nSum(nums, 4, target, 0, nums.size() - 1, path, ans);
    return ans;
  }

 private:
  // Finds n numbers that add up to the target in [l, r].
  void nSum(const vector<int>& nums, long n, long target, int l, int r,
            vector<int>& path, vector<vector<int>>& ans) {
    if (r - l + 1 < n || target < nums[l] * n || target > nums[r] * n) return;
    if (n == 2) {
      // Similar to the sub procedure in 15. 3Sum
      while (l < r) {
        const int sum = nums[l] + nums[r];
        if (sum == target) {
          path.push_back(nums[l]);
          path.push_back(nums[r]);
          ans.push_back(path);
          path.pop_back();
          path.pop_back();
          ++l;
          --r;
          while (l < r && nums[l] == nums[l - 1]) ++l;
          while (l < r && nums[r] == nums[r + 1]) --r;
        } else if (sum < target) {
          ++l;
        } else {
          --r;
        }
      }
      return;
    }

    for (int i = l; i <= r; ++i) {
      if (i > l && nums[i] == nums[i - 1]) continue;
      path.push_back(nums[i]);
      nSum(nums, n - 1, target - nums[i], i + 1, r, path, ans);
      path.pop_back();
    }
  }
};

int main() {
  Solution s;
  vector<int> nums{-1000000000, -1000000000, -1000000000, -1000000000};
  auto result = s.fourSum(nums, -1);
  for (auto v : result) {
    for (auto i : v) {
      cout << i << " ";
    }
    cout << endl;
  }
}
