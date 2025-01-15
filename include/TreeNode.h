#ifndef _TREE_NODE_
#define _TREE_NODE_ 1

#include <climits>
#include <iostream>
#include <queue>
#include <vector>

struct TreeNode {
	int val = 0;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;

	enum Sentinel { null = INT_MIN };

	TreeNode() : val(0) {}
	TreeNode(int x) : val(x) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
	TreeNode(const std::vector<int> &from);
	~TreeNode() {
		delete left;
		delete right;
	};
	void print(std::ostream &os = std::cout, const std::string &prefix = "",
			   bool isLeft = true) const;
	bool equals(TreeNode *other) const {
		return this == other ||
			   (other && val == other->val && left->equals(other->left) &&
				right->equals(other->right));
	}
};

std::ostream &operator<<(std::ostream &os, const TreeNode *node);

#endif
