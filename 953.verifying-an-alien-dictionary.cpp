/*
 * @lc app=leetcode id=953 lang=cpp
 *
 * [953] Verifying an Alien Dictionary
 *
 * https://leetcode.com/problems/verifying-an-alien-dictionary/description/
 *
 * algorithms
 * Easy (52.77%)
 * Likes:    4193
 * Dislikes: 1357
 * Total Accepted:    428.5K
 * Total Submissions: 793.9K
 * Testcase Example:  '["hello","leetcode"]\n"hlabcdefgijkmnopqrstuvwxyz"'
 *
 * In an alien language, surprisingly, they also use English lowercase letters,
 * but possibly in a different order. The order of the alphabet is some
 * permutation of lowercase letters.
 *
 * Given a sequence of words written in the alien language, and the order of
 * the alphabet, return true if and only if the given words are sorted
 * lexicographically in this alien language.
 *
 *
 * Example 1:
 *
 *
 * Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
 * Output: true
 * Explanation: As 'h' comes before 'l' in this language, then the sequence is
 * sorted.
 *
 *
 * Example 2:
 *
 *
 * Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
 * Output: false
 * Explanation: As 'd' comes after 'l' in this language, then words[0] >
 * words[1], hence the sequence is unsorted.
 *
 *
 * Example 3:
 *
 *
 * Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
 * Output: false
 * Explanation: The first three characters "app" match, and the second string
 * is shorter (in size.) According to lexicographical rules "apple" > "app",
 * because 'l' > '∅', where '∅' is defined as the blank character which is less
 * than any other character (More info).
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= words.length <= 100
 * 1 <= words[i].length <= 20
 * order.length == 26
 * All characters in words[i] and order are English lowercase letters.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        unordered_map<char, int> mp;
        for(int i=0;i<order.length();i++) mp[order[i]] = i;
        for (int i = 1; i < words.size(); i++)
        {
           string f = words[i-1];
           string s = words[i];
           int n = min(f.length(),s.length());
           bool fl = false;
           for(int j=0;j<n;j++){
            if(mp[f[j]]<mp[s[j]]) {
                fl = true;
                break;
            }
            else if(mp[f[j]]>mp[s[j]]) return false;
           }
           if(!fl and f.length() > s.length()) return false;
        }
        return true;
    }
};
// @lc code=end
