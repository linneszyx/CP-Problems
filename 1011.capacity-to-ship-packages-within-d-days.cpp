/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

// @lc code=start
class Solution
{
public:
 /**
  * We use binary search to find the minimum possible capacity of the ship
  * 
  * @param weights [1,2,3,4,5,6,7,8,9,10]
  * @param D number of days
  * 
  * @return The minimum capacity of the ship that will result in D or fewer days of travel.
  */
    int shipWithinDays(vector<int> &weights, int days)
    {
        int left = 0, right = 0;
        for (auto w : weights)
        {
            left = max(left, w);
            right += w;
        }
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            int need = 1, cur = 0;
            for (auto w : weights)
            {
                if (cur + w > mid)
                {
                    need++;
                    cur = 0;
                }
                cur += w;
            }
            if (need > days)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};
// @lc code=end
