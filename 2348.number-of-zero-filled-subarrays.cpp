/*
 * @lc app=leetcode id=2348 lang=cpp
 *
 * [2348] Number of Zero-Filled Subarrays
 */

// @lc code=start
class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        long long count = 0;
        int n = nums.size();
        for(int i =0,j=0;i<n;++i){
            if(nums[i]!=0) {
                j = i + 1;
            }
            count += i - j + 1;
        }
        return count;
    }
};
// @lc code=end
