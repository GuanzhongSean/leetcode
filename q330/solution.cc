#include <vector>

using namespace std;

class Solution {
 public:
  int minPatches(vector<int> &nums, int n) {
    long maxReach = 0;
    int count = 0, i = 0;
    while (maxReach < n) {
      if (i < nums.size() && nums[i] <= maxReach + 1) {
        maxReach += nums[i++];
      } else {
        maxReach += maxReach + 1;
        count++;
      }
    }
    return count;
  }
};

int main() {}
