/*
 * @lc app=leetcode id=1514 lang=cpp
 *
 * [1514] Path with Maximum Probability
 */

// @lc code=start
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // Build graph
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); ++i) {
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        // Dijkstra
        vector<double> prob(n, 0);
        prob[start] = 1;
        priority_queue<pair<double, int>> pq;
        pq.push({1, start});
        while (!pq.empty()) {
            auto [p, u] = pq.top();
            pq.pop();
            if (p < prob[u]) continue;
            for (auto [v, w] : graph[u]) {
                if (prob[u] * w > prob[v]) {
                    prob[v] = prob[u] * w;
                    pq.push({prob[v], v});
                }
            }
        }
        return prob[end];
    }
};
// @lc code=end

