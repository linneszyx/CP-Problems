/*
 * @lc app=leetcode id=1431 lang=cpp
 *
 * [1431] Kids With the Greatest Number of Candies
 */

// @lc code=start
class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        vector<bool> res;
        int max = 0;
        for (int i = 0; i < candies.size(); i++)
        {
            if (candies[i] > max)
            {
                max = candies[i];
            }
        }
        for (int i = 0; i < candies.size(); i++)
        {
            if (candies[i] + extraCandies >= max)
            {
                res.push_back(true);
            }
            else
            {
                res.push_back(false);
            }
        }
        return res;
    }
};
// @lc code=end
