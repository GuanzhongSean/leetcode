
#include "solution.cc"

int main() {
	std::vector<int> nums = {5,1,1,8,1,6,5,9,7,8};
	auto result = q768::Solution().maxChunksToSorted(nums);
	print(result);
	return 0;
}
