#include <cstring>
#include <ios>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  int N = 50005;
  int MAX = 4 * 50005 + 5;
  int arr[50005];
  int tree[4 * 50005 + 5];
  int lazy[4 * 50005 + 5];

  void build_tree(int node, int a, int b) {
    if (a > b)
      return;
    if (a == b) {
      tree[node] = arr[a];
      return;
    }
    build_tree(node * 2, a, (a + b) / 2);
    build_tree(node * 2 + 1, 1 + (a + b) / 2, b);
    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
  }

  void update_tree(int node, int a, int b, int i, int j, int value) {
    if (lazy[node] != 0) {
      tree[node] += lazy[node];
      if (a != b) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
      }
      lazy[node] = 0;
    }
    if (a > b || a > j || b < i)
      return;
    if (a >= i && b <= j) {
      tree[node] += value;
      if (a != b) {
        lazy[node * 2] += value;
        lazy[node * 2 + 1] += value;
      }
      return;
    }
    update_tree(node * 2, a, (a + b) / 2, i, j, value);
    update_tree(1 + node * 2, 1 + (a + b) / 2, b, i, j, value);
    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
  }

  int query_tree(int node, int a, int b, int i, int j) {
    if (a > b || a > j || b < i)
      return -1e9;
    if (lazy[node] != 0) {
      tree[node] += lazy[node];
      if (a != b) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
      }
      lazy[node] = 0;
    }
    if (a >= i && b <= j)
      return tree[node];
    int q1 = query_tree(node * 2, a, (a + b) / 2, i, j);
    int q2 = query_tree(1 + node * 2, 1 + (a + b) / 2, b, i, j);
    int res = max(q1, q2);
    return res;
  }
  vector<bool> getResults(vector<vector<int>> &queries) {
    for (int i = 0; i < N; i++)
      arr[i] = i;
    build_tree(1, 0, N - 1);
    memset(lazy, 0, sizeof lazy);
    vector<bool> ans;
    set<int> st;
    st.insert(N - 1);
    for (auto &it : queries) {
      if (it[0] == 1) {
        int val = query_tree(1, 0, N - 1, it[1], it[1]);
        int nv = *st.lower_bound(it[1]);
        update_tree(1, 0, N - 1, it[1] + 1, nv, -1 * val);
        st.insert(it[1]);
      } else {
        int val = query_tree(1, 0, N - 1, 0, it[1]);
        if (val >= it[2])
          ans.push_back(1);
        else
          ans.push_back(0);
      }
    }
    return ans;
  }
};

int main() {
  vector<vector<int>> queries = {{1, 2}, {2, 3, 3}, {2, 3, 1}, {2, 2, 2}};
  vector<bool> result = Solution().getResults(queries);
  cout << boolalpha;
  for (bool b : result)
    cout << b << " ";
  cout << endl;
}
