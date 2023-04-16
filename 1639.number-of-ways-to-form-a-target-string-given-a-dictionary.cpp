/*
 * @lc app=leetcode id=1639 lang=cpp
 *
 * [1639] Number of Ways to Form a Target String Given a Dictionary
 */

// @lc code=start
class Solution
{
public:
    int numWays(vector<string> &words, string target)
    {
        int mod = 1e9 + 7;
        int m = words.size();
        int n = words[0].size();
        vector<vector<int>> freq(n, vector<int>(26, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                freq[j][words[i][j] - 'a']++;
            }
        }
        vector<long long> dp(target.size() + 1, 0);
        dp[0] = 1;
        for (int j = 0; j < n; j++)
        {
            for (int i = target.size(); i > 0; i--)
            {
                dp[i] = (dp[i] + dp[i - 1] * freq[j][target[i - 1] - 'a']) % mod;
            }
        }
        return dp[target.size()];
    }
};
// @lc code=end
