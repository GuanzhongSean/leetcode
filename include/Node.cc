#include "Node.h"

Node::Node(vector<int> from) {
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

void Node::print(ostream &os, const string &prefix, bool isLeft) {
  if (right) right->print(os, prefix + (isLeft ? "│   " : "    "), false);
  os << prefix << (isLeft ? "└── " : "┌── ") << val;
  if (next) os << " => " << next->val;
  os << endl;
  if (left) left->print(os, prefix + (isLeft ? "    " : "│   "), true);
}

ostream &operator<<(ostream &os, Node *node) {
  if (node) node->print(os);
  return os;
}
