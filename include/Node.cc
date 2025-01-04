#include "Node.h"

#include <iostream>
#include <vector>

namespace std {

Node::Node(const vector<int> &from) {
    if (from.empty()) return;
    val = from[0];
    queue<Node *> nodeQueue;
    nodeQueue.push(this);

    int i = 1;
    while (i < from.size()) {
        Node *current = nodeQueue.front();
        nodeQueue.pop();

        if (from[i] != Node::null) {
            current->left = new Node(from[i]);
            nodeQueue.push(current->left);
        }
        i++;

        if (i < from.size() && from[i] != Node::null) {
            current->right = new Node(from[i]);
            nodeQueue.push(current->right);
        }
        i++;
    }
}

void Node::print(ostream &os, const string &prefix, bool isLeft) const {
    if (right) right->print(os, prefix + (isLeft ? "│   " : "    "), false);
    os << prefix << (isLeft ? "└── " : "┌── ") << val;
    if (next) os << " => " << next->val;
    os << endl;
    if (left) left->print(os, prefix + (isLeft ? "    " : "│   "), true);
}

ostream &operator<<(ostream &os, const Node *node) {
    if (node) node->print(os);
    return os;
}

}  // namespace std

namespace Random {

Node::Node(const std::vector<std::vector<int>> &from) {
    if (from.empty()) return;
    val = from[0][0];
    std::vector<Node *> dict{this};
    Node *prev = this;
    for (int i = 1; i < from.size(); i++) {
        Node *cur = new Node(from[i][0]);
        dict.push_back(cur);
        prev->next = cur;
        prev = cur;
    }
    for (int i = 0; i < from.size(); i++) {
        std::vector<int> row = from[i];
        Node *cur = dict[i];
        if (row[1] != null) {
            cur->random = dict[row[1]];
        }
    }
}

void Node::print(std::ostream &os) const {
    os << "[ (Random::Node): " << val
       << "(random: " << (random ? std::to_string(random->val) : "nullptr")
       << ") ";
    Node *cur = next;
    while (cur) {
        os << "-> " << cur->val << "(random: "
           << (cur->random ? std::to_string(cur->random->val) : "nullptr")
           << ") ";
        cur = cur->next;
    }
    os << "]" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Node *node) {
    if (node) node->print(os);
    return os;
}

}  // namespace Random
