#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result{};
        for (char d : digits) {
            vector<string> cur{};
            bool is_start = result.size() == 0;
            for (char ch : dir[d]) {
                if (is_start) {
                    string str;
                    str = ch;
                    cur.push_back(str);
                } else {
                    for (string str : result) {
                        cur.emplace_back(str + ch);
                    }
                }
            }
            result = cur;
        }
        return result;
    }
private:
    unordered_map<char, string> dir {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
        {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
        {'8', "tuv"}, {'9', "wxyz"}
    };
};

int main() {
    Solution s;
    auto result = s.letterCombinations("2");
    for (string s : result) {
        cout << s << endl;
    }
}
