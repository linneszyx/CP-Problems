/*
 * @lc app=leetcode id=688 lang=cpp
 *
 * [688] Knight Probability in Chessboard
 */

// @lc code=start
class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> dp(n, vector<double>(n, 0));
        dp[row][column] = 1;
        vector<vector<int>> dirs = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
                                    {1, -2}, {1, 2}, {2, -1}, {2, 1}};
        for (int step = 0; step < k; ++step) {
            vector<vector<double>> dp2(n, vector<double>(n, 0));
            for (int r = 0; r < n; ++r) {
                for (int c = 0; c < n; ++c) {
                    for (auto& dir : dirs) {
                        int x = r + dir[0];
                        int y = c + dir[1];
                        if (x >= 0 && x < n && y >= 0 && y < n) {
                            dp2[x][y] += dp[r][c] / 8.0;
                        }
                    }
                }
            }
            dp = dp2;
        }
        double ans = 0;
        for (auto& row : dp) {
            for (auto& x : row) {
                ans += x;
            }
        }
        return ans;
    }
};
// @lc code=end

