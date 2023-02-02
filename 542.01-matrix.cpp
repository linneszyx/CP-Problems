/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 *
 * https://leetcode.com/problems/01-matrix/description/
 *
 * algorithms
 * Medium (44.38%)
 * Likes:    6474
 * Dislikes: 311
 * Total Accepted:    351.2K
 * Total Submissions: 789.6K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * Given an m x n binary matrix mat, return the distance of the nearest 0 for
 * each cell.
 * 
 * The distance between two adjacent cells is 1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
 * Output: [[0,0,0],[0,1,0],[0,0,0]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
 * Output: [[0,0,0],[0,1,0],[1,2,1]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 10^4
 * 1 <= m * n <= 10^4
 * mat[i][j] is either 0 or 1.
 * There is at least one 0 in mat.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        int m = mat.size();
        int n = mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0) q.push({i,j});
                else mat[i][j] = -1;
            }
        }
        vector<int> dp = {-1,0,1,0,-1};
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                pair<int,int> p = q.front();
                q.pop();
                for(int j=0;j<4;j++){
                    int r = p.first + dp[j];
                    int c = p.second + dp[j+1];
                    if(r>=0 and c>=0 and r<m and c<n and mat[r][c]==-1){
                        mat[r][c] = 1 + mat[p.first][p.second];
                        q.push({r,c});
                    }
                }
            }
        }
        return mat;
    }
};
// @lc code=end

