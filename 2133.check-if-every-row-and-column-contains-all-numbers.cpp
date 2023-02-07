/*
 * @lc app=leetcode id=2133 lang=cpp
 *
 * [2133] Check if Every Row and Column Contains All Numbers
 *
 * https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/description/
 *
 * algorithms
 * Easy (52.81%)
 * Likes:    698
 * Dislikes: 40
 * Total Accepted:    48.7K
 * Total Submissions: 92.4K
 * Testcase Example:  '[[1,2,3],[3,1,2],[2,3,1]]'
 *
 * An n x n matrix is valid if every row and every column contains all the
 * integers from 1 to n (inclusive).
 * 
 * Given an n x n integer matrix matrix, return true if the matrix is valid.
 * Otherwise, return false.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[1,2,3],[3,1,2],[2,3,1]]
 * Output: true
 * Explanation: In this case, n = 3, and every row and column contains the
 * numbers 1, 2, and 3.
 * Hence, we return true.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[1,1,1],[1,2,3],[1,2,3]]
 * Output: false
 * Explanation: In this case, n = 3, but the first row and the first column do
 * not contain the numbers 2 or 3.
 * Hence, we return false.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == matrix.length == matrix[i].length
 * 1 <= n <= 100
 * 1 <= matrix[i][j] <= n
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool check(vector<int> mat){
        sort(mat.begin(), mat.end());
        int n = mat.size();
        for (int i = 0; i < n; i++)
        {
            if(mat[i]!=i+1){
                return false;
            }
        }
        return true;        
    }
    bool checkValid(vector<vector<int>>& matrix) {
     int n = matrix.size();
     for (int i = 0; i < n; i++)
     {
        if(check(matrix[i])==false) {
            return false;
        }
     }
        for (int i = 0; i < n; i++)
        {
            vector<int> v;
            for(int j = 0; j < n; j++){
                v.push_back(matrix[j][i]);
            }
            if(check(v)==false) {
                return false;
            }
        }
    return true;
    }
};
// @lc code=end

