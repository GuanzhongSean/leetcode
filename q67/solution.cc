#include "../include/utils.h"

using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    string x, y;
    if (a.size() > b.size()) {
      x = a;
      y = b;
    } else {
      x = b;
      y = a;
    }
    int carry = 0;
    for (int i = 0; i < x.size(); i++) {
      int sum = x[x.size() - i - 1] - '0' + carry;
      if (i < y.size())
        sum += y[y.size() - i - 1] - '0';
      else if (carry == 0)
        break;
      x[x.size() - i - 1] = sum % 2 + '0';
      carry = sum / 2;
    }
    return carry ? '1' + x : x;
  }
};

int main() { cout << Solution().addBinary("111", "1011") << endl; }
