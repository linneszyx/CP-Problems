/*
 * @lc app=leetcode id=1557 lang=cpp
 *
 * [1557] Minimum Number of Vertices to Reach All Nodes
 */

// @lc code=start
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> v;
        vector<int> in(n, 0);
        for (auto& e : edges) {
            in[e[1]]++;
        }
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) {
                v.push_back(i);
            }
        }
        return v;
    }
};
// @lc code=end

