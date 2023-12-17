#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
      if (s.size() % 2) return false;
      stack<char> container;
      for (char ch : s) {
        if (container.empty()) {
          container.push(ch);
          continue;
        } else {
          if (ch - container.top() == 1 || ch - container.top() == 2) {
            container.pop();
          } else {
            container.push(ch);
          }
        }
      }
      return container.empty();
    }
};

int main() {
    Solution s;
    auto result = s.isValid("([)][]{}");
    cout << result << endl;
}
