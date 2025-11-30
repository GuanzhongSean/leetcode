
#include "solution.cc"

int main() {
	std::vector<int> nums = {7,2,5,10,8};
	auto result = q410::Solution().splitArray(nums, 2);
	print(result);
	return 0;
}
