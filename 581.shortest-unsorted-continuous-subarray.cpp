/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 */

// @lc code=start
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        int i = 0, j = n - 1;
        while (i < n and nums[i] == sorted[i]) i++;
        while (j >= 0 and nums[j] == sorted[j]) j--;
        return max(0, j - i + 1);
    }
};
// @lc code=end

