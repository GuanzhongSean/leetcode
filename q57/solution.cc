#include <vector>

#include "utils.h"

using namespace std;

class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    bool inserted = false;
    vector<vector<int>> ans{};
    for (auto i : intervals) {
      if (i[0] > newInterval[1]) {
        if (!inserted) {
          ans.push_back(newInterval);
          inserted = true;
        }
        ans.push_back(i);
      } else if (i[1] < newInterval[0]) {
        ans.push_back(i);
      } else {
        newInterval[0] = min(newInterval[0], i[0]);
        newInterval[1] = max(newInterval[1], i[1]);
      }
    }
    if (!inserted) ans.push_back(newInterval);
    return ans;
  }
};

class Solution2 {
 public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    int i = 0;
    vector<vector<int>> ans;

    while (i < intervals.size() && intervals[i][1] < newInterval[0])
      ans.push_back(intervals[i++]);

    while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
      newInterval[0] = min(newInterval[0], intervals[i][0]);
      newInterval[1] = max(newInterval[1], intervals[i++][1]);
    }

    ans.push_back(newInterval);

    while (i < intervals.size()) ans.push_back(intervals[i++]);

    return ans;
  }
};

int main() {
  vector<vector<int>> intervals{{1, 4}, {5, 6}};
  vector<int> newInterval{4, 7};
  cout << Solution().insert(intervals, newInterval);
}
