/*
 * @lc app=leetcode id=1970 lang=cpp
 *
 * [1970] Last Day Where You Can Still Cross
 */

// @lc code=start
class Solution {
public:
    bool check(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            if (grid[0][i] == 0) {
                q.push({0, i});
                vis[0][i] = 1;
            }
        }
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (x == n - 1) {
                return true;
            }
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && grid[nx][ny] == 0) {
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> grid(row, vector<int>(col, 0));
        int n = cells.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            for (int i = 0; i <= mid; ++i) {
                grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
            }
            if (check(grid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
            for (int i = 0; i <= mid; ++i) {
                grid[cells[i][0] - 1][cells[i][1] - 1] = 0;
            }
        }
        return l + 1;
    }
};
// @lc code=end

