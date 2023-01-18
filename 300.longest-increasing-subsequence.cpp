/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (51.74%)
 * Likes:    16144
 * Dislikes: 296
 * Total Accepted:    1.1M
 * Total Submissions: 2.2M
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * Given an integer array nums, return the length of the longest strictly
 * increasing subsequence.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [10,9,2,5,3,7,101,18]
 * Output: 4
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore
 * the length is 4.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0,1,0,3,2,3]
 * Output: 4
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [7,7,7,7,7,7,7]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 2500
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 * 
 * Follow up: Can you come up with an algorithm that runs in O(n log(n)) time
 * complexity?
 * 
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        int len = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[i],dp[j]+1);
                    len = max(len,dp[i]);
                }
            }
            
        }
        return len;
    }
};
// @lc code=end

