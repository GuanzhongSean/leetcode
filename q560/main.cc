
#include "solution.cc"

int main() {
	std::vector<int> nums = {0,0,0};
	auto result = q560::Solution().subarraySum(nums, 0);
	print(result);
	assert(result == 6);
	return 0;
}
