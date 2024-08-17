#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int romanToInt(string s) {
    int result = 0;
    for (int i = 0; i < s.size(); i++) {
      int cur = dir[s[i]];
      if (i < s.size() - 1) {
        int next = dir[s[i + 1]];
        if (next > cur) {
          i++;
          result += next - cur;
          continue;
        }
      }
      result += cur;
    }
    return result;
  }

 private:
  unordered_map<char, int> dir{{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                               {'C', 100}, {'D', 500}, {'M', 1000}};
};

int main() {
  Solution s;
  int result = s.romanToInt("MCMXCIV");
  cout << result << endl;
  cout << (result == 1994) << endl;
}
