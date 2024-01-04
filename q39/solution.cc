#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return helper(candidates, target, 0);
    }
private:
    vector<vector<int>> helper(vector<int>& candidates, int target, int start) {
        vector<vector<int>> results{};
        if ((candidates[start] > target && candidates[start] > 0) ||
            (candidates.back() < target && candidates.back() < 0)) return results;
        for (int i = start; i < candidates.size(); i++) {
            int x = candidates[i];
            vector<vector<int>> vv = helper(candidates, target - x, i);
            for (auto v : vv) {
                v.emplace_back(x);
                results.emplace_back(v);
            }
            if (x == target)
                results.emplace_back(vector<int>{x});
        }
        return results;
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
