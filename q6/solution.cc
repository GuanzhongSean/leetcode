#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows == 1) return s;
    unsigned cur_line = 0;
    bool direction = true;
    vector<string> lines{};
    lines.resize(numRows, "");
    for (unsigned i = 0; i < s.size(); i++) {
      char ch = s[i];
      lines[cur_line].push_back(ch);
      if (cur_line == 0) {
        direction = true;
        cur_line++;
      } else if (cur_line == numRows - 1) {
        direction = false;
        cur_line--;
      } else {
        if (direction)
          cur_line++;
        else
          cur_line--;
      }
    }
    string zigzag{};
    for (string str : lines) {
      zigzag += str;
    }
    return zigzag;
  }
};

int main() {
  Solution s;
  cout << s.convert("PAYPALISHIRING", 3) << endl;
  if (s.convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR")
    cout << "true" << endl;
}
