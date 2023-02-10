/*
 * @lc app=leetcode id=1162 lang=cpp
 *
 * [1162] As Far from Land as Possible
 *
 * https://leetcode.com/problems/as-far-from-land-as-possible/description/
 *
 * algorithms
 * Medium (48.49%)
 * Likes:    3253
 * Dislikes: 82
 * Total Accepted:    110K
 * Total Submissions: 218.4K
 * Testcase Example:  '[[1,0,1],[0,0,0],[1,0,1]]'
 *
 * Given an n x n grid containing only values 0 and 1, where 0 represents water
 * and 1 represents land, find a water cell such that its distance to the
 * nearest land cell is maximized, and return the distance. If no land or water
 * exists in the grid, return -1.
 *
 * The distance used in this problem is the Manhattan distance: the distance
 * between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
 * Output: 2
 * Explanation: The cell (1, 1) is as far as possible from all the land with
 * distance 2.
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
 * Output: 4
 * Explanation: The cell (2, 2) is as far as possible from all the land with
 * distance 4.
 *
 *
 *
 * Constraints:
 *
 *
 * n == grid.length
 * n == grid[i].length
 * 1 <= n <= 100
 * grid[i][j] is 0 or 1
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int maxDistance = -1;
        vector<pair<int, int>> lands;
        vector<pair<int, int>> waters;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    lands.emplace_back(i, j);
                }
                else
                {
                    waters.emplace_back(i, j);
                }
            }
        }
        if(lands.empty() || waters.empty()){
            return -1;
        }
        for(auto &water : waters){
            int minDistance = INT_MAX;
            for(auto &land : lands){
                int distance = abs(land.first - water.first) + abs(land.second - water.second);
                minDistance = min(minDistance,distance);
            }
            maxDistance = max(maxDistance,minDistance);
        }
        return maxDistance;
    }
};
// @lc code=end
