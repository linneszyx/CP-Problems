/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 *
 * https://leetcode.com/problems/triangle/description/
 *
 * algorithms
 * Medium (54.17%)
 * Likes:    7559
 * Dislikes: 458
 * Total Accepted:    561.4K
 * Total Submissions: 1M
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * Given a triangle array, return the minimum path sum from top to bottom.
 * 
 * For each step, you may move to an adjacent number of the row below. More
 * formally, if you are on index i on the current row, you may move to either
 * index i or index i + 1 on the next row.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
 * Output: 11
 * Explanation: The triangle looks like:
 * ⁠  2
 * ⁠ 3 4
 * ⁠6 5 7
 * 4 1 8 3
 * The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined
 * above).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: triangle = [[-10]]
 * Output: -10
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= triangle.length <= 200
 * triangle[0].length == 1
 * triangle[i].length == triangle[i - 1].length + 1
 * -10^4 <= triangle[i][j] <= 10^4
 * 
 * 
 * 
 * Follow up: Could you do this using only O(n) extra space, where n is the
 * total number of rows in the triangle?
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
       for(int i=1;i<triangle.size();i++){
        for(int j=0;j<triangle[i].size();j++){
            if(j==0){
            triangle[i][j] += triangle[i-1][j];
            } 
            else if(j==triangle[i].size()-1) 
            triangle[i][j] += triangle[i-1][j-1];
            else triangle[i][j] += min(triangle[i-1][j-1],triangle[i-1][j]);
        }
       }
       int siz = triangle.size()-1;
    int res = *min_element(triangle[siz].begin(),triangle[siz].end());
    return  res;
    }
};
// @lc code=end

