#include "utils.h"

using namespace std;

class Solution {
 public:
  vector<int> plusOne(vector<int> &digits) {
    int i = digits.size() - 1;
    vector<int> ans{digits};
    ans[i]++;
    while (ans[i] == 10) {
      ans[i--] = 0;
      if (i < 0) {
        ans.insert(ans.begin(), 1);
        break;
      }
      ans[i]++;
    }
    return ans;
  }
};

int main() {
  vector<int> v{9, 9, 9};
  cout << Solution().plusOne(v);
}
