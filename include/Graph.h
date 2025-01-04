#ifndef _GRAPH_
#define _GRAPH_ 1

#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using ostream = std::ostream;

class Graph {
   public:
    class Node {
       public:
        int val = 0;
        std::vector<Node*> neighbors{};
        Node(int _val) { val = _val; }
        Node(int _val, std::vector<Node*> _neighbors) {
            val = _val;
            neighbors = _neighbors;
        }
        void print(ostream& os = std::cout) const;
    };

    Graph(const std::vector<std::vector<int>>& adjList);
    ~Graph() {
        for (Node* node : nodes) {
            delete node;
        }
    }
    void print(ostream& os = std::cout) const;
    Node* operator[](int i) const { return nodes[i]; }
    Node* get(int i) const { return nodes[i]; }

   private:
    std::vector<Node*> nodes{};
};

ostream& operator<<(ostream& os, const Graph::Node* node);
ostream& operator<<(ostream& os, const Graph* graph);

#endif
