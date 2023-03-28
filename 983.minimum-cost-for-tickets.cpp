/*
 * @lc app=leetcode id=983 lang=cpp
 *
 * [983] Minimum Cost For Tickets
 */

// @lc code=start
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int now = 0;
        int n = days.size();
        int dp[366] = {0};
        for (int i = 1; i <= 365; i++) {
            if (now < n && i == days[now]) {
                dp[i] = min(dp[i - 1] + costs[0], min(dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2]));
                now++;
            } else {
                dp[i] = dp[i - 1];
            }
        }
        return dp[days.back()];
    }
};
// @lc code=end

