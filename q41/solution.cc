#include "../include/utils.h"
#include <unordered_map>

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) { // time: O(n), space: O(n)
        int n = nums.size();
        unordered_map<int, int> mp;

        for (auto num: nums) {
            if (1 <= num && num <= n)
                mp[num]++;
        }

        for (int i = 1; i <= n; i++) {
            if (mp[i] == 0)
                return i;
        }
        return n + 1;
    }
};

class Solution2 {
public:
    int firstMissingPositive(vector<int>& nums) { // time: O(n), space: O(1)
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0)
                nums[i] = n + 1;
        }
        print(nums);
        for (int i = 0; i < n; i++) {
            if (abs(nums[i]) <= n && nums[abs(nums[i]) - 1] > 0)
                nums[abs(nums[i]) - 1] *= -1;
        }
        print(nums);
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0)
                return i + 1;
        }
        return n + 1;
    }
};

int main() {
    Solution2 s;
    vector<int> nums{3,4,-1,1};
    auto result =  s.firstMissingPositive(nums);
    cout << result << endl;
}
