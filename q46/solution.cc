#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums, int from = 0) {
        vector<vector<int>> result{};
        if (from == nums.size() - 1) {
            result.push_back({nums[from]});
        } else {
            for (int i = from; i < nums.size(); i++) {
                swap(nums[i], nums[from]);
                vector<vector<int>> cur = permute(nums, from + 1);
                for (auto v : cur) {
                    v.push_back(nums[from]);
                    result.push_back(v);
                }
                swap(nums[i], nums[from]);
            }
        }
        return result;
    }
};

class Solution2 {
    void permutations(int idx, vector<int>& nums, vector<vector<int>>& ans) {
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);
            permutations(idx+1, nums, ans);
            swap(nums[idx], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permutations(0, nums, ans);
        return ans;
    }
};

int main() {
    vector<int> nums{1,2,3};
    auto result =  Solution{}.permute(nums);
    cout << "result: " << endl;
    for (auto v : result) {
        for (int x : v) {
            cout << x << " ";
        }
        cout << endl;
    }
}
