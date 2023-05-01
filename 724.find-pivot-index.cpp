/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */

// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return -1;
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        for (int i = 1; i < n; ++i) {
            left[i] = left[i-1] + nums[i-1];
        }
        for (int i = n-2; i >= 0; --i) {
            right[i] = right[i+1] + nums[i+1];
        }
        for (int i = 0; i < n; ++i) {
            if (left[i] == right[i]) return i;
        }
        return -1;
    }
};
// @lc code=end

