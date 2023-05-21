/*
 * @lc app=leetcode id=934 lang=cpp
 *
 * [934] Shortest Bridge
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, queue<pair<int, int>>& q) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || !grid[i][j]) return;
        grid[i][j] = 0;
        q.push({i, j});
        dfs(grid, i + 1, j, q);
        dfs(grid, i - 1, j, q);
        dfs(grid, i, j + 1, q);
        dfs(grid, i, j - 1, q);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        bool found = false;
        for (int i = 0; i < m && !found; ++i) {
            for (int j = 0; j < n && !found; ++j) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, q);
                    found = true;
                }
            }
        }
        vector<vector<int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto p = q.front();
                q.pop();
                for (auto& dir : dirs) {
                    int x = p.first + dir[0];
                    int y = p.second + dir[1];
                    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 2) continue;
                    if (grid[x][y] == 1) return ans;
                    grid[x][y] = 2;
                    q.push({x, y});
                }
            }
            ++ans;
        }
        return -1;
    }
};
// @lc code=end

