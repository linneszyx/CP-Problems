/*
 * @lc app=leetcode id=2439 lang=cpp
 *
 * [2439] Minimize Maximum of Array
 */

// @lc code=start
class Solution
{
public:
    static bool check(vector<int> &nums, int mid)
    {
        long long have = 0;
        for (int n : nums)
        {
            if (n <= mid)
            {
                have += mid - n;
            }
            else
            {
                if (have < n - mid)
                {
                    return 0;
                }
                else
                {
                    have -= (n - mid);
                }
            }
        }
        return 1;
    }
    int minimizeArrayValue(vector<int> &nums)
    {
        int left = 0;
        int right = *max_element(nums.begin(), nums.end());
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (check(nums, mid))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end
