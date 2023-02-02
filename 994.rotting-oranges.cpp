/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 *
 * https://leetcode.com/problems/rotting-oranges/description/
 *
 * algorithms
 * Medium (52.68%)
 * Likes:    9565
 * Dislikes: 329
 * Total Accepted:    553K
 * Total Submissions: 1M
 * Testcase Example:  '[[2,1,1],[1,1,0],[0,1,1]]'
 *
 * You are given an m x n grid where each cell can have one of three
 * values:
 *
 *
 * 0 representing an empty cell,
 * 1 representing a fresh orange, or
 * 2 representing a rotten orange.
 *
 *
 * Every minute, any fresh orange that is 4-directionally adjacent to a rotten
 * orange becomes rotten.
 *
 * Return the minimum number of minutes that must elapse until no cell has a
 * fresh orange. If this is impossible, return -1.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
 * Output: 4
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
 * Output: -1
 * Explanation: The orange in the bottom left corner (row 2, column 0) is never
 * rotten, because rotting only happens 4-directionally.
 *
 *
 * Example 3:
 *
 *
 * Input: grid = [[0,2]]
 * Output: 0
 * Explanation: Since there are already no fresh oranges at minute 0, the
 * answer is just 0.
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 10
 * grid[i][j] is 0, 1, or 2.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<pair<int, int>, int>> q;
        int rows = grid.size();
        int cols = grid[0].size();
        int count_of_one = 0;
        /* This is to count the number of 1's in the grid. */
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == 2)
                    q.push({{i, j}, 0});
                if(grid[i][j] == 1)
                    count_of_one++;
            }
        }
        if(count_of_one == 0) return 0;
        if(q.empty()) return -1;`
        /* This is to create a copy of the grid. */
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                visited[i][j] = grid[i][j];
            }
        }
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        int time = 0;
       /* This is the BFS part. */
        while(!q.empty())
        {
            pair<pair<int, int>, int> p = q.front();
            q.pop();
            pair<int, int> index = p.first;
            time = p.second;

            for(int i = 0; i < 4; i++)
            {
                int newRow = delRow[i] + index.first;
                int newCol = delCol[i] + index.second;

               /* This is to check if the newRow and newCol are within the grid and if the newRow and
               newCol are not visited and not rotten. */
                if(newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && visited[newRow][newCol] != 2 && visited[newRow][newCol] != 0)
                {
                    q.push({{newRow, newCol}, time+1});
                    visited[newRow][newCol] = 2;
                }
            }
        }
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0;  j < cols; j++)
            {
                if(visited[i][j] == 1)
                    return -1;
            }
        }
        return time;
    }
};
// @lc code=end
