#include "Utils.h"

using namespace std;

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
