#include "Utils.h"

namespace q42 {

using namespace std;

namespace V1 {
class Solution {
   public:
	int trap(vector<int>& height) {	 // add up horizontally
		stack<pair<int, int>> s;
		int n = height.size(), sum = 0;
		s.push({0, height[0]});
		for (int i = 1; i < n; i++) {
			int h = height[i];
			if (h == s.top().second)
				s.pop();
			else if (h > s.top().second) {
				int prev_height = s.top().second;
				s.pop();
				while (!s.empty()) {
					if (s.top().second <= h) {
						sum += (i - s.top().first - 1) * (s.top().second - prev_height);
						prev_height = s.top().second;
						s.pop();
					} else {
						sum += (i - s.top().first - 1) * (h - prev_height);
						break;
					}
				}
			}
			s.push({i, h});
		}
		return sum;
	}
};
}  // namespace V1

namespace V2 {
class Solution {
   public:
	int trap(vector<int>& height) {	 // add up vertically
		int n = height.size();
		int l = 0, r = n - 1;
		int leftmax = 0, rightmax = 0, ans = 0;
		while (l < r) {
			if (height[l] <= height[r]) {
				if (height[l] >= leftmax)
					leftmax = height[l];
				else
					ans += leftmax - height[l];
				l++;
			} else {
				if (height[r] >= rightmax)
					rightmax = height[r];
				else
					ans += rightmax - height[r];
				r--;
			}
		}
		return ans;
	}
};
}  // namespace V2

inline namespace V3 {
class Solution {
   public:
	int trap(vector<int>& height) {
		const size_t n = height.size();
		vector<int> left(n), right(n);
		left[0] = height[0];
		right[n - 1] = height[n - 1];
		for (size_t i = 1; i < n; ++i) {
			left[i] = max(left[i - 1], height[i]);
			right[n - 1 - i] = max(right[n - i], height[n - 1 - i]);
		}

		int volumn = 0;
		for (size_t i = 1; i < n - 1; ++i)
			volumn += max(0, min(left[i - 1], right[i + 1]) - height[i]);
		return volumn;
	}
};
}  // namespace V3

}  // namespace q42
