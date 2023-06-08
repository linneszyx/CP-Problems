/*
 * @lc app=leetcode id=1351 lang=cpp
 *
 * [1351] Count Negative Numbers in a Sorted Matrix
 */

// @lc code=start
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        for (auto& row : grid) {
            for (auto& num : row) {
                if (num < 0) {
                    count++;
                }
            }
        }
        return count;
    }
};
// @lc code=end

