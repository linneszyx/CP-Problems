/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 *
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (49.05%)
 * Likes:    10124
 * Dislikes: 296
 * Total Accepted:    693.5K
 * Total Submissions: 1.4M
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * Given two strings s and p, return an array of all the start indices of p's
 * anagrams in s. You may return the answer in any order.
 *
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "cbaebabacd", p = "abc"
 * Output: [0,6]
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of "abc".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "abab", p = "ab"
 * Output: [0,1,2]
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length, p.length <= 3 * 10^4
 * s and p consist of lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    bool isanagram(int freq_s[], int freq_p[])
    {
        for (int i = 0; i < 26; i++)
        {
            if (freq_s[i] != freq_p[i])
                return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ans;
        int n = s.size();
        int m = p.size();
        int fs[26] = {0};
        int ps[26] = {0};
        for (int i = 0; i < m; i++)
        {
            ps[p[i] - 'a']++;
        }
        for (int i = 0; i < n; i++)
        {
            if (i < m - 1)
            {
                fs[s[i] - 'a']++;
            }
            else if (i == m - 1)
            {
                fs[s[i] - 'a']++;
                if (isanagram(fs, ps))
                {
                    ans.push_back(i - m + 1);
                }
            }
            else
            {
                fs[s[i - m] - 'a']--;
                fs[s[i] - 'a']++;
                if (isanagram(fs, ps))
                {
                    ans.push_back(i - m + 1);
                }
            }
        }

        return ans;
    }
};
// @lc code=end
