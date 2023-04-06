/*
 * @lc app=leetcode id=1254 lang=cpp
 *
 * [1254] Number of Closed Islands
 */

// @lc code=start
class Solution
{
public:
    bool dfs(vector<vector<int>> &grid, int i, int j)
    {
        int n = grid.size();
        int m = grid[0].size();
        if (i < 0 || i >= n || j < 0 || j >= m)
        {
            return false;
        }
        if (grid[i][j] == 1)
        {
            return true;
        }
        grid[i][j] = 1;
        bool ans = true;
        ans &= dfs(grid, i - 1, j);
        ans &= dfs(grid, i + 1, j);
        ans &= dfs(grid, i, j - 1);
        ans &= dfs(grid, i, j + 1);
        return ans;
    }
    int closedIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                {
                    if (dfs(grid, i, j))
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end
