#include "Utils.h"
#include "solution.cc"

int main() {
	std::vector<int> prices{7, 1, 5, 3, 6, 4};
	auto result = q121::Solution().maxProfit(prices);
	print(result);
}
