#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  string getPermutation(int n, int k) {
    string ans(n, '0');
    for (int i = 1; i <= n; ++i) ans[i - 1] = '0' + i;
    for (int i = 1; i < k; ++i) next_permutation(ans.begin(), ans.end());
    return ans;
  }
};

class Solution2 {
 public:
  string getPermutation(int n, int k) {
    int fact = 1;
    vector<int> numbers;
    for (int i = 1; i < n; i++) {
      fact = fact * i;
      numbers.push_back(i);
    }
    numbers.push_back(n);
    string ans = "";
    k = k - 1;
    while (true) {
      ans = ans + to_string(numbers[k / fact]);
      numbers.erase(numbers.begin() + k / fact);
      if (numbers.size() == 0) break;
      k = k % fact;
      fact = fact / numbers.size();
    }
    return ans;
  }
};

int main() { cout << Solution2().getPermutation(5, 3) << endl; }
