/*
 * @lc app=leetcode id=1027 lang=cpp
 *
 * [1027] Longest Arithmetic Subsequence
 */

// @lc code=start
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n);
        if(n<=2) return n;
        int longest = 2;
        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                int diff = nums[i] - nums[j];
                if(dp[j].find(diff) != dp[j].end()) {
                    dp[i][diff] = dp[j][diff] + 1;
                } else {
                    dp[i][diff] = 2;
                }
                longest = max(longest, dp[i][diff]);
            }
        }
        return longest;
    }
};
// @lc code=end

