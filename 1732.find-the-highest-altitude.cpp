/*
 * @lc app=leetcode id=1732 lang=cpp
 *
 * [1732] Find the Highest Altitude
 */

// @lc code=start
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int ans = 0;
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            cur += gain[i];
            ans = max(ans, cur);
        }
        return ans;
    }
};
// @lc code=end

