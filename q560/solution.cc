#include "Utils.h"

namespace q560 {

using namespace std;

inline namespace V1 {
class Solution {
   public:
	int subarraySum(vector<int>& nums, int k) {
		unordered_map<int, int> subNum;
		subNum[0] = 1;
		int total = 0, count = 0;
		for (int n : nums) {
			total += n;
			count += subNum[total - k];
			subNum[total]++;
		}
		return count;
	}
};
}  // namespace V1

}  // namespace q560
