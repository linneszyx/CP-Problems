/*
 * @lc app=leetcode id=1964 lang=cpp
 *
 * [1964] Find the Longest Valid Obstacle Course at Each Position
 */

// @lc code=start
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> res;
        vector<int> dp;
        for (int i = 0; i < obstacles.size(); ++i) {
            int idx = upper_bound(dp.begin(), dp.end(), obstacles[i]) - dp.begin();
            if (idx == dp.size()) {
                dp.push_back(obstacles[i]);
            } else {
                dp[idx] = obstacles[i];
            }
            res.push_back(idx + 1);
        }
        return res;
    }
};
// @lc code=end

