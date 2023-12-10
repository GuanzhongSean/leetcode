#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int cur_max = 0;
        int left = 0;
        int right = height.size() - 1;
        while (right > left) {
            cur_max = max(cur_max, (right - left) * min(height[right], height[left]));
            if (height[right] < height[left]) {
                right--;
            } else {
                left++;
            }
        }
        return cur_max;
    }
};


int main() {
    Solution s;
    vector<int> test1 = {1,8,6,2,5,4,8,3,7};
    cout << s.maxArea(test1) << endl;
}
