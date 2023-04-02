/*
 * @lc app=leetcode id=2300 lang=cpp
 *
 * [2300] Successful Pairs of Spells and Potions
 */

// @lc code=start
class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        int n = spells.size();
        int m = potions.size();
        vector<int> v(n, 0);
        sort(potions.begin(), potions.end());
        for (int i = 0; i < n; i++)
        {
            int spell = spells[i];
            int l = 0;
            int r = m - 1;
            while (l <= r)
            {
                int mid = l + (r - l) / 2;
                long long sum = (long long)spell * (long long)potions[mid];
                if (sum>=success)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            v[i] = m-l;
        }
        return v;
    }
};
// @lc code=end
