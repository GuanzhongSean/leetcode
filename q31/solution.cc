#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int last_ascend = -1, n = nums.size();
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                last_ascend = i - 1;
                break;
            }
        }
        if (last_ascend >= 0)
            for (int i = n - 1; i > last_ascend; i--) {
                if (nums[i] > nums[last_ascend]) {
                    swap(nums[i], nums[last_ascend]);
                    break;
                }
            }
        reverse(nums.begin() + last_ascend + 1, nums.end());
    }

    void nextPermutation2(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};

int main() {
    Solution s;
    vector<int> nums{4, 2, 3, 1};
    s.nextPermutation(nums);
    for (int i : nums) {
        cout << i << " ";
    }
    cout << endl;
}
