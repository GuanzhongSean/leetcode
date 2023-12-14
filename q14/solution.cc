#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        string result{};
        sort(v.begin(), v.end());
        int n = v.size();
        string first = v[0], last = v[n-1];
        for(int i = 0; i < min(first.size(), last.size()); i++){
            if(first[i] != last[i]){
                return result;
            }
            result.push_back(first[i]);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<string> strs{"","flow","flight"};
    auto result = s.longestCommonPrefix(strs);
    cout << result << endl;
    cout << (result == "") << endl;
}
