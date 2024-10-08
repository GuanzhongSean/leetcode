#include "utils.h"

namespace q93 {

class Solution {
  vector<string> result;
  vector<string> path;
  void backtrack(const string& s, int start, int step) {
    if (start == s.size() && step == 4) {
      result.push_back(path[0] + "." + path[1] + "." + path[2] + "." + path[3]);
      return;
    }
    if (s.size() - start > (4 - step) * 3) return;
    if (s.size() - start < 4 - step) return;
    int num = 0;
    for (int i = start; i < start + 3; i++) {
      num = num * 10 + (s[i] - '0');
      if (num <= 255) {
        path.push_back(s.substr(start, i - start + 1));
        backtrack(s, i + 1, step + 1);
        path.pop_back();
      }
      if (num == 0) break;
    }
  }

 public:
  vector<string> restoreIpAddresses(string s) {
    result.clear();
    path.clear();
    backtrack(s, 0, 0);
    return result;
  }
};

}  // namespace q93

int main() {
  auto result = q93::Solution().restoreIpAddresses("25525511135");
  print(result);
}
