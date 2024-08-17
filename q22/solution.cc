#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    set<string> result{""};
    while (n) {
      result = insertParenAtEntries(result);
      n--;
    }
    vector<string> result0{};
    for (string str : result) {
      result0.push_back(str);
    }
    return result0;
  }

  vector<string> generateParenthesis2(int n) {
    vector<string> res;

    recursion(n, n, res, "");
    return res;
  }

 private:
  const string parens = "()";
  set<string> insertParenAtEntries(set<string> paren_lists) {
    set<string> result{};
    for (string s0 : paren_lists) {
      string s = parens + s0;
      result.insert(s);
      for (int i = 0; i < s0.size(); i++) {
        if (s0[i] == '(') {
          string s{s0};
          s.insert(i + 1, parens);
          result.insert(s);
        }
      }
    }
    return result;
  }

  void recursion(int open, int close, vector<string>& res, string str) {
    if (open == 0 && close == 0) {
      res.push_back(str);
      return;
    }

    if (open > 0) recursion(open - 1, close, res, str + '(');
    if (close > 0 && close > open) recursion(open, close - 1, res, str + ')');
  }
};

int main() {
  Solution s;
  auto result = s.generateParenthesis(3);
  for (string str : result) {
    cout << str << endl;
  }
}
