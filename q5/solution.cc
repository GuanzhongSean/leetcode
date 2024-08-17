#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  string longestPalindrome(string s) {
    int len = s.size();
    int max_len = 1;
    int max_b = 0;
    for (int i = 0; i < len; i++) {
      int cur_len = 1;
      int b = i;
      int e = i;
      while (b > 0 && e < len - 1) {
        b--;
        e++;
        if (s[b] == s[e])
          cur_len += 2;
        else {
          b++;
          break;
        }
      }
      if (cur_len > max_len) {
        max_len = cur_len;
        max_b = b;
      }
      if (i < len - 1 && s[i] == s[i + 1]) {
        b = i;
        e = i + 1;
        cur_len = 2;
        while (b > 0 && e < len - 1) {
          b--;
          e++;
          if (s[b] == s[e])
            cur_len += 2;
          else {
            b++;
            break;
          }
        }
        if (cur_len > max_len) {
          max_len = cur_len;
          max_b = b;
        }
      }
    }
    return s.substr(max_b, max_len);
  }
};

int main() {
  Solution s;
  cout << s.longestPalindrome("bb") << endl;
}
