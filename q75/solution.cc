#include <vector>

#include "utils.h"

using namespace std;

class Solution {
 public:
  void sortColors(vector<int> &nums) {
    vector<int> colour(3, 0);
    for (int n : nums) colour[n]++;
    int i = 0;
    for (int c = 0; c < 3; c++)
      for (int j = 0; j < colour[c]; j++) nums[i++] = c;
  }
};

int main() {
  vector<int> v{2, 0, 2, 1, 1, 0};
  Solution().sortColors(v);
  cout << v;
}
