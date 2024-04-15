#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int candy(std::vector<int> &ratings) {
    vector<int> A(ratings.size());
    vector<int> S(ratings.size(), 1);

    for (int i = 0; i < A.size(); i++) {
      A[i] = i;
    }

    sort(A.begin(), A.end(),
         [&](int i, int j) { return ratings[i] < ratings[j]; });

    int totalCandies = 0;
    for (int i = 0; i < A.size(); i++) {
      if (A[i] != A.size() - 1 && ratings[A[i]] > ratings[A[i] + 1])
        S[A[i]] = S[A[i] + 1] + 1;
      if (A[i] != 0 && ratings[A[i]] > ratings[A[i] - 1])
        S[A[i]] = std::max(S[A[i]], S[A[i] - 1] + 1);
    }
    for (int i : S)
      totalCandies += i;

    return totalCandies;
  }
};

int main() {
  vector<int> v{1, 0, 2};
  cout << Solution().candy(v) << endl;
}
