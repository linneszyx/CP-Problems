/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */

// @lc code=start
class Solution {
public:
    double helper(unordered_map<string, vector<pair<string, double>>>& graph, string s, string e, unordered_set<string>& visited) {
        if (!graph.count(s) || !graph.count(e)) return -1.0;
        if (s == e) return 1.0;
        visited.insert(s);
        for (auto& p : graph[s]) {
            if (visited.count(p.first)) continue;
            double t = helper(graph, p.first, e, visited);
            if (t > 0) return t * p.second;
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;
        for (int i = 0; i < equations.size(); ++i) {
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }
        vector<double> res;
        for (auto& q : queries) {
            unordered_set<string> visited;
            double t = helper(graph, q[0], q[1], visited);
            res.push_back(t);
        }
        return res;
    }
};
// @lc code=end

