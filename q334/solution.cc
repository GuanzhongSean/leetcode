#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool increasingTriplet(vector<int> &nums) {
    int n = nums.size(), min;
    vector<bool> d(n, false);
    if (n > 0) min = nums[0];
    for (int i = 1; i < n; i++) {
      if (nums[i] > min) {
        d[i] = true;
      }
      min = std::min(min, nums[i]);
    }
    if (n > 1) min = nums[1];
    int min_i = 1;
    for (int i = 2; i < n; i++) {
      if (nums[i] > min && d[min_i]) return true;
      if (d[i] && (nums[i] < min || !d[min_i])) {
        min = nums[i];
        min_i = i;
      }
    }
    return false;
  }
};

class Solution2 {
 public:
  bool increasingTriplet(vector<int> &nums) {
    int fst = INT_MAX;
    int scnd = INT_MAX;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] <= fst)
        fst = nums[i];
      else if (nums[i] <= scnd)
        scnd = nums[i];
      else
        return true;
    }

    return false;
  }
};

int main() {
  vector<int> nums = {2, 1, 5, 0, 4, 6};
  cout << Solution().increasingTriplet(nums) << endl;
}
