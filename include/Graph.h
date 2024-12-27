#ifndef _GRAPH_
#define _GRAPH_ 1

#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Graph {
 public:
  class Node {
   public:
    int val;
    vector<Node*> neighbors;
    Node() {
      val = 0;
      neighbors = vector<Node*>();
    }
    Node(int _val) {
      val = _val;
      neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
      val = _val;
      neighbors = _neighbors;
    }
    void print(ostream& os = cout) const;
  };

  Graph(vector<vector<int>> adjList);
  ~Graph() {
    for (Node* node : nodes) {
      delete node;
    }
  }
  void print(ostream& os = cout) const;
  Node* operator[](int i) const { return nodes[i]; }
  Node* get(int i) const { return nodes[i]; }

 private:
  vector<Node*> nodes{};
};

ostream& operator<<(ostream& os, Graph::Node* node);
ostream& operator<<(ostream& os, Graph* graph);

#endif
