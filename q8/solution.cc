#include <climits>
#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  int myAtoi(string s) {
    bool begin = true;
    bool is_negative = false;
    long x = 0;
    for (char ch : s) {
      if (ch == ' ') {
        if (begin)
          continue;
        else
          break;
      } else if (ch == '-') {
        if (begin)
          is_negative = true;
        else
          break;
        begin = false;
      } else if (ch == '+') {
        if (!begin) break;
        begin = false;
      } else if (ch >= '0' && ch <= '9') {
        if (begin) begin = false;
        short digit = ch - '0';
        x = x * 10 + digit;
      } else {
        break;
      }
      if (!is_negative && x > INT_MAX)
        return INT_MAX;
      else if (is_negative && -x < INT_MIN)
        return INT_MIN;
    }
    if (is_negative) x = -x;
    return x;
  }
};

int main() {
  Solution s;
  cout << s.myAtoi("words and 987") << endl;
}
