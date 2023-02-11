/*
 * @lc app=leetcode id=1129 lang=cpp
 *
 * [1129] Shortest Path with Alternating Colors
 *
 * https://leetcode.com/problems/shortest-path-with-alternating-colors/description/
 *
 * algorithms
 * Medium (42.93%)
 * Likes:    2293
 * Dislikes: 108
 * Total Accepted:    63.5K
 * Total Submissions: 140.4K
 * Testcase Example:  '3\n[[0,1],[1,2]]\n[]'
 *
 * You are given an integer n, the number of nodes in a directed graph where
 * the nodes are labeled from 0 to n - 1. Each edge is red or blue in this
 * graph, and there could be self-edges and parallel edges.
 *
 * You are given two arrays redEdges and blueEdges where:
 *
 *
 * redEdges[i] = [ai, bi] indicates that there is a directed red edge from node
 * ai to node bi in the graph, and
 * blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from
 * node uj to node vj in the graph.
 *
 *
 * Return an array answer of length n, where each answer[x] is the length of
 * the shortest path from node 0 to node x such that the edge colors alternate
 * along the path, or -1 if such a path does not exist.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 3, redEdges = [[0,1],[1,2]], blueEdges = []
 * Output: [0,1,-1]
 *
 *
 * Example 2:
 *
 *
 * Input: n = 3, redEdges = [[0,1]], blueEdges = [[2,1]]
 * Output: [0,1,-1]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 100
 * 0 <= redEdges.length, blueEdges.length <= 400
 * redEdges[i].length == blueEdges[j].length == 2
 * 0 <= ai, bi, uj, vj < n
 *
 *
 */

// @lc code=start
class Solution
{
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        vector<int> res(n, -1);
        vector<int> v1(n, 0);
        vector<int> v2(n, 0);
        vector<vector<pair<int, int>>> v(n);
        queue<pair<int, int>> q;
        for (auto &it : redEdges)
        {
            v[it[0]].push_back({it[1], 1});
        }
        for (auto &it : blueEdges)
        {
            v[it[0]].push_back({it[1], 2});
        }
        res[0] = 0;
        v1[0] = 1;
        v2[0] = 1;
        int temp = 1;
        /* This is the first step of BFS. */
        for (auto &it : v[0])
        {
            q.push(it);
            if (res[it.first] == -1)
            {
                res[it.first] = temp;
            }
        }
       /* Doing BFS. */
        while (!q.empty())
        {
            int len = q.size();
            temp++;
            for (int i = 0; i < len; i++)
            {
                auto val = q.front();
                q.pop();
                if (val.second == 1)
                {
                    v1[val.first] = 1;
                }
                else
                {
                    v2[val.first] = 1;
                }
                for (auto &it : v[val.first])
                {
                    if (val.second == 1 and (v2[it.first] || it.second == 1))
                    {
                        continue;
                    }
                    if (val.second == 2 and (v1[it.first] || it.second == 2))
                    {
                        continue;
                    }
                    q.push(it);
                    if (res[it.first] == -1)
                    {
                        res[it.first] = temp;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
