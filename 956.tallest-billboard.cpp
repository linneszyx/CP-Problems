/*
 * @lc app=leetcode id=956 lang=cpp
 *
 * [956] Tallest Billboard
 */

// @lc code=start
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
         int n = rods.size();
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += rods[i];
        }
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        dp[0][0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int d = 0; d <= sum; ++d) {
                if (dp[i][d] < 0) continue;
                dp[i + 1][d] = max(dp[i + 1][d], dp[i][d]);
                if (d + rods[i] <= sum) {
                    dp[i + 1][d + rods[i]] = max(dp[i + 1][d + rods[i]], dp[i][d] + rods[i]);
                }
                if (d >= rods[i]) {
                    dp[i + 1][d - rods[i]] = max(dp[i + 1][d - rods[i]], dp[i][d]);
                } else {
                    dp[i + 1][rods[i] - d] = max(dp[i + 1][rods[i] - d], dp[i][d] + rods[i] - d);
                }
            }
        }
        return dp[n][0];
    }
};
// @lc code=end

