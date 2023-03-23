/*
 * @lc app=leetcode id=1319 lang=cpp
 *
 * [1319] Number of Operations to Make Network Connected
 */

// @lc code=start
class Solution {
public:
    int find(vector<int>& parent, int i) {
        if (parent[i] != i) {
            parent[i] = find(parent, parent[i]);
        }
        return parent[i];
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        int extra = 0;
        for (auto& c : connections) {
            int x = find(parent, c[0]);
            int y = find(parent, c[1]);
            if (x == y) {
                extra++;
            } else {
                parent[x] = y;
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) {
                count++;
            }
        }
        return extra >= count - 1 ? count - 1 : -1;
    }
};
// @lc code=end

