/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (32.38%)
 * Likes:    23515
 * Dislikes: 2153
 * Total Accepted:    2.5M
 * Total Submissions: 7.6M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an integer array nums, return all the triplets [nums[i], nums[j],
 * nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] +
 * nums[k] == 0.
 * 
 * Notice that the solution set must not contain duplicate triplets.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Explanation: 
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
 * The distinct triplets are [-1,0,1] and [-1,-1,2].
 * Notice that the order of the output and the order of the triplets does not
 * matter.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0,1,1]
 * Output: []
 * Explanation: The only possible triplet does not sum up to 0.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [0,0,0]
 * Output: [[0,0,0]]
 * Explanation: The only possible triplet sums up to 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 3 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n<3){
            return {};
        }
        if(nums[0]>0){
            return {};
        }
        vector<vector<int>> res;
        /* The below code is using the two pointer technique to find the triplets. */
        for (int i = 0; i < n; i++)
        {
            if(nums[i]>0){
                break;
            }
            if(i>0 and nums[i]==nums[i-1]){
                continue;
            }
            int l = i+1;
            int h = n-1;
            int s = 0;
            while(l<h){
                s = nums[i] + nums[l] + nums[h];
                if(s>0) h--;
                else if(s<0) l++;
                else{
                    res.push_back({nums[i],nums[l],nums[h]});
                    int last_occur_l = nums[l];
                    int last_occur_h = nums[h];
                    while (l<h and nums[l]==last_occur_l)
                    {
                        l++;
                    }
                    while (l<h and nums[h]==last_occur_h)
                    {
                        h--;
                    }
                    
                    
                }
            }
        }
        return res;
    }
};
// @lc code=end

