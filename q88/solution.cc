#include <vector>

#include "utils.h"

using namespace std;

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0) {
      if (nums1[i] > nums2[j]) {
        nums1[k--] = nums1[i--];
      } else {
        nums1[k--] = nums2[j--];
      }
    }
    while (j >= 0) {
      nums1[k--] = nums2[j--];
    }
    while (i >= 0) {
      nums1[k--] = nums1[i--];
    }
  }
};

auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << boolalpha;
  return '$';
}();

int main() {
  vector<int> num1 = {1, 2, 3, 0, 0, 0};
  vector<int> num2 = {2, 5, 6};
  Solution().merge(num1, 3, num2, 3);
  print(num1);
}
