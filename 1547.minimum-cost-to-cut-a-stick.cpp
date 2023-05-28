/*
 * @lc app=leetcode id=1547 lang=cpp
 *
 * [1547] Minimum Cost to Cut a Stick
 */

// @lc code=start
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
       int size = cuts.size();
       cuts.insert(cuts.begin(), 0);
         cuts.push_back(n);
         sort(cuts.begin(), cuts.end());
            vector<vector<int>> dp(size + 2, vector<int>(size + 2, 0));
            for (int i = size; i >= 0; i--) {
                for (int j = i + 1; j < size + 2; j++) {
                    for (int k = i + 1; k < j; k++) {
                        dp[i][j] = min(dp[i][j] == 0 ? INT_MAX : dp[i][j], dp[i][k] + dp[k][j] + cuts[j] - cuts[i]);
                    }
                }
            }
            return dp[0][size + 1];
        
    }
};
// @lc code=end

