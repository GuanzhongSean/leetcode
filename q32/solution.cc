#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  int longestValidParentheses(string s) {
    stack<int> stk;
    stk.push(-1);
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(')
        stk.push(i);
      else {
        if (stk.size() == 1)
          stk.top() = i;
        else {
          stk.pop();
          ans = max(ans, i - stk.top());
        }
      }
    }
    return ans;
  }
};

class Solution2 {
 public:
  int longestValidParentheses(string s) {
    int n = s.length();
    if (n == 0) return 0;
    vector<int> dp(n, 0);
    dp[0] = 0;  // Base case as it doesnt matter if the first one is ( or )
    int answer = 0;

    for (int i = 1; i < n; i++) {
      if (s[i] == '(') {
        dp[i] = 0;
      } else {
        if (s[i - 1] == '(') {
          if (i - 2 >= 0) {
            dp[i] = dp[i - 2] + 2;
          } else {
            dp[i] = 2;
          }
        } else {
          if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
            dp[i] = dp[i - 1] + 2;
            if (i - dp[i - 1] - 2 >= 0) {
              dp[i] += dp[i - dp[i - 1] - 2];
            }
          }
        }
      }
      answer = max(answer, dp[i]);
    }
    return answer;
  }
};

int main() {
  Solution s;
  cout << s.longestValidParentheses("(())") << endl;
}
