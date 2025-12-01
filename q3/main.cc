#include "solution.cc"

int main() {
	std::string s = "abcabcbb";
	auto result = q3::Solution().lengthOfLongestSubstring(s);
	print(result);
    EXPECT_EQ(result, 3);
	return 0;
}
