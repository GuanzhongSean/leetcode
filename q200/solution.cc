#include "Utils.h"

namespace q200 {

using namespace std;

inline namespace V1 {
class Solution {
	size_t m, n;
	const vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	void dfs(vector<vector<char>>& grid, size_t x, size_t y) {
		for (auto [dx, dy] : directions) {
			size_t new_x = x + dx, new_y = y + dy;
			if (0 <= new_x && new_x < m && 0 <= new_y && new_y < n &&
				grid[new_x][new_y] == '1') {
				grid[new_x][new_y] = '0';
				dfs(grid, new_x, new_y);
			}
		}
	}

   public:
	int numIslands(vector<vector<char>>& grid) {
		m = grid.size();
		if (m < 1) throw runtime_error("Invalid grid.");
		n = grid[0].size();
		int count = 0;
		for (size_t i = 0; i < m; ++i) {
			for (size_t j = 0; j < n; ++j) {
				if (grid[i][j] == '1') {
					dfs(grid, i, j);
					count++;
				}
			}
		}
		return count;
	}
};
}  // namespace V1

}  // namespace q200
