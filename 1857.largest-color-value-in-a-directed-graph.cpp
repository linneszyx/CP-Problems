/*
 * @lc app=leetcode id=1857 lang=cpp
 *
 * [1857] Largest Color Value in a Directed Graph
 */

// @lc code=start
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int x = colors.size();
        vector<vector<int>> g(x);
        vector<int> in(x);
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            in[e[1]]++;
        }
        vector<int> q;
        for (int i = 0; i < x; i++) {
            if (in[i] == 0) {
                q.push_back(i);
            }
        }
        vector<int> cnt(x);
        vector<vector<int>> dp(x, vector<int>(26));
        for (int i = 0; i < q.size(); i++) {
            int u = q[i];
            cnt[u]++;
            dp[u][colors[u] - 'a']++;
            for (int v : g[u]) {
                for (int j = 0; j < 26; j++) {
                    dp[v][j] = max(dp[v][j], dp[u][j]);
                }
                if (--in[v] == 0) {
                    q.push_back(v);
                }
            }
        }
        if (q.size() != x) {
            return -1;
        }
        int ans = 0;
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < 26; j++) {
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
// @lc code=end

