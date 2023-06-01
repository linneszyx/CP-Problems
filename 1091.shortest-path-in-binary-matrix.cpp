/*
 * @lc app=leetcode id=1091 lang=cpp
 *
 * [1091] Shortest Path in Binary Matrix
 */

// @lc code=start
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        if (n == 1) return 1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        int ans = 1;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [x, y] = q.front();
                q.pop();
                if (x == n-1 && y == n-1) return ans;
                for (int i = -1; i <= 1; ++i) {
                    for (int j = -1; j <=1; ++j) {
                        if (i == 0 && j == 0) continue;
                        int nx = x + i, ny = y + j;
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n || grid[nx][ny] == 1) continue;
                        q.push({nx, ny});
                        grid[nx][ny] = 1;
                    }
                }
            }
            ++ans;
        }
        return -1;
    }
};
// @lc code=end

