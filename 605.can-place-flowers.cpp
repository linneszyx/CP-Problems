/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 */

// @lc code=start
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int size = flowerbed.size();
        int counting = 0;
        for (int i = 0; i < size; i++)
        {
            if (flowerbed[i] == 0)
            {
                if (i == 0)
                {
                    if (size == 1)
                    {
                        counting++;
                        break;
                    }
                    if (flowerbed[i + 1] == 0)
                    {
                        counting++;
                        flowerbed[i] = 1;
                    }
                }
                else if (i == size - 1)
                {
                    if (flowerbed[i - 1] == 0)
                    {
                        counting++;
                        flowerbed[i] = 1;
                    }
                }
                else
                {
                    if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
                    {
                        counting++;
                        flowerbed[i] = 1;
                    }
                }
            }
        }
        return counting >= n;
    }
};
// @lc code=end
