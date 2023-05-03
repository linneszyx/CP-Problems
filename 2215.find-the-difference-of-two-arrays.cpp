/*
 * @lc app=leetcode id=2215 lang=cpp
 *
 * [2215] Find the Difference of Two Arrays
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> res = {{},{}};
        set<int> s1;
        set<int> s2;
        for (int i = 0; i < nums1.size(); ++i) {
            s1.insert(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); ++i) {
            s2.insert(nums2[i]);
        }
        for (auto it = s1.begin(); it != s1.end(); ++it) {
            if (s2.find(*it) == s2.end()) {
                res[0].push_back(*it);
            }
        }
        for (auto it = s2.begin(); it != s2.end(); ++it) {
            if (s1.find(*it) == s1.end()) {
                res[1].push_back(*it);
            }
        }
        return res;
    }
};
// @lc code=end

