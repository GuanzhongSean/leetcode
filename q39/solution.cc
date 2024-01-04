#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> ds;
        helper(0, target, candidates, ds, res);
        return res;
    }
private:
    void helper(int ind, int target, vector<int>& arr, vector<int>& ds, vector<vector<int>>& res){
        for (int i = ind; i < arr.size(); i++) {
            if (arr[i] > target) break;
            ds.push_back(arr[i]);
            if (target == arr[i])
                res.push_back(ds);
            else
                helper(i, target - arr[i], arr, ds, res);
            ds.pop_back();
        }
    }
};

class Solution2 {
public:
    void combine(vector<int>& candidates, int target, vector<vector<int>> &out, vector<int> &curr, int i, int n) {
        if(i == n) {
            if(target == 0)
                out.push_back(curr);
            return;
        }
        for(int j = candidates[i]; j <= target; j += candidates[i]) {
            curr.push_back(candidates[i]);
            combine(candidates, target - j, out, curr, i + 1, n);
        }
        for(int j = candidates[i]; j <= target; j += candidates[i])
            curr.pop_back();
        combine(candidates, target, out, curr, i + 1, n);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> out;
        vector<int> curr;
        combine(candidates, target, out, curr, 0, candidates.size());
        return out;
    }
};

int main() {
    Solution s;
    vector<int> candidates{8,7,4,3};
    auto result =  s.combinationSum(candidates, 11);
    for (auto v : result) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
}
