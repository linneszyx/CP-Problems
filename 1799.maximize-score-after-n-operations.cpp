/*
 * @lc app=leetcode id=1799 lang=cpp
 *
 * [1799] Maximize Score After N Operations
 */

// @lc code=start
class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(1 << n, vector<int>(n / 2 + 1, 0));
        for (int mask = 1; mask < (1 << n); ++mask) {
            int cnt = __builtin_popcount(mask);
            if (cnt % 2) continue;
            for (int i = 0; i < n; ++i) {
                if ((mask & (1 << i)) == 0) continue;
                for (int j = i + 1; j < n; ++j) {
                    if ((mask & (1 << j)) == 0) continue;
                    int new_mask = mask ^ (1 << i) ^ (1 << j);
                    int new_cnt = __builtin_popcount(new_mask);
                    dp[mask][cnt / 2] = max(dp[mask][cnt / 2], dp[new_mask][new_cnt / 2] + cnt / 2 * gcd(nums[i], nums[j]));
                }
            }
        }
        return dp[(1 << n) - 1][n / 2];
    }
};
// @lc code=end

