#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool isNegative = false;
        if (x < 0) {
            if (x == INT_MIN) return 0;
            isNegative = true;
            x = -x;
        }
        unsigned reversed = 0;
        while (x > 0) {
            if (reversed > INT_MAX / 10) return 0;
            reversed = reversed * 10 + x % 10;
            x = x / 10;
        }
        if (isNegative) {
            return -reversed;
        } else {
            return reversed;
        }
    }
};


int main() {
    Solution s;
    cout << s.reverse(1534236469) << endl;
}
