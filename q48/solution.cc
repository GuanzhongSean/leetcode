#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> tmp(n, vector<int>(n));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) tmp[j][n - i - 1] = matrix[i][j];
    matrix = tmp;
  }
};

class Solution2 {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i <= n / 2; i++) {
      for (int j = i; j < n - 1 - i; j++) {
        int temp = matrix[i][j];
        matrix[i][j] = matrix[n - 1 - j][i];
        matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
        matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
        matrix[j][n - 1 - i] = temp;
      }
    }
  }
};

int main() {
  vector<vector<int>> matrix{
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9},
  };
  Solution{}.rotate(matrix);
  cout << "result: " << endl;
  for (auto v : matrix) {
    for (int x : v) {
      cout << x << " ";
    }
    cout << endl;
  }
}
