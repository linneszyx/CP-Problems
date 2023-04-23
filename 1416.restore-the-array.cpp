/*
 * @lc app=leetcode id=1416 lang=cpp
 *
 * [1416] Restore The Array
 */

// @lc code=start
class Solution {
public:
    int numberOfArrays(string s, int k) {
        int dp[s.size() + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') continue;
            long long num = 0;
            for (int j = i; j < s.size(); j++) {
                num = num * 10 + s[j] - '0';
                if (num > k) break;
                dp[j + 1] = (dp[j + 1] + dp[i]) % 1000000007;
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end

