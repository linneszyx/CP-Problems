/*
 * @lc app=leetcode id=1402 lang=cpp
 *
 * [1402] Reducing Dishes
 */

// @lc code=start
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        int ans = 0;
        int sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            sum += satisfaction[i];
            if (sum > 0) {
                ans += sum;
            } else {
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

