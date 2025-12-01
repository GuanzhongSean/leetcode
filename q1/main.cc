#include "solution.cc"

int main() {
	std::vector<int> nums{2,7,11,15};
	auto result = q1::Solution().twoSum(nums, 9);
	print(result);
	std::vector<int> expect{0,1};
	EXPECT_EQ(result, expect);
	return 0;
}
