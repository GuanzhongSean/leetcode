#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> L = lastOccuranceArray(needle);
        size_t n = haystack.size(), m = needle.size();
        int i = m - 1, j = m - 1;
        while (i < n && j >= 0) {
            if (haystack[i] == needle[j]) {
                i--; j--;
            } else {
                i = i + m - 1 - min(L[haystack[i]], j - 1);
                j = m - 1;
            }
        }
        if (j == -1) return i + 1;
        return -1;
        // return haystack.find(needle);
    }
private:
    vector<int> lastOccuranceArray(string pattern) {
        vector<int> array{};
        array.resize(255, -1);
        for (int i = 0; i < pattern.size(); i++) {
            char ch = pattern[i];
            array[ch] = i;
        }
        return array;
    }
};

int main() {
    Solution s;
    cout << s.strStr("sadbutsad", "bu") << endl;
}
