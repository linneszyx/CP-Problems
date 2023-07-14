/*
 * @lc app=leetcode id=1218 lang=cpp
 *
 * [1218] Longest Arithmetic Subsequence of Given Difference
 */

// @lc code=start
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int res = 0;
        unordered_map<int, int> dp;
        for (int i = 0; i < arr.size(); ++i) {
            dp[arr[i]] = dp[arr[i] - difference] + 1;
            res = max(res, dp[arr[i]]);
        }
        return res;
    }
};
// @lc code=end

