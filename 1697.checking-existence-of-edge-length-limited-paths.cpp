/*
 * @lc app=leetcode id=1697 lang=cpp
 *
 * [1697] Checking Existence of Edge Length Limited Paths
 */

// @lc code=start
class Solution {
public:
    int find(vector<int>& parent, int x) {
        return parent[x] == x ? x : parent[x] = find(parent, parent[x]);
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<bool> ans(queries.size());
        vector<int> idx(queries.size());
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return queries[i][2] < queries[j][2];
        });
        sort(edgeList.begin(), edgeList.end(), [&](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        int i = 0;
        for (int j : idx) {
            while (i < edgeList.size() && edgeList[i][2] < queries[j][2]) {
                int x = find(parent, edgeList[i][0]);
                int y = find(parent, edgeList[i][1]);
                if (x != y) {
                    parent[x] = y;
                }
                ++i;
            }
            ans[j] = find(parent, queries[j][0]) == find(parent, queries[j][1]);
        }
        return ans;
    }
};
// @lc code=end

