#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string simplifyPath(string path) {
    if (path[0] != '/')
      return "";
    vector<string> names;
    int i = 1;
    string name = "";
    while (i <= path.size()) {
      if (i == path.size() || path[i] == '/') {
        if (name == "..") {
          if (!names.empty())
            names.pop_back();
        } else if (name != "" && name != ".") {
          names.push_back(name);
        }
        name = "";
        i++;
        continue;
      }
      name += path[i++];
    }
    string result = "/";
    for (int i = 0; i < names.size(); i++) {
      result += names[i];
      if (i != names.size() - 1)
        result += "/";
    }
    return result;
  }
};

int main() {
  cout << Solution().simplifyPath("/home/user/Documents/../Pictures") << endl;
}
