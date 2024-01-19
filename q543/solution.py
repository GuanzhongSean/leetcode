# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def diameterOfBinaryTree(self, root):
        def diameterAndHeight(root):
            if root is None:
                return 0, 0
            ld, lh = diameterAndHeight(root.left)
            rd, rh = diameterAndHeight(root.right)
            d = lh + rh
            return max(ld, rd, d), max(lh, rh) + 1
        d, _ = diameterAndHeight(root)
        return d

d = Solution().diameterOfBinaryTree(TreeNode(0, TreeNode(0), TreeNode(0, TreeNode())))
print(d)
