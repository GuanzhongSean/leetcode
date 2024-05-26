#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k) {
    int count = 0;
    int n = nums1.size();
    int m = nums2.size();

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (nums1[i] % (nums2[j] * k) == 0) {
          ++count;
        }
      }
    }
    return count;
  }
  string compressedString(string word) {
    string comp = "";
    int n = word.length();
    int i = 0;

    while (i < n) {
      char c = word[i];
      int count = 0;

      // Count the number of consecutive characters c, but not more than 9
      while (i < n && word[i] == c && count < 9) {
        ++i;
        ++count;
      }

      // Append the count and the character to the result
      comp += to_string(count) + c;
    }
    return comp;
  }
};

class Solution2 {
public:
  long long numberOfPairs(std::vector<int> &nums1, std::vector<int> &nums2,
                          int k) {
    std::unordered_map<int, int> productCount;

    // Calculate k * nums2[j] for all j and count frequencies
    for (int num : nums2) {
      int product = num * k;
      ++productCount[product];
    }

    long long count = 0;

    // Check each nums1[i] for divisibility by any k * nums2[j]
    for (int num : nums1) {
      for (int divisor = 1; divisor * divisor <= num; ++divisor) {
        if (num % divisor == 0) {
          // divisor is a valid divisor
          if (productCount.count(divisor)) {
            count += productCount[divisor];
          }
          // Check if num / divisor is a different number and also a valid
          // divisor
          int otherDivisor = num / divisor;
          if (otherDivisor != divisor && num % otherDivisor == 0) {
            if (productCount.count(otherDivisor)) {
              count += productCount[otherDivisor];
            }
          }
        }
      }
    }
    return count;
  }
  int maximumSumSubsequence(vector<int> &nums, vector<vector<int>> &queries) {
    int n = nums.size();
    const int MOD = 1e9 + 7;
    vector<long long> dp(n, 0);
    long long result = 0;
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        dp[0] = max(0, nums[0]);
      } else if (i == 1) {
        dp[1] = max(dp[0], (long long)nums[1]);
      } else {
        dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
      }
    }

    // Initialize for processing queries
    for (auto &query : queries) {
      int pos = query[0];
      int x = query[1];
      nums[pos] = x;
      for (int i = pos; i < n; i++) {
        if (i == 0) {
          dp[0] = max(0, nums[0]);
        } else if (i == 1) {
          dp[1] = max(dp[0], (long long)nums[1]);
        } else {
          dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }
      }
      result = (result + dp[n - 1]) % MOD;
    }

    return result;
  }
};
