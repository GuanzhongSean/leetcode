#include <iostream>
#include <vector>

using namespace std;

class Solution {
  int row[9][9] = {}, col[9][9] = {}, box[9][9] = {};

  bool valid(int x, int y, int i) {
    return row[x][i] == 0 && col[y][i] == 0 && box[x / 3 * 3 + y / 3][i] == 0;
  }

  bool dfs(vector<vector<char>>& A, int x, int y) {
    if (y == 9) {
      ++x;
      y = 0;
    }
    if (x == 9) return true;
    if (A[x][y] == '.') {
      for (int i = 0; i < 9; ++i) {
        if (!valid(x, y, i)) continue;
        A[x][y] = '1' + i;
        row[x][i] = col[y][i] = box[x / 3 * 3 + y / 3][i] = 1;
        if (dfs(A, x, y + 1)) return true;
        row[x][i] = col[y][i] = box[x / 3 * 3 + y / 3][i] = 0;
        A[x][y] = '.';
      }
      return false;
    }
    return dfs(A, x, y + 1);
  }

 public:
  void solveSudoku(vector<vector<char>>& A) {
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        if (A[i][j] == '.') continue;
        row[i][A[i][j] - '1'] = 1;
        col[j][A[i][j] - '1'] = 1;
        box[i / 3 * 3 + j / 3][A[i][j] - '1'] = 1;
      }
    }
    dfs(A, 0, 0);
  }
};

int main() {
  Solution s;
  vector<vector<char>> sudoku{{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                              {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                              {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                              {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                              {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                              {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                              {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                              {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                              {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  s.solveSudoku(sudoku);
  for (auto v : sudoku) {
    for (char ch : v) {
      cout << ch << " ";
    }
    cout << endl;
  }
}
