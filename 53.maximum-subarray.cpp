/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Medium (50.11%)
 * Likes:    27848
 * Dislikes: 1237
 * Total Accepted:    3M
 * Total Submissions: 6M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the subarray with the largest sum, and
 * return its sum.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: The subarray [4,-1,2,1] has the largest sum 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1]
 * Output: 1
 * Explanation: The subarray [1] has the largest sum 1.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [5,4,-1,7,8]
 * Output: 23
 * Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 * 
 * Follow up: If you have figured out the O(n) solution, try coding another
 * solution using the divide and conquer approach, which is more subtle.
 * 
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        bool flag =true;
        int rr = INT_MIN;
        for(auto x : nums){
            if(x>0) flag = false;
            if(x>rr) rr = x;
        }
        if(flag) return rr;
        int maxSum = 0;
        int fa = 0;
        int temp = 0;
        int n = nums.size();
        for(int i =0;i<n;i++){
            temp = maxSum + nums[i];
            if(temp<nums[i]) maxSum = nums[i];
            else maxSum = temp; 
            fa = max(fa,maxSum);
        }
        return fa;
    }
};
// @lc code=end

