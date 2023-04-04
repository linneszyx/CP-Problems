/*
 * @lc app=leetcode id=2405 lang=cpp
 *
 * [2405] Optimal Partition of String
 */

// @lc code=start
class Solution
{
public:
    int partitionString(string s)
    {
        int index = 0;
        int count = 0;
        unordered_map<char, bool> map;
        while (index < s.length())
        {
            if (map.find(s[index]) != map.end())
            {
                count++;
                map.clear();
            }
            map[s[index]] = true;
            index++;
        }
        return count+1;
    }
};
// @lc code=end
