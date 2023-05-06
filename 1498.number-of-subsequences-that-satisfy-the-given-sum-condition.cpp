/*
 * @lc app=leetcode id=1498 lang=cpp
 *
 * [1498] Number of Subsequences That Satisfy the Given Sum Condition
 */

// @lc code=start
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int count = 0;
        int mod = 1e9 + 7;
        sort(nums.begin(), nums.end());
        vector<int> pow(n, 1);
        for (int i = 1; i < n; ++i) {
            pow[i] = (pow[i - 1] * 2) % mod;
        }
        int left = 0, right = n - 1;
        while (left <= right) {
            if (nums[left] + nums[right] > target) {
                --right;
            } else {
                count = (count + pow[right - left]) % mod;
                ++left;
            }
        }
        return count;
    }
};
// @lc code=end

