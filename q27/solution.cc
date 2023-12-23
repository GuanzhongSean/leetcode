#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int b = 0;
        for (int i : nums) {
            if (i != val) nums[b++] = i;
        }
        return b;
    }
};

int main() {
    Solution s;
    vector<int> nums{1, 2, 2, 2, 3, 4, 5, 5, 6, 7, 8};
    cout << s.removeElement(nums, 2) << endl;
    for (int i : nums) {
        cout << i << " ";
    }
    cout << endl;
}
