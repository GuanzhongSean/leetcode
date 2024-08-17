#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  string intToRoman(int num) {
    char dir[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    string result{};
    for (int i = 0; i < 4; i++) {
      if (num == 0) break;
      int d = num % 10;
      string fragment{};
      if (d < 4) {
        for (int j = 0; j < d; j++) fragment.push_back(dir[2 * i]);
      } else if (d == 4) {
        fragment.push_back(dir[2 * i]);
        fragment.push_back(dir[2 * i + 1]);
      } else if (d == 5) {
        fragment.push_back(dir[2 * i + 1]);
      } else if (d < 9) {
        fragment.push_back(dir[2 * i + 1]);
        for (int j = 0; j < d - 5; j++) fragment.push_back(dir[2 * i]);
      } else if (d == 9) {
        fragment.push_back(dir[2 * i]);
        fragment.push_back(dir[2 * i + 2]);
      }
      num /= 10;
      cout << fragment << endl;
      result = fragment + result;
    }
    return result;
  }
};

int main() {
  Solution s;
  string result = s.intToRoman(1994);
  cout << result << endl;
  cout << (result == "MCMXCIV") << endl;
}
