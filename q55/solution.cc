#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool canJump(vector<int> &nums) {
    int cur = 0;
    while (cur < nums.size() - 1) {
      int max = 0;
      int new_cur = cur;
      for (int i = 1; i <= nums[cur] && cur + i < nums.size(); i++) {
        if (i + nums[cur + i] >= max) {
          new_cur = cur + i;
          max = i + nums[cur + i];
        }
      }
      if (new_cur == cur)
        return false;
      cur = new_cur;
    }
    return true;
  }
};

int main() {
  vector<int> v{2,3,1,1,4};
  cout << Solution().canJump(v) << endl;
}
