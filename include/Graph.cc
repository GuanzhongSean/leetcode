#include "Graph.h"

#include <cstddef>

void Graph::Node::print(ostream &os) const {
  os << val << " -> [ ";
  for (Node *neighbor : neighbors) {
    os << neighbor->val << " ";
  }
  os << "]" << std::endl;
}

Graph::Graph(const std::vector<std::vector<int>> &adjList) {
  for (size_t i = 0; i < adjList.size(); i++) {
    nodes.push_back(new Node(i + 1));
  }
  for (size_t i = 0; i < adjList.size(); i++) {
    for (size_t j = 0; j < adjList[i].size(); j++) {
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
