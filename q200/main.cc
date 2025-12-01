#include "solution.cc"

int main() {
	std::vector<std::vector<char>> grid = {{'1', '1', '1', '1', '0'},
										   {'1', '1', '0', '1', '0'},
										   {'1', '1', '0', '0', '0'},
										   {'0', '0', '0', '0', '0'}};
	auto result = q200::Solution().numIslands(grid);
	print(result);
	assert(result == 1);
	return 0;
}
