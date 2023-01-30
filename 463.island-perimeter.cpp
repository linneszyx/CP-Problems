/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 *
 * https://leetcode.com/problems/island-perimeter/description/
 *
 * algorithms
 * Easy (69.59%)
 * Likes:    5350
 * Dislikes: 263
 * Total Accepted:    417.4K
 * Total Submissions: 599.6K
 * Testcase Example:  '[[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]'
 *
 * You are given row x col grid representing a map where grid[i][j] = 1
 * represents land and grid[i][j] = 0 represents water.
 * 
 * Grid cells are connected horizontally/vertically (not diagonally). The grid
 * is completely surrounded by water, and there is exactly one island (i.e.,
 * one or more connected land cells).
 * 
 * The island doesn't have "lakes", meaning the water inside isn't connected to
 * the water around the island. One cell is a square with side length 1. The
 * grid is rectangular, width and height don't exceed 100. Determine the
 * perimeter of the island.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
 * Output: 16
 * Explanation: The perimeter is the 16 yellow stripes in the image above.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[1]]
 * Output: 4
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: grid = [[1,0]]
 * Output: 4
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * row == grid.length
 * col == grid[i].length
 * 1 <= row, col <= 100
 * grid[i][j] is 0 or 1.
 * There is exactly one island in grid.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int dir[5] = {0,1,0,-1,0};
   /**
    * For each cell, if it is an island, add 4 to the perimeter, and if it is not an island, do
    * nothing. For each neighbor of the cell that is an island, subtract 1 from the perimeter
    * 
    * @param grid the grid of the island
    * 
    * @return The perimeter of the island.
    */
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int peri = 0;
        int r,c;
        for(r=0;r<row;r++){
            for(c=0;c<col;c++){
                if(grid[r][c]==0) {
                    continue;
                }
                peri += 4;
                for(int i=0;i<4;i++){
                    int nr = r + dir[i];
                    int nc = c + dir[i+1];
                    if(nr<0 or nr==row or nc<0 or nc==col or grid[nr][nc]==0){
                        continue;
                    }
                    peri -= 1;
                }
            }
        }
        return peri;
    }
};
// @lc code=end

