#include <vector>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> raw_dic(9, set<char>{});
        vector<set<char>> col_dic(9, set<char>{});
        vector<set<char>> sub_dic(9, set<char>{});
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char ch = board[i][j];
                if (ch == '.') continue;
                if (!raw_dic[i].insert(ch).second ||
                    !col_dic[j].insert(ch).second ||
                    !sub_dic[(i / 3) * 3 + j / 3].insert(ch).second)
                    return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<vector<char>> sudoku{
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    auto result =  s.isValidSudoku(sudoku);
    cout << result << endl;
}
