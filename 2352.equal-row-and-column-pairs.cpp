/*
 * @lc app=leetcode id=2352 lang=cpp
 *
 * [2352] Equal Row and Column Pairs
 */

// @lc code=start
class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
       int ans = 0;
       map<vector<int>, int> m;
       for(int i=0;i<grid.size();i++) m[grid[i]]++;
       for(int j=0;j<grid[0].size();j++) {
              vector<int> v;
              for(int i=0;i<grid.size();i++) v.push_back(grid[i][j]);
              ans += m[v];
       }
         return ans;
    }
};
// @lc code=end
