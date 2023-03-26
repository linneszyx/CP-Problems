/*
 * @lc app=leetcode id=2360 lang=cpp
 *
 * [2360] Longest Cycle in a Graph
 */

// @lc code=start
class Solution
{
public:
    int ans = -1;
    void dfs(int i, vector<int> &edges, unordered_map<int, int> &dist, vector<bool> &visited)
    {
        visited[i] = true;
        int j = edges[i];
        if (j != -1 and !visited[j])
        {
            dist[j] = dist[i] + 1;
            dfs(j, edges, dist, visited);
        }
        else if (j != -1 and dist.count(j))
        {
            ans = max(ans, dist[i] - dist[j] + 1);
        }
    }
    int longestCycle(vector<int> &edges)
    {
        int n = edges.size();
        vector<bool> visited(n);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                unordered_map<int, int> dist;
                dist[i] = 1;
                dfs(i, edges, dist, visited);
            }
        }
        return ans;
    }
};
// @lc code=end
