#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int minimumChairs(string s) {
    int current_people = 0;
    int max_people = 0;

    for (char event : s) {
      if (event == 'E') {
        current_people++;
      } else if (event == 'L') {
        current_people--;
      }
      max_people = max(max_people, current_people);
    }

    return max_people;
  }
  int countDays(int days, vector<vector<int>> &meetings) {
    sort(
        meetings.begin(), meetings.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });

    int count = 0;
    int max_end = 0;
    for (auto m : meetings) {
      if (m[0] > days)
        break;
      if (m[0] > max_end + 1)
        count += m[0] - max_end - 1;
      max_end = max(max_end, m[1]);
    }
    count += days - max_end;

    return count;
  }
  int minimumDifference(vector<int> &nums, int k) {
    int n = nums.size(), min = INT_MAX;
    for (int i : nums) {
      if (i == k)
        return 0;
      min = ::min(min, abs(nums[i] - k));
    }
    vector<int> dp{nums};
    for (int len = 2; len <= n; len++) {
      for (int i = 0; i <= n - len; i++) {
        dp[i] = dp[i + 1] & nums[i];
        if (dp[i] == k)
          return 0;
        min = ::min(min, abs(dp[i] - k));
      }
    }
    return min;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> meetings1 = {{2, 5}, {3, 8}, {9, 10}};
  vector<vector<int>> meetings2 = {{2, 4}, {1, 3}};
  vector<vector<int>> meetings3 = {{1, 6}};

  cout << sol.countDays(8, meetings1) << endl; // Output: 3
  cout << sol.countDays(5, meetings2) << endl; // Output: 2
  cout << sol.countDays(6, meetings3) << endl; // Output: 1

  return 0;
}
