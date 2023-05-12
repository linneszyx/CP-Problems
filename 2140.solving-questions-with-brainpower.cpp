/*
 * @lc app=leetcode id=2140 lang=cpp
 *
 * [2140] Solving Questions With Brainpower
 */

// @lc code=start
class Solution
{
public:
    long long mostPoints(vector<vector<int>> &questions)
    {
        int n = questions.size();
        vector<long long> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            int p = questions[i][0];
            int q = questions[i][1];
            int x = min(n, i + q + 1);
            dp[i] = max(dp[i + 1], p + dp[x]);
        }
        return dp[0];
    }
};
// @lc code=end
