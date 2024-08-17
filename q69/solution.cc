#include <iostream>

using namespace std;

class Solution {
 public:
  int mySqrt(int x) {
    if (x == 0 || x == 1) return x;

    int start = 1, end = x / 2;
    while (start <= end) {
      long long mid = start + (end - start) / 2;
      if (mid * mid > x)
        end = mid - 1;
      else if (mid * mid == x)
        return mid;
      else
        start = mid + 1;
    }
    return end;
  }
};

int main() { cout << Solution().mySqrt(6) << endl; }
