/*
 * @lc app=leetcode id=87 lang=cpp
 *
 * [87] Scramble String
 */

// @lc code=start
class Solution
{
public:
    unordered_map<string, bool> mp;
    bool isScramble(string s1, string s2)
    {
        int n = s1.size();
        if (s2.size() != n)
            return false;
        if (s1 == s2)
            return true;
        if (n == 1)
            return false;
        string key = s1 + " " + s2;
        if (mp.find(key) != mp.end())
            return mp[key];
        for (int i = 1; i < n; i++)
        {
            bool withoutSwap = (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                                isScramble(s1.substr(i), s2.substr(i)));
            if (withoutSwap)
                return true;
            bool withSwap = (isScramble(s1.substr(0, i), s2.substr(n - i)) &&
                             isScramble(s1.substr(i), s2.substr(0, n - i)));
            if (withSwap)
                return true;
        }
        return mp[key] = false;
    }
};
// @lc code=end
