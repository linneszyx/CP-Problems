/*
 * @lc app=leetcode id=864 lang=cpp
 *
 * [864] Shortest Path to Get All Keys
 */

// @lc code=start
class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();
        int x, y;
        int keys = 0;
        int target = 0;
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<vector<int>> q;
        vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(64, false)));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '@') {
                    x = i;
                    y = j;
                } else if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                    target |= 1 << (grid[i][j] - 'a');
                }
            }
        }
        q.push({x, y, 0});
        visited[x][y][0] = true;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto cur = q.front();
                q.pop();
                if (cur[2] == target) return res;
                for (auto dir : dirs) {
                    int nx = cur[0] + dir[0];
                    int ny = cur[1] + dir[1];
                    int nkeys = cur[2];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == '#') continue;
                    if (grid[nx][ny] >= 'a' && grid[nx][ny] <= 'f') {
                        nkeys |= 1 << (grid[nx][ny] - 'a');
                    }
                    if (grid[nx][ny] >= 'A' && grid[nx][ny] <= 'F' && !(nkeys & (1 << (grid[nx][ny] - 'A')))) continue;
                    if (visited[nx][ny][nkeys]) continue;
                    visited[nx][ny][nkeys] = true;
                    q.push({nx, ny, nkeys});
                }
            }
            ++res;
        }
        return -1;
    }
};
// @lc code=end

