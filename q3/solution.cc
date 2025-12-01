#include "Utils.h"

namespace q3 {

using namespace std;

inline namespace V1 {
class Solution {
   public:
	uint16_t lengthOfLongestSubstring(string s) {
		uint16_t max_substr = 0;
		uint16_t cur_begin = 0;
		uint16_t cur_index = 0;
		vector<int> char_dic{};
		char_dic.resize(255, -1);
		for (char ch : s) {
			if (char_dic[ch] < cur_begin) {
				max_substr = max<uint16_t>(max_substr, cur_index - cur_begin + 1);
			} else {
				cur_begin = char_dic[ch] + 1;
			}
			char_dic[ch] = cur_index;
			cur_index++;
		}
		return max_substr;
	}
};
}  // namespace V1

}  // namespace q3
