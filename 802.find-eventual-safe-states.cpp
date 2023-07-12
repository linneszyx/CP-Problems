/*
 * @lc app=leetcode id=802 lang=cpp
 *
 * [802] Find Eventual Safe States
 */

// @lc code=start
class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int cur, vector<int>& color) {
        if (color[cur] > 0) return color[cur] == 2;
        color[cur] = 1;
        for (int i : graph[cur]) {
            if (color[i] == 2) continue;
            if (color[i] == 1 || !dfs(graph, i, color)) return false;
        }
        color[cur] = 2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> res;
        vector<int> color(graph.size(), 0);
        for (int i = 0; i < graph.size(); ++i) {
            if (dfs(graph, i, color)) res.push_back(i);
        }
        return res;
    }
};
// @lc code=end

