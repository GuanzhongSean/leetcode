#include "solution.cc"

using std::vector;
using std::string;

int main() {
	vector<string> wordList{"ymann","yycrj","oecij","ymcnj","yzcrj","yycij","xecij","yecij","ymanj","yzcnj","ymain"};
	auto result = q127::Solution{}.ladderLength("ymain", "oecij", wordList);
	print(result);
    EXPECT_EQ(result, 10);
    return 0;
}
