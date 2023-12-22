#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        size_t k = nums.size();
        if (k < 2) return k;
        int j = 0;
        for(int i = 1; i < k; i++) {
            if (nums[i] != nums[j]) {
                j++;
                nums[j] = nums[i];
            }
        }
        return j + 1;
    }
};

int main() {
    Solution s;
    vector<int> nums{1, 2, 2, 2, 3, 4, 5, 5, 6, 7, 8};
    cout << s.removeDuplicates(nums) << endl;
    for (int i : nums) {
        cout << i << " ";
    }
    cout << endl;
}
