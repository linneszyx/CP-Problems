/*
 * @lc app=leetcode id=1376 lang=cpp
 *
 * [1376] Time Needed to Inform All Employees
 */

// @lc code=start
class Solution {
public:
    int dfs(int i, vector<int>& manager, vector<int>& informTime) {
        if (manager[i] == -1) return 0;
        return informTime[manager[i]] + dfs(manager[i], manager, informTime);
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int s1 = 0, s2 = 0;
        for (int i = 0; i < n; ++i) {
            if (informTime[i] == 0) {
                s1 = max(s1, dfs(i, manager, informTime));
            }
        }
        return s1;
    }
};
// @lc code=end

