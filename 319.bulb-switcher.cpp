/*
 * @lc app=leetcode id=319 lang=cpp
 *
 * [319] Bulb Switcher
 */

// @lc code=start
class Solution {
public:
    int bulbSwitch(int n) {
        int count = 0;
        for (int i = 1; i * i <= n; ++i) {
            ++count;
        }
        return count;
    }
};
// @lc code=end

