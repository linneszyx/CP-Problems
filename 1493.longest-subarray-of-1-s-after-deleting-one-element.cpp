/*
 * @lc app=leetcode id=1493 lang=cpp
 *
 * [1493] Longest Subarray of 1's After Deleting One Element
 */

// @lc code=start
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        int ans = 0;
        int count = 0;
        while(right < n){
            if(nums[right] == 0){
                count++;
            }
            while(count > 1){
                if(nums[left] == 0){
                    count--;
                }
                left++;
            }
            ans = max(ans, right - left);
            right++;
        }
        return ans;
    }
};
// @lc code=end

