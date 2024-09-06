#ifndef _NODE_
#define _NODE_ 1

#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

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
  Node(vector<int> from);
  ~Node() {
    delete left;
    delete right;
  };
  void print(ostream& os = cout, const string& prefix = "", bool isLeft = true);
};

ostream& operator<<(ostream& os, Node* node);

#endif
