#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string largestNumber(vector<int> &arr) {
    vector<string> s;
    for (int i : arr) {
      s.push_back(to_string(i));
    }
    sort(s.begin(), s.end(),
         [&](string a, string b) { return (a + b > b + a); });
    string ans = "";
    for (int i = 0; i < arr.size(); i++) ans += s[i];
    if (ans[0] == '0') return "0";
    return ans;
  }
};

int main() {}
