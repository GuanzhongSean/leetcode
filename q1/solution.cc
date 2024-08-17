#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        if (nums[i] + nums[j] == target) return vector<int>{i, j};
      }
    }
    return vector<int>{};
  }
};

int main() {
  Solution s;
  vector<int> nums{3, 2, 4};
  int target = 6;
  vector<int> result = s.twoSum(nums, target);
  for (int x : result) {
    cout << x << endl;
  }
}
