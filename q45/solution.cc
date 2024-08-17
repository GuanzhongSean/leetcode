#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  int recall(vector<int>& nums, int ind, vector<int>& dp) {
    if (ind >= nums.size() - 1) return 0;
    if (dp[ind] != 0) return dp[ind];
    int ans = INT_MAX - 1;
    for (int i = ind + 1; i <= ind + nums[ind]; i++)
      ans = min(ans, 1 + recall(nums, i, dp));
    return dp[ind] = ans;
  }

 public:
  int jump(vector<int>& nums) {
    vector<int> dp(nums.size(), 0);
    int mans = recall(nums, 0, dp);
    return mans;
  }
};

class Solution2 {
 public:
  int jump(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++)
      nums[i] = max(nums[i] + i, nums[i - 1]);

    int ind = 0;
    int ans = 0;
    while (ind < nums.size() - 1) {
      ans++;
      ind = nums[ind];
    }
    return ans;
  }
};

class Solution3 {
 public:
  int jump(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return 0;

    int jumps = 0;
    int current = 0;
    int next = 0;
    for (int i = 0; i < n - 1; ++i) {
      next = max(next, i + nums[i]);
      if (i == current) {
        current = next;
        jumps += 1;
      }
    }
    return jumps;
  }
};

int main() {
  vector<int> nums{2, 3, 1, 1, 4};
  auto result = Solution{}.jump(nums);
  cout << "result: " << result << endl;
}
