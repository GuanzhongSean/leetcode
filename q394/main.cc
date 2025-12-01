#include "solution.cc"

int main() {
	auto result = q394::Solution().decodeString("3[a]2[bc]");
	print(result);
	std::string expect = "aaabcbc";
	EXPECT_EQ(result, expect);
	return 0;
}
