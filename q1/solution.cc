#include "Utils.h"

namespace q1 {

using namespace std;

inline namespace V1 {
class Solution {
   public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> dict;
		for (int i = 0; i < nums.size(); ++i) {
			if (dict.count(target - nums[i]) && dict[target - nums[i]] != i)
				return {dict[target - nums[i]], i};
			dict[nums[i]] = i;
		}
		return {};
	}
};
}  // namespace V1

}  // namespace q1
