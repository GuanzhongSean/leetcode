#include <map>

#include "utils.h"

class Solution {
  vector<vector<int>> result;
  map<int, int> nums_;
  void helper(vector<int>& cur, int pos) {
    if (pos >= nums_.size()) {
      result.push_back(cur);
      return;
    }

    auto it = nums_.begin();
    advance(it, pos);
    int n = it->first;
    int count = it->second;
    helper(cur, pos + 1);
    for (int i = 0; i < count; i++) {
      cur.push_back(n);
      helper(cur, pos + 1);
    }
    for (int i = 0; i < count; i++) {
      cur.pop_back();
    }
  }

 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    result.clear();
    nums_.clear();
    for (int x : nums) nums_[x]++;
    vector<int> cur{};
    helper(cur, 0);
    return result;
  }
};

char init = []() -> char {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << boolalpha;
  return '$';
}();

int main() {
  vector<int> nums{1, 2, 2};
  vector<vector<int>> result = Solution().subsetsWithDup(nums);
  print(result);
}
