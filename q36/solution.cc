#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    vector<vector<bool>> raw_dic(9, vector<bool>(9, false));
    vector<vector<bool>> col_dic(9, vector<bool>(9, false));
    vector<vector<bool>> sub_dic(9, vector<bool>(9, false));
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        char ch = board[i][j];
        if (ch == '.') continue;
        if (raw_dic[i][ch - '1'] || col_dic[j][ch - '1'] ||
            sub_dic[(i / 3) * 3 + j / 3][ch - '1'])
          return false;
        else {
          raw_dic[i][ch - '1'] = true;
          col_dic[j][ch - '1'] = true;
          sub_dic[(i / 3) * 3 + j / 3][ch - '1'] = true;
        }
      }
    }
    return true;
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
  auto result = s.isValidSudoku(sudoku);
  cout << result << endl;
}
