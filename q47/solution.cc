#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    dfs(nums, vector<bool>(nums.size()), {}, ans);
    return ans;
  }

 private:
  void dfs(const vector<int>& nums, vector<bool>&& used, vector<int>&& path,
           vector<vector<int>>& ans) {
    if (path.size() == nums.size()) {
      ans.push_back(path);
      return;
    }

    for (int i = 0; i < nums.size(); ++i) {
      if (used[i])
        continue;
      if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
        continue;
      used[i] = true;
      path.push_back(nums[i]);
      dfs(nums, std::move(used), std::move(path), ans);
      path.pop_back();
      used[i] = false;
    }
  }
};

class Solution2 {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        do {
            res.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return res;
    }
};

class Solution3 {
    void permutations(int idx, vector<int>& nums, set<vector<int>>& ans) {
        if (idx == nums.size()) {
            ans.insert(nums);
            return;
        }
        for (int i = idx; i < nums.size(); i++) {
            if (i != 0 && (nums[i] == nums[i - 1] || nums[i] == nums[idx])) continue;
            swap(nums[idx], nums[i]);
            permutations(idx+1, nums, ans);
            swap(nums[idx], nums[i]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        permutations(0, nums, ans);
        vector<vector<int>> final_ans{ans.begin(), ans.end()};
        return final_ans;
    }
};

int main() {
    vector<int> nums{0,1,0,0,9};
    auto result =  Solution3{}.permuteUnique(nums);
    cout << "result: size: " << result.size() << endl;
    for (auto v : result) {
        for (int x : v) {
            cout << x << " ";
        }
        cout << endl;
    }
}
