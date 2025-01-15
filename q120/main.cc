#include "Utils.h"
#include "solution.cc"

int main() {
	vector<vector<int>> triangle{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
	auto result = q120::Solution().minimumTotal(triangle);
	print(result);
}
