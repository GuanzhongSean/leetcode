#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int> &nums) {
    if (nums.empty()) return 0;
    int idx = 1, remain = 1;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] == nums[i - 1]) {
        if (remain) {
          remain--;
          nums[idx++] = nums[i];
        }
      } else {
        remain = 1;
        nums[idx++] = nums[i];
      }
    }
    return idx;
  }
};

class Solution2 {
 public:
  int removeDuplicates(vector<int> &nums) {
    int i = 0;
    for (int n : nums)
      if (i < 2 || n > nums[i - 2]) nums[i++] = n;
    return i;
  }
};

int main() {
  vector<int> nums{0, 0, 1, 1, 1, 1, 2, 3, 3};
  int i = Solution().removeDuplicates(nums);
  cout << i << endl;
  for (int j = 0; j < i; j++) cout << nums[j] << " ";
  cout << endl;
}
