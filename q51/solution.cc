#include <iostream>
#include <vector>

#include "../include/utils.h"

using namespace std;

class Solution {
 public:
  void solve(int col, int n, vector<string> &board,
             vector<vector<string>> &answer, vector<int> &leftRow,
             vector<int> &upperDiag, vector<int> &lowerDiag) {
    if (col == n) answer.push_back(board);

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

  vector<vector<string>> solveNQueens(int n) {
    int col = 0;
    vector<vector<string>> answer;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++) board[i] = s;
    vector<int> leftRow(n, 0), upperDiag(2 * n - 1, 0), lowerDiag(2 * n - 1, 0);
    solve(col, n, board, answer, leftRow, upperDiag, lowerDiag);
    return answer;
  }
};

int main() { cout << Solution().solveNQueens(4); }
