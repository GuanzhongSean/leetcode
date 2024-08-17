#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, int> map{};
    vector<vector<string>> ans{};

    for (int i{}; i < strs.size(); i++) {
      string copy(strs[i]);
      sort(copy.begin(), copy.end());
      if (!map.count(copy)) {
        map[copy] = ans.size();
        ans.push_back({strs[i]});
      } else {
        ans[map[copy]].push_back(strs[i]);
      }
    }

    return ans;
  }
};

int main() {
  vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
  auto result = Solution{}.groupAnagrams(strs);
  cout << "result: " << endl;
  for (auto v : result) {
    for (string s : v) {
      cout << s << " ";
    }
    cout << endl;
  }
}
