#include <vector>

namespace q119 {

using namespace std;

class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> result{1};
    for (int i = 0; i < rowIndex; i++) {
      vector<int> cur(result.size() + 1, 1);
      for (int j = 1; j < cur.size() - 1; j++)
        cur[j] = result[j] + result[j - 1];
      result = cur;
    }
    return result;
  }
};

}  // namespace q119
