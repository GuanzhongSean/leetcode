#include <algorithm>

#include "../include/utils.h"

using namespace std;

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> result;
    result.push_back(intervals[0]);
    for (int i = 1; i < n; i++)
      if (intervals[i][0] <= result.back()[1])
        result.back()[1] = max(result.back()[1], intervals[i][1]);
      else
        result.push_back(intervals[i]);
    return result;
  }
};

int main() {
  vector<vector<int>> intervals{{1, 4}, {1, 5}};
  cout << Solution().merge(intervals);
}
