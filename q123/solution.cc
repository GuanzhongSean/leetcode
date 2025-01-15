#include <vector>

#include "Utils.h"

namespace q123 {

using namespace std;

class Solution {
   public:
	// Find the maximum profit you can achieve. You may complete at most two
	// transactions.
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (n == 0) return 0;
		vector<int> left(n), right(n);
		int min_price = prices[0];
		for (int i = 1; i < n; i++) {
			left[i] = max(left[i - 1], prices[i] - min_price);
			min_price = min(min_price, prices[i]);
		}
		print(left);
		int max_price = prices[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			right[i] = max(right[i + 1], max_price - prices[i]);
			max_price = max(max_price, prices[i]);
		}
		print(right);
		int profit = 0;
		for (int i = 0; i < n; i++) {
			profit = max(profit, left[i] + right[i]);
		}
		return profit;
	}
};

}  // namespace q123
