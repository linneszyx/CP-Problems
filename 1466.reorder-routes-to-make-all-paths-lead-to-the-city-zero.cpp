/*
 * @lc app=leetcode id=1466 lang=cpp
 *
 * [1466] Reorder Routes to Make All Paths Lead to the City Zero
 */

// @lc code=start
class Solution
{
public:
    
    int dfs(vector<vector<int>> &graph, vector<bool> &visited, int from)
    {
       auto change = 0;
         visited[from] = true;
        for (auto to : graph[from])
        {
            if(!visited[abs(to)]){
                change += dfs(graph,visited,abs(to)) + (to > 0 ? 1 : 0);
                
            }
        }
        return change;
    }

    int minReorder(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> graph(n);
        for (auto &c : connections)
        {
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(-c[0]);
        }
        return dfs(graph,vector<bool>(n)={},0);
    }
};
// @lc code=end
