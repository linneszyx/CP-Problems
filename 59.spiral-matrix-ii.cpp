/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int m = n;
        vector<vector<int>> res(m, vector<int>(n, 0));
        int rowBegin = 0, rowEnd = m - 1;
        int colBegin = 0, colEnd = n - 1;
        int num = 1;
        while (rowBegin <= rowEnd && colBegin <= colEnd) {
            for (int j = colBegin; j <= colEnd; ++j) {
                res[rowBegin][j] = num++;
            }
            ++rowBegin;
            for (int i = rowBegin; i <= rowEnd; ++i) {
                res[i][colEnd] = num++;
            }
            --colEnd;
            if (rowBegin <= rowEnd) {
                for (int j = colEnd; j >= colBegin; --j) {
                    res[rowEnd][j] = num++;
                }
            }
            --rowEnd;
            if (colBegin <= colEnd) {
                for (int i = rowEnd; i >= rowBegin; --i) {
                    res[i][colBegin] = num++;
                }
            }
            ++colBegin;
        }
        return res;
    }
};
// @lc code=end

