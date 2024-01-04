#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> ds;
        helper(0, target, candidates, ds, res);
        return res;
    }
private:
    void helper(int ind, int target, vector<int>& arr, vector<int>& ds, vector<vector<int>>& res){
        for (int i = ind; i < arr.size(); i++) {
            if (i > ind && arr[i] == arr[i - 1]) continue;
            if (arr[i] > target) break;
            ds.push_back(arr[i]);
            if (target == arr[i])
                res.push_back(ds);
            else
                helper(i + 1, target - arr[i], arr, ds, res);
            ds.pop_back();
        }
    }
};

int main() {
    Solution s;
    vector<int> candidates(30, 1);
    auto result =  s.combinationSum2(candidates, 30);
    for (auto v : result) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
}
