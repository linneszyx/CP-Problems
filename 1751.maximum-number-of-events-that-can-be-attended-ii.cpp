/*
 * @lc app=leetcode id=1751 lang=cpp
 *
 * [1751] Maximum Number of Events That Can Be Attended II
 */

// @lc code=start
class Solution {
public:
vector<vector<int>> dp;
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n = events.size();
        dp.resize(n, vector<int>(k+1, -1));
        return solve(events, 0, k,0);
    }
    int solve(vector<vector<int>> &events,int i,int k,int end){
        if(i==events.size() || k==0) return 0;
        if(k==0) return 0;
        if(events[i][0]<=end) return solve(events, i+1, k, end);
        if(dp[i][k]!=-1) return dp[i][k];
        int take = events[i][2] + solve(events, i+1, k-1, events[i][1]);
        int notTake = solve(events, i+1, k, end);
        return dp[i][k] = max(take, notTake);
    }
};
// @lc code=end

