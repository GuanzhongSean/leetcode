#include "../include/utils.h"

using namespace std;

class Solution {
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> start;
    for (int i = 0; i < k; i++)
      start.push_back(i + 1);

    int idx = 0;
    while (true) {
      if (start[idx] > n - k + idx + 1) {
        if (idx == 0)
          break;
        idx--;
        start[idx]++;
        for (int i = idx; i < k - 1; i++)
          start[i + 1] = start[i] + 1;
      } else if (idx < k - 1) {
        idx++;
      } else {
        result.push_back(start);
        start[idx]++;
      }
    }
    return result;
  }

public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> result{{}};
    int n = nums.size();
    for (int i = 1; i < n; i++) {
      vector<vector<int>> v = combine(n, i);
      for (vector<int> &e : v) {
        for (int &j : e)
          j = nums[j - 1];
      }
      result.insert(result.end(), v.begin(), v.end());
    }
    result.push_back(nums);
    return result;
  }
};

class Solution2 {
public:
  vector<vector<int>> output;
  int n, k;
  void backtrack(int first, vector<int> curr, vector<int> &nums) {
    // if the combination is done
    if (curr.size() == k) {
      output.push_back(curr);
      return;
    }

    for (int i = first; i < n; i++) {
      // add i into the current combination
      // cout << i << endl;
      curr.push_back(nums[i]);
      // use next integers to complete the combination
      backtrack(i + 1, curr, nums);
      // backtrack
      curr.pop_back();
    }
  }

  vector<vector<int>> subsets(vector<int> &nums) {
    n = nums.size();
    for (k = 0; k < n + 1; ++k) {
      vector<int> curr;
      backtrack(0, curr, nums);
    }
    return output;
  }
};

int main() {
  vector<int> v{2, 3, 4};
  cout << Solution().subsets(v);
}
