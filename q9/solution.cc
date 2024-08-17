#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) return false;

    long reversed = 0;
    int temp = x;

    while (temp != 0) {
      int digit = temp % 10;
      reversed = reversed * 10 + digit;
      temp /= 10;
    }

    return (reversed == x);
  }
  bool isPalindrome2(int x) {
    if (x < 0) return false;
    string str = to_string(x);
    for (unsigned i = 0; i < str.size() / 2; i++) {
      if (str[i] == str[str.size() - 1 - i]) continue;
      return false;
    }
    return true;
  }
};

int main() {
  Solution s;
  cout << s.isPalindrome(12321) << endl;
}
