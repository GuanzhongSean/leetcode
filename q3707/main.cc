#include <gtest/gtest.h>

#include "Utils.h"
#include "solution.cc"

using std::string;

int main() {
	string s = "adcb";
	auto result = q3707::Solution().scoreBalance(s);
	print(result);
	EXPECT_EQ(result, true);
}
