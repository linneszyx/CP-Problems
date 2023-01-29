/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 *
 * https://leetcode.com/problems/max-area-of-island/description/
 *
 * algorithms
 * Medium (71.74%)
 * Likes:    8531
 * Dislikes: 191
 * Total Accepted:    671.2K
 * Total Submissions: 935.4K
 * Testcase Example:  '[[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]'
 *
 * You are given an m x n binary matrix grid. An island is a group of 1's
 * (representing land) connected 4-directionally (horizontal or vertical.) You
 * may assume all four edges of the grid are surrounded by water.
 * 
 * The area of an island is the number of cells with a value 1 in the island.
 * 
 * Return the maximum area of an island in grid. If there is no island, return
 * 0.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid =
 * [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
 * Output: 6
 * Explanation: The answer is not 11, because the island must be connected
 * 4-directionally.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[0,0,0,0,0,0,0,0]]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 50
 * grid[i][j] is either 0 or 1.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int bfs(int row,int col, vector<vector<int>> &vi,
          vector<vector<int>> &grid,int n,int m   
        )
        {
            vi[row][col] = 1;
            queue<pair<pair<int,int>,int>> q;
            q.push({{row,col},1});
            int ar = 1;
            int dr[] = {-1,0,+1,0};
            int dc[] = {0,+1,0,-1};
            while(!q.empty()){
                int row = q.front().first.first;
                int col = q.front().first.second;
                q.pop();
                for(int i =0;i<4;i++){
                    int nr = row + dr[i];
                    int nc = col + dc[i];
                    if(nr>=0 and nr<n and nc>=0 and nc<m and !vi[nr][nc] and grid[nr][nc]==1){
                        vi[nr][nc] = 1;
                        ar = ar + 1;
                        q.push({{nr,nc},ar});
                    }
                }
            }
            return ar;
        }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vi(n,vector<int>(m,0));
        int maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(!vi[i][j] and grid[i][j]==1){
                    int ar = bfs(i,j,vi,grid,n,m);
                    maxArea = max(ar,maxArea);
                }
            }
        }
        return maxArea;
    }
};
// @lc code=end

