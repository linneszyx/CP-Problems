/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 */

// @lc code=start
class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& color, int node) {
        for (int i = 0; i < graph[node].size(); ++i) {
            int next = graph[node][i];
            if (color[next] == 0) {
                color[next] = -color[node];
                if (!dfs(graph, color, next)) {
                    return false;
                }
            } else if (color[next] == color[node]) {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        bool status = true;
        vector<int> color(graph.size(), 0);
        for (int i = 0; i < graph.size(); ++i) {
            if (color[i] == 0) {
                color[i] = 1;
                status &= dfs(graph, color, i);
            }
        }
        return status;
    }
};
// @lc code=end

