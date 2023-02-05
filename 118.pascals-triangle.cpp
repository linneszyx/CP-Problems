/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (69.85%)
 * Likes:    8925
 * Dislikes: 297
 * Total Accepted:    1.1M
 * Total Submissions: 1.6M
 * Testcase Example:  '5'
 *
 * Given an integer numRows, return the first numRows of Pascal's triangle.
 *
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it as shown:
 *
 *
 * Example 1:
 * Input: numRows = 5
 * Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 * Example 2:
 * Input: numRows = 1
 * Output: [[1]]
 *
 *
 * Constraints:
 *
 *
 * 1 <= numRows <= 30
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int binomialCoeff(int n, int k)
    {
        int res = 1;
        if (k > n - k)
        {
            k = n - k;
        }
        for (int i = 0; i < k; i++)
        {
            res *= (n - i);
            res /= (i + 1);
        }
        return res;
    }
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res;
        for (int line = 0; line < numRows; line++)
        {
            vector<int> row;
            for (int i = 0; i <= line; i++)
            {
                row.push_back(binomialCoeff(line, i));
            }
            res.push_back(row);
        }
        return res;
    }
};
// @lc code=end
