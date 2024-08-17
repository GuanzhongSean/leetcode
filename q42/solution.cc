#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  int trap(vector<int>& height) {  // add up horizontally
    stack<pair<int, int>> s;
    int n = height.size(), sum = 0;
    s.push({0, height[0]});
    for (int i = 1; i < n; i++) {
      int h = height[i];
      if (h == s.top().second)
        s.pop();
      else if (h > s.top().second) {
        int prev_height = s.top().second;
        s.pop();
        while (!s.empty()) {
          if (s.top().second <= h) {
            sum += (i - s.top().first - 1) * (s.top().second - prev_height);
            prev_height = s.top().second;
            s.pop();
          } else {
            sum += (i - s.top().first - 1) * (h - prev_height);
            break;
          }
        }
      }
      s.push({i, h});
    }
    return sum;
  }
};

class Solution2 {
 public:
  int trap(vector<int>& height) {  // add up vertically
    int n = height.size();
    int l = 0, r = n - 1;
    int leftmax = 0, rightmax = 0, ans = 0;
    while (l < r) {
      if (height[l] <= height[r]) {
        if (height[l] >= leftmax)
          leftmax = height[l];
        else
          ans += leftmax - height[l];
        l++;
      } else {
        if (height[r] >= rightmax)
          rightmax = height[r];
        else
          ans += rightmax - height[r];
        r--;
      }
    }
    return ans;
  }
};

int main() {
  vector<int> heights{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  auto result = Solution{}.trap(heights);
  cout << result << endl;
}
