/*
 * @lc app=leetcode id=1480 lang=cpp
 *
 * [1480] Running Sum of 1d Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = 0; j <= i; j++)
            {
                sum += nums[j];
            }
            v.push_back(sum);
        }
        return v;
    }
};
// @lc code=end
