#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int totalNQueens(int n) {
    int ans = 0;
    dfs(n, 0, vector<bool>(n), vector<bool>(2 * n - 1), vector<bool>(2 * n - 1),
        ans);
    return ans;
  }

 private:
  void dfs(int n, int i, vector<bool> &&cols, vector<bool> &&diag1,
           vector<bool> &&diag2, int &ans) {
    if (i == n) {
      ++ans;
      return;
    }

    for (int j = 0; j < n; ++j) {
      if (cols[j] || diag1[i + j] || diag2[j - i + n - 1]) continue;
      cols[j] = diag1[i + j] = diag2[j - i + n - 1] = true;
      dfs(n, i + 1, std::move(cols), std::move(diag1), std::move(diag2), ans);
      cols[j] = diag1[i + j] = diag2[j - i + n - 1] = false;
    }
  }
};

class Solution2 {
 public:
  void solve(int col, int n, vector<string> &board, int &answer,
             vector<int> &leftRow, vector<int> &upperDiag,
             vector<int> &lowerDiag) {
    if (col == n) answer++;

    for (int row = 0; row < n; row++) {
      if (leftRow[row] == 0 && upperDiag[row + col] == 0 &&
          lowerDiag[n - 1 + col - row] == 0) {
        board[row][col] = 'Q';
        leftRow[row] = 1;
        upperDiag[row + col] = 1;
        lowerDiag[n - 1 + col - row] = 1;
        solve(col + 1, n, board, answer, leftRow, upperDiag, lowerDiag);
        leftRow[row] = 0;
        upperDiag[row + col] = 0;
        lowerDiag[n - 1 + col - row] = 0;
        board[row][col] = '.';
      }
    }
  }

  int totalNQueens(int n) {
    int col = 0, answer = 0;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++) board[i] = s;
    vector<int> leftRow(n, 0), upperDiag(2 * n - 1, 0), lowerDiag(2 * n - 1, 0);
    solve(col, n, board, answer, leftRow, upperDiag, lowerDiag);
    return answer;
  }
};

int main() { cout << Solution2().totalNQueens(4) << endl; }
