#include "Graph.h"

void Graph::Node::print(ostream &os) const {
  os << val << " -> [ ";
  for (Node *neighbor : neighbors) {
    os << neighbor->val << " ";
  }
  os << "]" << endl;
}

Graph::Graph(const vector<vector<int>> &adjList) {
  for (int i = 0; i < adjList.size(); i++) {
    nodes.push_back(new Node(i + 1));
  }
  for (int i = 0; i < adjList.size(); i++) {
    for (int j = 0; j < adjList[i].size(); j++) {
      nodes[i]->neighbors.push_back(nodes[adjList[i][j] - 1]);
    }
  }
}

void Graph::print(ostream &os) const {
  for (Node *node : nodes) {
    node->print(os);
  }
}

ostream &operator<<(ostream &os, const Graph::Node *node) {
  if (node) node->print(os);
  return os;
}

ostream &operator<<(ostream &os, const Graph *graph) {
  if (graph) graph->print(os);
  return os;
}
