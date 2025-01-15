#include <algorithm>
#include <iterator>
#include <stack>

#include "Utils.h"

namespace q105 {

class Solution {
   public:
	TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
		if (inorder.size() == 0) return nullptr;
		if (inorder.size() == 1) {
			preorder.erase(preorder.begin());
			return new TreeNode(inorder[0]);
		}
		int x = preorder[0];
		auto it = find(inorder.begin(), inorder.end(), x);
		if (it != inorder.end()) {
			preorder.erase(preorder.begin());
			int index = distance(inorder.begin(), it);
			TreeNode* result = new TreeNode(x);
			std::vector<int> left(inorder.begin(), inorder.begin() + index);
			result->left = buildTree(preorder, left);
			std::vector<int> right(inorder.begin() + index + 1, inorder.end());
			result->right = buildTree(preorder, right);
			return result;
		}
		return nullptr;
	}
};

class Solution2 {
   public:
	TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
		std::unordered_map<int, int> map;
		std::stack<std::pair<int, TreeNode*>> stk;
		for (int i = 0; i < inorder.size(); i++) map[inorder[i]] = i;

		TreeNode* root = new TreeNode(preorder[0]);
		TreeNode* parent = root;
		stk.push({map[preorder[0]], parent});
		for (int i = 1; i < preorder.size(); i++) {
			TreeNode* node = new TreeNode(preorder[i]);
			int index = map[preorder[i]];
			if (index < stk.top().first) {
				parent = stk.top().second;
				parent->left = node;
			} else {
				while (!stk.empty() && index > stk.top().first) {
					parent = stk.top().second;
					stk.pop();
				}
				parent->right = node;
			}
			stk.push({index, node});
		}
		return root;
	}
};

}  // namespace q105

int main() {
	std::vector<int> preorder{3, 9, 20, 15, 7};
	std::vector<int> inorder{9, 3, 15, 20, 7};
	auto result = q105::Solution().buildTree(preorder, inorder);
	print(result);
	delete result;
}
