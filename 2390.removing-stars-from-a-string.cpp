/*
 * @lc app=leetcode id=2390 lang=cpp
 *
 * [2390] Removing Stars From a String
 */

// @lc code=start
class Solution {
public:
    string removeStars(string s) {
        string ans = "";
        for (char c : s) {
            if (c == '*') {
                if (ans.size() > 0) {
                    ans.pop_back();
                }
            } else {
                ans.push_back(c);
            }
        }
        return ans;
    }
};
// @lc code=end

