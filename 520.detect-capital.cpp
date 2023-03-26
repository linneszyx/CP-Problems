/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 */

// @lc code=start
class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int n = word.size();
        if (n == 1)
            return true;
        if (isupper(word[0]) && isupper(word[1]))
        {
            for (int i = 2; i < n; i++)
            {
                if (islower(word[i]))
                    return false;
            }
        }
        else
        {
            for (int i = 1; i < n; i++)
            {
                if (isupper(word[i]))
                    return false;
            }
        }
        return true;
    }
};

// @lc code=end
