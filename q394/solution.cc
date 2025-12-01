#include "Utils.h"

namespace q394 {

using namespace std;

inline namespace V1 {
class Solution {
	pair<string, int> decode(const string& s, int index) {
		string result;
		int i = index;
		while (i < s.size()) {
			if (isdigit(s[i])) {
				int count = 0;
				while (i < s.size() && isdigit(s[i])) {
					count = count * 10 + (s[i] - '0');
					i++;
				}
				i++;
				auto [decodedString, nextIndex] = decode(s, i);
				for (int j = 0; j < count; j++) result += decodedString;
				i = nextIndex;
			} else if (s[i] == ']') {
				return {result, i + 1};
			} else {
				result += s[i];
				i++;
			}
		}
		return {result, i};
	}

   public:
	string decodeString(string s) { return decode(s, 0).first; }
};
}  // namespace V1

}  // namespace q394
