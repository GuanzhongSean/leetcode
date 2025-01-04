#ifndef _NODE_
#define _NODE_ 1

#include <climits>
#include <iostream>
#include <queue>
#include <vector>

namespace std {

struct Node {
    int val;
    Node* left;
    Node* right;
    Node* next;

    enum Sentinel { null = INT_MIN };

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
    Node(const vector<int>& from);
    ~Node() {
        delete left;
        delete right;
    };
    void print(ostream& os = cout, const string& prefix = "",
               bool isLeft = true) const;
};

ostream& operator<<(ostream& os, const Node* node);

}  // namespace std

namespace Random {

class Node {
   public:
    int val{0};
    Node* next{nullptr};
    Node* random{nullptr};

    enum Sentinel { null = INT_MIN };

    Node() = default;
    Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
    Node(int _val, Node* _next, Node* _random)
        : val(_val), next(_next), random(_random) {}
    Node(const std::vector<std::vector<int>>& from);
    virtual void print(std::ostream& os = std::cout) const;
};

std::ostream& operator<<(std::ostream& os, const Node* node);

}  // namespace Random

#endif
