#include <iostream>

using namespace std;

class Solution {
public:
  double myPow(double x, int n) {
    if (n == 0)
      return 1;
    if (n == 1)
      return x;
    if (n == -1)
      return 1 / x;

    double half = myPow(x, n / 2);
    double res = half * half;
    if (n % 2 == 1)
      res *= x;
    else if (n % 2 == -1)
      res /= x;
    return res;
  }
};

class Solution2 {
public:
  double myPow(double x, int n) {
    if (n == 0)
      return 1;
    if (n == 1)
      return x;
    if (n == -1)
      return 1 / x;

    if (n % 2)
      return x * myPow(x, n - 1);
    return myPow(x * x, n / 2);
  }
};

int main() { cout << Solution().myPow(2, 10) << endl; }
