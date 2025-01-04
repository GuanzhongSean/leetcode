#include "TreeNode.h"

TreeNode::TreeNode(const std::vector<int> &from) {
    if (from.empty()) return;
    val = from[0];
    std::queue<TreeNode *> nodeQueue;
    nodeQueue.push(this);

    int i = 1;
    while (i < from.size()) {
        TreeNode *current = nodeQueue.front();
        nodeQueue.pop();

        if (from[i] != TreeNode::null) {
            current->left = new TreeNode(from[i]);
            nodeQueue.push(current->left);
        }
        i++;

        if (i < from.size() && from[i] != TreeNode::null) {
            current->right = new TreeNode(from[i]);
            nodeQueue.push(current->right);
        }
        i++;
    }
}

void TreeNode::print(std::ostream &os, const std::string &prefix, bool isLeft) const {
    if (right) right->print(os, prefix + (isLeft ? "│   " : "    "), false);
    os << prefix << (isLeft ? "└── " : "┌── ") << val << std::endl;
    if (left) left->print(os, prefix + (isLeft ? "    " : "│   "), true);
}

std::ostream &operator<<(std::ostream &os, const TreeNode *node) {
    if (node) node->print(os);
    return os;
}
