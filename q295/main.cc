#include "Utils.h"

using namespace std;

namespace {

namespace V1 {

class MedianFinder {
	multiset<int> data;
	multiset<int>::iterator mid;

   public:
	MedianFinder() {}

	void addNum(int num) {
		const int n = data.size();

		data.insert(num);
		if (n == 0) {
			mid = data.begin();
			return;
		}

		if (num < *mid) {
			if (n % 2 == 1) {
				mid--;
			}
		} else {
			if (n % 2 == 0) {
				mid++;
			}
		}
	}

	double findMedian() const {
		int n = data.size();
		if (n == 0) throw runtime_error("No elements present");

		if (n % 2 == 1) {
			return *mid;  // odd: mid is median
		} else {
			auto next_it = next(mid);
			return (*mid + *next_it) / 2.0;
		}
	}
};
}  // namespace V1

inline namespace V2 {

class MedianFinder {
   public:
	priority_queue<int> maxh;
	priority_queue<int, vector<int>, greater<int>> minh;

	MedianFinder() {}

	void addNum(int num) {
		maxh.push(num);
		minh.push(maxh.top());
		maxh.pop();
		if (minh.size() > maxh.size()) {
			maxh.push(minh.top());
			minh.pop();
		}
	}

	double findMedian() {
		return maxh.size() == minh.size() ? (maxh.top() + minh.top()) / 2.0 : maxh.top();
	}
};
}  // namespace V2

}  // namespace

int main() {
	MedianFinder medianFinder = MedianFinder();
	medianFinder.addNum(1);					  // arr = [1]
	medianFinder.addNum(2);					  // arr = [1, 2]
	double val1 = medianFinder.findMedian();  // return 1.5 (i.e., (1 + 2) / 2)
	EXPECT_EQ(val1, 1.5);
	medianFinder.addNum(3);					  // arr = [1, 2, 3]
	double val2 = medianFinder.findMedian();  // return 2.0
	EXPECT_EQ(val2, 2.0);
	print("All test cases passed!");
	return 0;
}
