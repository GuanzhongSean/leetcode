#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int l = 0, r = matrix.size() * matrix[0].size() - 1, m;
    while (l <= r) {
      m = (l + r) / 2;
      int i = m / matrix[0].size(), j = m % matrix[0].size();
      if (matrix[i][j] == target)
        return true;
      else if (matrix[i][j] > target)
        r = m - 1;
      else
        l = m + 1;
    }
    return false;
  }
};

int main() {
  vector<vector<int>> matrix{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
  cout << Solution().searchMatrix(matrix, 3) << endl;
}
