/*
 * @lc app=leetcode id=2141 lang=cpp
 *
 * [2141] Maximum Running Time of N Computers
 */

// @lc code=start
#define ll long long
class Solution
{
public:
    long long maxRunTime(int n, vector<int> &batteries)
    {
        // code here
        ll low = 1;
        ll high = accumulate(begin(batteries), end(batteries), 0LL) / n;
        while (low < high)
        {
            ll mid = (low + high + 1) / 2;
            ll sum = 0;
            for (int t : batteries)
            {
                sum += min((ll)t, mid);
            }
            if (mid * n <= sum)
            {
                low = mid;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
};
// @lc code=end
