/*
 * @lc app=leetcode id=1575 lang=cpp
 *
 * [1575] Count All Possible Routes
 */

// @lc code=start
class Solution {
public:
    int dfs(vector<int>& locations, int start, int finish, int fuel, vector<vector<int>>& dp) {
        if (fuel < 0) return 0;
        if (dp[start][fuel] != -1) return dp[start][fuel];
        int res = start == finish;
        for (int i = 0; i < locations.size(); ++i) {
            if (i != start) {
                res = (res + dfs(locations, i, finish, fuel - abs(locations[start] - locations[i]), dp)) % 1000000007;
            }
        }
        return dp[start][fuel] = res;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>> dp(n, vector<int>(fuel + 1, -1));
        return dfs(locations, start, finish, fuel, dp);

    }
};
// @lc code=end

