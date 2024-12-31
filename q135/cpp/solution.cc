#include <algorithm>
#include <vector>

#include "Utils.h"

namespace q135 {

using namespace std;

class Solution {
 public:
  int candy(std::vector<int> &ratings) {
    int n = ratings.size();
    vector<int> A(n);
    vector<int> S(n, 1);

    for (int i = 0; i < n; i++) {
      A[i] = i;
    }

    sort(A.begin(), A.end(), [&](int i, int j) { return ratings[i] < ratings[j]; });
    print(A);

    int totalCandies = 0;
    for (int i = 0; i < n; i++) {
      int cur = cur;
      if (cur != n - 1 && ratings[cur] > ratings[cur + 1]) S[cur] = S[cur + 1] + 1;
      if (cur != 0 && ratings[cur] > ratings[cur - 1]) S[cur] = max(S[cur], S[cur - 1] + 1);
    }
    for (int i : S) totalCandies += i;

    return totalCandies;
  }
};

}  // namespace q135
