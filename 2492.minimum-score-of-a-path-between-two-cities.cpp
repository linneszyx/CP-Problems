/*
 * @lc app=leetcode id=2492 lang=cpp
 *
 * [2492] Minimum Score of a Path Between Two Cities
 */

// @lc code=start
class Solution
{
public:
    int minScore(int n, vector<vector<int>> &roads)
    {
        int ans = INT_MAX;
        vector<vector<pair<int, int>>> graph(n + 1);
        for (auto &road : roads)
        {
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});
        }
        vector<int> dist(n + 1, 0);
        queue<int> q;
        q.push(1);
        dist[1] = 1;
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            for (auto &[v, dis] : graph[node])
            {
                ans = min(ans, dis);
                if (dist[v] == 0)
                {
                    dist[v] = 1;
                    q.push(v);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
