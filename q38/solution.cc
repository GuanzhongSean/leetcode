#include <iostream>

using namespace std;

class Solution {
 public:
  string countAndSay(int n) {
    if (n == 1) return "1";
    string str = countAndSay(n - 1);
    string tmp{};
    char c = str[0];
    int count = 0;
    for (char ch : str) {
      if (ch == c) {
        count++;
      } else {
        tmp += '0' + count;
        tmp += c;
        c = ch;
        count = 1;
      }
    }
    tmp += '0' + count;
    tmp += c;
    return tmp;
  }
};

int main() {
  Solution s;
  auto result = s.countAndSay(4);
  cout << result << endl;
}
