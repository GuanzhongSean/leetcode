#include <vector>

#include "utils.h"

using namespace std;

class Solution {
 public:
  vector<string> fullJustify(vector<string> &words, int maxWidth) {
    vector<string> res;
    int i = 0;
    while (i < words.size()) {
      int j = i + 1;
      int len = words[i].size();
      while (j < words.size()) {
        if (len + 1 + words[j].size() > maxWidth) break;
        len += 1 + words[j++].size();
      }
      string line = words[i];
      int diff = maxWidth - len;
      int gaps = j - i - 1;
      if (gaps == 0 || j == words.size()) {
        for (int k = i + 1; k < j; k++) {
          line += " " + words[k];
        }
        line += string(diff, ' ');
      } else {
        int space = diff / gaps;
        int extra = diff % gaps;
        for (int k = i + 1; k < j; k++)
          line += string(1 + space + (k - i - 1 < extra), ' ') + words[k];
      }
      res.push_back(line);
      i = j;
    }
    return res;
  }
};

int main() {
  vector<string> words = {"This",          "is", "an", "example", "of", "text",
                          "justification."};
  vector<string> result = Solution().fullJustify(words, 16);
  for (auto &s : result) {
    cout << s << "|" << endl;
  }
}
