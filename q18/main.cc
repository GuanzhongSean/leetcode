#include "solution.cc"

using std::vector;

int main() {
	vector<int> nums{1, 0, -1, 0, -2, 2};
	auto result = q1::Solution().fourSum(nums, 0);
	print(result);
	vector<vector<int>> expect{{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}};
	EXPECT_EQ(result, expect);
	return 0;
}
