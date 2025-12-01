#include "Utils.h"

namespace q768 {

using namespace std;

inline namespace V1 {
class Solution {
	struct Chunk {
		size_t endAt;
		int max;
		Chunk(size_t endAt, int max) : endAt(endAt), max(max) {}
	};

   public:
	int maxChunksToSorted(vector<int>& arr) {
		const size_t n = arr.size();
		vector<Chunk> stack;
		for (size_t i = 0; i < n; ++i) {
			int cur_max = arr[i];
			while (stack.size() != 0 && stack.back().max > arr[i]) {
				Chunk c = stack.back();
				stack.pop_back();
				cur_max = max(c.max, cur_max);
			}
			stack.emplace_back(i, cur_max);
		}
		return stack.size();
	}
};
}  // namespace V1

}  // namespace q768
