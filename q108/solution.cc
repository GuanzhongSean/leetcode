#include "TreeNode.h"

namespace q108 {

class Solution {
  TreeNode* sortedArrayToBST(vector<int>& nums, int begin, int end) {
    if (begin == end) return new TreeNode(nums[begin]);
    if (end < begin) return nullptr;
    int mid = (begin + end) / 2;
    return new TreeNode(nums[mid], sortedArrayToBST(nums, begin, mid - 1),
                        sortedArrayToBST(nums, mid + 1, end));
  }

 public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBST(nums, 0, nums.size() - 1);
  }
};

}  // namespace q108
