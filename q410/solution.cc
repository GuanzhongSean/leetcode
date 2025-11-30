#include "Utils.h"

namespace q410 {

using namespace std;

namespace V1 {
class Solution {
   public:
	int splitArray(vector<int>& nums, int k) {
		const size_t n = nums.size();
		vector<vector<int>> dp(n, vector<int>(k, INT_MAX));
		int partial_sum = accumulate(nums.begin(), nums.end(), 0);
		for (int i = 0; i < n; i++) {
			dp[i][0] = partial_sum;
			partial_sum -= nums[i];
		}
		for (int j = 1; j < k; j++) {
			for (int i = 0; i < n - j; i++) {
				int curr_sum = 0;
				for (int m = i; m < n - j; m++) {
					curr_sum += nums[m];
					int largest_sum = max(curr_sum, dp[m + 1][j - 1]);
					dp[i][j] = min(dp[i][j], largest_sum);
				}
			}
		}
		return dp[0][k - 1];
	}
};
}  // namespace V1

inline namespace V2 {
class Solution {
   public:
	int splitArray(vector<int>& nums, int k) {
		int low = 0, high = 0;
		for (int num : nums) {
			low = max(low, num);
			high += num;
		}
		int ans = high;
		while (low <= high) {
			int mid = (high + low) / 2;
			if (isFeasible(nums, mid, k)) {
				ans = mid;
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		return ans;
	}

	bool isFeasible(vector<int>& nums, int maxSum, int k) {
		int count = 1;
		int currentSum = 0;
		for (int num : nums) {
			currentSum += num;
			if (currentSum > maxSum) {
				count++;
				currentSum = num;
				if (count > k) return false;
			}
		}
		return true;
	}
};
}  // namespace V2

}  // namespace q410
