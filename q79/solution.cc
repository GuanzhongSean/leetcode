#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  bool dfs(vector<vector<char>> &board, string &word, int i, int j, int index,
           vector<vector<bool>> &record) {
    if (index == word.size())
      return true;
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
        board[i][j] != word[index] || record[i][j])
      return false;
    record[i][j] = true;
    if (dfs(board, word, i - 1, j, index + 1, record) ||
        dfs(board, word, i + 1, j, index + 1, record) ||
        dfs(board, word, i, j - 1, index + 1, record) ||
        dfs(board, word, i, j + 1, index + 1, record))
      return true;
    else {
      record[i][j] = false;
      return false;
    }
  }

public:
  bool exist(vector<vector<char>> &board, string word) {
    int n = board.size(), m = board[0].size();
    vector<vector<bool>> record(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (board[i][j] == word[0])
          if (dfs(board, word, i, j, 0, record))
            return true;
    return false;
  }
};

class Solution2 {
  string_view _str;
  int _lastIdx = 0;
  int _rows = 0, _cols = 0;
  vector<std::vector<char>> *_board = nullptr;
  bool dfs(int i, int j, int idx) {
    if (i < 0 || j < 0 || i == _rows || j == _cols ||
        (*_board)[i][j] != _str[idx])
      return false;

    if (idx == _lastIdx)
      return true;

    char restore = (*_board)[i][j];
    (*_board)[i][j] = '1';
    bool left = dfs(i, j - 1, idx + 1);
    bool right = dfs(i, j + 1, idx + 1);
    bool up = dfs(i - 1, j, idx + 1);
    bool down = dfs(i + 1, j, idx + 1);
    (*_board)[i][j] = restore;

    return left || right || up || down;
  }

public:
  bool exist(vector<vector<char>> &board, string word) {
    if (word.empty())
      return true;
    if (board.empty())
      return false;

    _str = word;
    _lastIdx = _str.size() - 1;

    _cols = board[0].size();
    _rows = board.size();

    _board = &board;

    // 'z'-'A'+1=122-65+1=58
    int freq[58] = {0};

    // check if word construction is even possible from the grid - complexity of
    // O(rows * columns) << O(4^(rows * columns))
    for (int i = 0; i < _rows; i++)
      for (int j = 0; j < _cols; j++)
        freq[board[i][j] - 'A']++;

    for (char c : _str)
      if (--freq[c - 'A'] < 0)
        return false;

    if (freq[word[0] - 'A'] > freq[word[_lastIdx] - 'A'])
      reverse(word.begin(), word.end());

    for (int i = 0; i < _rows; ++i)
      for (int j = 0; j < _cols; ++j)
        if (dfs(i, j, 0))
          return true;

    return false;
  }
};

int main() {
  vector<vector<char>> board{
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  cout << boolalpha << Solution().exist(board, "ABCCED") << endl;
}
