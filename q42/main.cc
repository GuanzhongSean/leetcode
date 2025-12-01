#include "solution.cc"

using std::vector;

int main() {
	vector<int> heights{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	auto result = q42::Solution{}.trap(heights);
	print(result);
    EXPECT_EQ(result, 6);
    return 0;
}
