#include <string>

namespace q3707 {

using namespace std;

class Solution {
   public:
	bool scoreBalance(string s) {
		int n = s.size();
		int l = 0, r = 0;
		for (char c : s) {
			l += c - 'a' + 1;
		}
		for (int i = n - 1; i >= 0; --i) {
			r += s[i] - 'a' + 1;
			l -= s[i] - 'a' + 1;
			if (l == r) {
				return true;
			}
		}
		return false;
	}
};

}  // namespace q3707
