/*
 * @lc app=leetcode id=879 lang=cpp
 *
 * [879] Profitable Schemes
 */

// @lc code=start
class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int x = group.size();
        vector<vector<vector<int>>> dp(x + 1, vector<vector<int>>(n + 1, vector<int>(minProfit + 1, 0)));
        dp[0][0][0] = 1;
        for (int i = 1; i <= x; i++) {
            int g = group[i - 1];
            int p = profit[i - 1];
            for (int j = 0; j <= n; j++) {
                for (int k = 0; k <= minProfit; k++) {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (j >= g) {
                        dp[i][j][k] += dp[i - 1][j - g][max(0, k - p)];
                        dp[i][j][k] %= 1000000007;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            ans += dp[x][i][minProfit];
            ans %= 1000000007;
        }
        return ans;
    }
};
// @lc code=end

