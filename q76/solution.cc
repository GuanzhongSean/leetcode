#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string minWindow(string s, string t) {
    if (s.empty() || t.empty() || s.length() < t.length()) return "";

    vector<int> dict(128, 0);
    for (char c : t) dict[c]++;

    int left = 0, right = 0, count = 0;
    int minLen = s.size() + 1, minLeft;
    while (right < s.size()) {
      if (dict[s[right]] > 0) count++;
      dict[s[right]]--;
      right++;
      while (count == t.size()) {
        if (right - left < minLen) {
          minLen = right - left;
          minLeft = left;
        }
        if (dict[s[left]] == 0) count--;
        dict[s[left]]++;
        left++;
      }
    }
    return minLen == s.size() + 1 ? "" : s.substr(minLeft, minLen);
  }
};

int main() { cout << Solution().minWindow("ADOBECODEBANC", "ABC") << endl; }
