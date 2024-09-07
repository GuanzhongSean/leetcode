#include <vector>

namespace q118 {

using namespace std;

class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result{{1}};
    for (int i = 1; i < numRows; i++) {
      vector<int> prev = result.back();
      vector<int> cur(prev.size() + 1, 1);
      for (int j = 1; j < cur.size() - 1; j++) cur[j] = prev[j] + prev[j - 1];
      result.emplace_back(cur);
    }
    return result;
  }
};

}  // namespace q118
