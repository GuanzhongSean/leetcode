#include <unordered_map>

#include "Graph.h"

namespace q133 {

using namespace std;
using Node = Graph::Node;

class Solution {
 public:
  Node* cloneGraph(Node* node) {
    if (!node) return nullptr;
    unordered_map<Node*, Node*> visited;
    queue<Node*> q;
    q.push(node);
    visited[node] = new Node(node->val);
    while (!q.empty()) {
      Node* curr = q.front();
      q.pop();
      for (Node* neighbor : curr->neighbors) {
        if (!visited.count(neighbor)) {
          visited[neighbor] = new Node(neighbor->val);
          q.push(neighbor);
        }
        visited[curr]->neighbors.push_back(visited[neighbor]);
      }
    }
    return visited[node];
  }
};

}  // namespace q133
